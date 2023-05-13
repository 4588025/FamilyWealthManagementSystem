#pragma once


#include "person.h"

class Management_System {
public:
	void show();
	int check(string);
	void no_Enter();
	void help_List();
	void exit_System();
	void cat();
	void cat_User();
	void add_User();
	void delete_User();
	void add_Account();
	void delete_Account();
	void initSystem();
private:
	vector<person>user;
	
};