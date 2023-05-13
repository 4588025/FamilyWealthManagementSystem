#include "account.h"

string& account::getTime() {
	return time;
}
string& account::getUse() {
	return use;
}
double& account::getMoney() {
	return money;
}
account::account(string a, string b , double c) :time(a), use(b), money(c) {}

ostream& operator<<(ostream& cout, account& account) {
	cout << "\ttime: " << account.time << endl;
	cout << "\tuse: " << account.use << endl;
	cout << "\tmoney: " << account.money << endl;
	return cout;
}