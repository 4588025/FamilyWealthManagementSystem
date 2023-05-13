
#include "person.h"

person::person(string name) :name(name){}

ostream& operator<<(ostream& cout, person& person) {
	cout << "\tname£º" << person.name << endl;
	for (int i = 0; i < person.account_List.size(); i++) {
		cout << person.account_List[i] << endl;
	}
	if (person.account_List.size() == 0) {
		cout << "\tNo record, please add a record." << endl;
	}
	return cout;
}

void person::add_Account() {
	string time, use;
	double money;
	cout << "Please enter the time:";
	cout << "\033[33m";
	getline(cin, time);
	cout << "\033[0m";
	cout << "Please enter the use:";
	cout << "\033[33m";
	getline(cin, use);
	cout << "\033[0m";
	cout << "Please enter the money:";
	cout << "\033[33m";
	cin >> money;
	cout << "\033[0m";
	getchar();
	account_List.push_back(account(time, use, money));
}

void person::delete_Account() {
	string time;
	cout << "Please enter the billing time:";
	cout << "\033[33m";
	getline(cin, time);
	cout << "\033[0m";
	auto pos = find(account_List.begin(), account_List.end(), account(time));
	if (pos == account_List.end()) {
		cout << "This account was not found" << endl;
	}
	else {
		account_List.erase(pos);
	}
}

string& person::getName() {
	return name;
}

bool person::exit_System() {
	ofstream ofs;
	ofs.open(accountFilename, ios::app);
	if (!ofs.is_open()) {
		cout << "Data storage failure!" << endl;
		return 0;
	}
	ofs << account_List.size() << endl;
	for (auto i : account_List) {
		ofs << i.getTime() <<" " << i.getUse() <<" " << i.getMoney() << endl;
	}
	ofs.close();
	return 1;
}

bool person::initSystem(ifstream& ifsAccount) {
	if (!ifsAccount.is_open()) {
		cout << "Data storage failure!" << endl;
		return 0;
	}
	int length = 0;
	ifsAccount >> length ;
	while (length--) {
		string time, use; double money;
		ifsAccount >> time >> use >> money;
		account_List.push_back(account(time, use, money));
	}
	return 1;
}