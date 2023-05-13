#pragma once

#include "account.h"

class person {
public:
	person(string name);
	friend ostream& operator<<(ostream& cout, person& person);
	bool operator==(const person& t)const {
		if (t.name == name)  return 1;
		else return 0;
	}
	void add_Account();
	void delete_Account();
	string& getName();
	bool exit_System();
	bool initSystem(ifstream& ifs);
private:
	vector<account>account_List;
	string name;
};
ostream& operator<<(ostream& cout, person& person);