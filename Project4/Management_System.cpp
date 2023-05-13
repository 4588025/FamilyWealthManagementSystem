#include "Management_System.h"



void Management_System::show() {
	cout << "Welcome to the \033[31mFamily Wealth Management System\033[0m." << endl;
	Sleep(200);
	cout << endl << "loading..." << endl;
	Sleep(500);
	cout << "ready." << endl;
	Sleep(200);
	cout << endl << "You can enter \033[34m'/help'\033[0m to get the the menu." << endl;//\033[31m   \033
}

int Management_System::check(string choice) {
	if (choice == "/help"){
		return 1;
	}
	else if (choice == "/cat") {
		return 2;
	}
	else if (choice == "/cat user") {
		return 3;
	}
	else if (choice == "/add user") {
		return 4;
	}
	else if (choice == "/delete user") {
		return 5;
	}
	else if (choice == "/add account") {
		return 6;
	}
	else if (choice == "/delete account") {
		return 7;
	}
	else if (choice == "/exit") {
		return 8;
	}
	else {
		return 0;
	}
}
void Management_System::no_Enter() {
	cout<< "\033[32m" << "~author:nbufe000~" << "\033[0m";
}

void Management_System::help_List() {
	cout << "Use `" << "\033[34m" << "/cat" << "\033[0m" << "' to displays information about all users." << endl;
	cout << "Use `" << "\033[34m" << "/cat user" << "\033[0m" << "' to displays information about the specified user." << endl;
	cout << "Use `" << "\033[34m" << "/add user" << "\033[0m" << "' to displays information about all users." << endl;
	cout << "Use `" << "\033[34m" << "/delete user" << "\033[0m" << "' to delete user information." << endl;
	cout << "Use `" << "\033[34m" << "/add account" << "\033[0m" << "' to add the specified user account information." << endl;
	cout << "Use `" << "\033[34m" << "/delete account" << "\033[0m" << "' to delete the specified user account information." << endl;
	cout << "Use `" << "\033[34m" << "/exit" << "\033[0m" << "' to log out the family wealth management system." << endl;
}


void Management_System::cat() {
	for (int i = 0; i < user.size(); i++) {
		cout << "       ("<<i+1<<")" << endl;
		cout << user[i];
	}
	if (user.size() == 0) {
		cout << "The system does not have a user, please add a user." << endl;
	}
}

void Management_System::cat_User() {
	string name;
	cout << "Please enter the name of the user you want to query:";
	cout << "\033[33m";
	getline(cin, name);
	cout << "\033[0m";
	auto pos = find(user.begin(), user.end(), person(name));
	if (pos == user.end()) {
		cout << "This user was not found" << endl;
	}
	else {
		cout << *pos;
	}
}

void Management_System::add_User() {
	string name;
	cout << "Please enter the name of the user you want to add:";
	cout << "\033[33m";
	getline(cin, name);
	cout << "\033[0m";
	user.push_back(person(name));
	Sleep(100);
	cout << "User added successfully!" << endl;
}


void Management_System::delete_User() {
	string name;
	cout << "Please enter the name of the user you want to delete:";
	cout << "\033[33m";
	getline(cin, name);
	cout << "\033[0m";
	auto pos = find(user.begin(), user.end(), person(name));
	if (pos == user.end()) {
		cout << "This user was not found" << endl;
	}
	else {
		user.erase(pos);
	}
	cout << "User deleted successfully!" << endl;
}

void Management_System::add_Account() {
	string name;
	cout << "Please enter the name of the user you want to query:";
	cout << "\033[33m";
	getline(cin, name);
	cout << "\033[0m";
	auto pos = find(user.begin(), user.end(), person(name));
	if (pos == user.end()) {
		cout << "This user was not found" << endl;
	}
	else {
		pos->person::add_Account();
		cout << "account added successfully!" << endl;
	}
}

void Management_System::delete_Account() {
	string name;
	cout << "Please enter the name of the user you want to query:";
	cout << "\033[33m";
	getline(cin, name);
	cout << "\033[0m";
	auto pos = find(user.begin(), user.end(), person(name));
	if (pos == user.end()) {
		cout << "This user was not found" << endl;
	}
	else {
		pos->person::delete_Account();
		cout << "account deleted successfully!" << endl;
	}
}

void Management_System::exit_System() {
	ofstream ofs;
	ofs.open(accountFilename, ios::trunc);
	ofs.close();
	ofs.open(userFilename, ios::out | ios::trunc);
	if (!ofs.is_open()) {
		cout << "Data storage failure!" << endl;
		return;
	}
	for (auto i : user) {
		ofs << i.getName() << endl;
		if (!i.person::exit_System()) {
			return;
		}
	}
	ofs.close();
	
	cout << "Data saved successfully!" << endl;
}

void Management_System::initSystem() {
	ifstream ifs;
	ifstream ifsAccount;
	ifsAccount.open(accountFilename, ios::in);
	ifs.open(userFilename, ios::in);
	if (!ifs.is_open()) {
		cout << "Data storage failure!" << endl;
		return;
	}
	string name;
	while(ifs >>name){
		user.push_back(person(name));
		auto pos = user.end()-1;
		if (!pos->person::initSystem(ifsAccount)) {
			return;
		}
	}
	ifs.close();
	ifsAccount.close();
	cout << "Data read successfully!" << endl;
}