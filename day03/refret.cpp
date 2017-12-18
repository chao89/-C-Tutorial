#include <iostream>
using namespace std;
int g_global = 0;
int foo (void) {
	return g_global;
}
int& bar (void) {
	return g_global;
}
int& hum (void) {
//	int local = 123;
//	static int local = 123;
//	return local;
	return *new int (123);
}
int& fun (void) {
	int other = 456;
	return other;
}
int& dum (int& arg) {
	return arg;
}
struct Student {
	char name[64];
	int age;
	char info[1024];
};
Student const& read (void) {
	static Student s = {"张飞", 22,
		"达内1505班学员"};
	return s;
}
int main (void) {
	cout << g_global << endl; // 0
//	foo () = 100;
	bar () = 100; // g_global = 100;
	cout << g_global << endl; // 100
	int& ret = hum ();
	fun ();
	cout << ret << endl; // 123
	delete &ret;
	int x = 123;
	int& y = dum (x);
	cout << y << endl; // 123
	Student const& s = read ();
	cout << s.name << ',' << s.age/*++*/ << ','
		<< s.info << endl;
	cout << read ().age << endl;
	return 0;
}
