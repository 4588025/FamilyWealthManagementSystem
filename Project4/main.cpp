#include "Management_System.h"

int main() {
	Management_System Management_System;
	Management_System.initSystem();
	Management_System.show();
	string choice = "";
	while (1) {
		cout << "\033[33m";
		getline(cin, choice);
		cout << "\033[0m";
		switch (Management_System.check(choice)){
			case 0:
				Management_System.no_Enter();
				break;
			case 1:
				Management_System.help_List();
				break;
			case 2:
				Management_System.cat();
				break;
			case 3:
				Management_System.cat_User();
				break;
			case 4:
				Management_System.add_User();
				break; 
			case 5:
				Management_System.delete_User();
				break;
			case 6:
				Management_System.add_Account();
				break;
			case 7:
				Management_System.delete_Account();
				break;
			case 8:
				Management_System.exit_System();
				return 0;
			default:
				break;
		}
	}
	return 0;
}