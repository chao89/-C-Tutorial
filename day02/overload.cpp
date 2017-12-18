#include <iostream>
using namespace std;
void foo (void) {
	cout << 1 << endl;
}
void foo (int n) {
	cout << 2 << endl;
}
void foo (int* n) {
	cout << 3 << endl;
}
char const* foo (int n, double d) {
	cout << 4 << endl;
	return NULL;
}
char const* foo (double d, int n) {
	cout << 5 << endl;
	return NULL;
}
/*
int foo (void) {
	cout << 6 << endl;
	return 0;
}*/
/*
void bar (char c) {
	cout << 'A' << endl;
}*/
void bar (short h) {
	cout << 'B' << endl;
}
void bar (int i) {
	cout << 'C' << endl;
}
void hum (int i) {
	cout << 'X' << endl;
}
void hum (long long l) {
	cout << 'Y' << endl;
}
void fun (char* p) {
	cout << 'a' << endl;
}
void fun (char const* p) {
	cout << 'b' << endl;
}
int main (void) {
	foo ();
	foo (100);
	int* p = NULL;
	foo (p);
	foo (100, 100.);
	foo (100., 100);
	bar ('X');
	short h;
	hum (h);
	fun ("abc");
	char s[] = "abc";
	fun (s);
	return 0;
}
