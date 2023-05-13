#pragma once

#include<bits/stdc++.h>
#include<Windows.h>

#define userFilename "user.txt"
#define accountFilename "account.txt"

using namespace std;

class account {
public:
	string& getTime();
	string& getUse();
	double& getMoney();
	account(string a, string b ="", double c=0);
	bool operator==(const account& t)const {
		if (t.time == time)  return 1;
		else return 0;
	}
	friend ostream& operator<<(ostream& cout, account& account);
private:
	string time;
	string use;
	double money;
};
ostream& operator<<(ostream& cout, account& account);