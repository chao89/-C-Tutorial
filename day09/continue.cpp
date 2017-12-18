#include <iostream>
using namespace std;
void foo (void) {
	throw 1;
}
void bar (void) {
	try {
		foo ();
	}
	catch (int& ex) {
		cout << "bar: " << ex++ << endl;
		throw;
	}
}
void hum (void) {
	try {
		bar ();
	}
	catch (int& ex) {
		cout << "hum: " << ex++ << endl;
		throw;
	}
}
int main (void) {
	try {
		hum ();
	}
	catch (int& ex) {
		cout << "main: " << ex << endl; // 3
		return -1;
	}
	return 0;
}
