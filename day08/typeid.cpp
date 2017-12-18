#include <iostream>
#include <typeinfo>
#include <cstring>
using namespace std;
class Student {};
class A { virtual void foo (void) {} };
class B : public A {};
class C : public A {};
void bar (A* a) {
//	if (! strcmp (typeid (*a).name (), "1A"))
	if (typeid (*a) == typeid (A))
		cout << "这是一个A对象！" << endl;
	else
//	if (! strcmp (typeid (*a).name (), "1B"))
	if (typeid (*a) == typeid (B))
		cout << "这是一个B对象！" << endl;
	else
//	if (! strcmp (typeid (*a).name (), "1C"))
	if (typeid (*a) == typeid (C))
		cout << "这是一个C对象！" << endl;
}
int main (void) {
	char c;
	unsigned char uc;
	short h;
	unsigned short uh;
	int i;
	unsigned int ui;
	long l;
	unsigned long ul;
	long long ll;
	unsigned long long ull;
	float f;
	double d;
	long double ld;
	cout << typeid (c).name () << endl;
	cout << typeid (uc).name () << endl;
	cout << typeid (h).name () << endl;
	cout << typeid (uh).name () << endl;
	cout << typeid (i).name () << endl;
	cout << typeid (ui).name () << endl;
	cout << typeid (l).name () << endl;
	cout << typeid (ul).name () << endl;
	cout << typeid (ll).name () << endl;
	cout << typeid (ull).name () << endl;
	cout << typeid (f).name () << endl;
	cout << typeid (d).name () << endl;
	cout << typeid (ld).name () << endl;
	int const ci = 0;
	cout << typeid (ci).name () << endl;
	double***** pd;
	cout << typeid (pd).name () << endl;
	float const* pf1; // 指针目标只读
	float *const pf2 = 0; // 指针本身只读
	float const* const pf3 = 0; // 指针的目标和指针
	                            // 本身都只读
	cout << typeid (pf1).name () << ' '
		<< typeid (pf2).name () << ' '
		<< typeid (pf3).name () << endl;
	int* pa[5]; // 指针数组
	int (*pb)[5]; // 数组指针
	cout << typeid (pa).name () << ' '
		<< typeid (pb).name () << endl;
	char* (*fun) (int*, char*, double);
	cout << typeid (fun).name () << endl;
	cout << typeid (6 > 5.0).name () << endl;
	cout << typeid (1 > 0 ? 5 : 6.0).name ()
		<< endl;
	Student s;
	cout << typeid (s).name () << endl;
	B b;
	A* a = &b;
	cout << typeid (*a).name () << endl;
	A& r = b;
	cout << typeid (r).name () << endl;
	bar (new A);
	bar (new B);
	bar (new C);
	return 0;
}
