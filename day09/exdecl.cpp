#include <iostream>
using namespace std;
//void foo (int arg) throw (int, double, string) {
//void foo (int arg) { // 可以抛出任何异常
void foo (int arg) throw () { // 不会抛出任何异常
	if (arg == 1)
		throw 123;
	if (arg == 2)
		throw 4.56;
	if (arg == 3)
		throw string ("abc");
	if (arg == 4)
		throw "xyz"; // char const*
}
void bar (void) throw (int, string);
class A {
public:
	virtual void foo (void) throw (int, string) {
	}
};
class B : public A {
public:
//	void foo (void) {} // 无效覆盖
//	void foo (void) throw () {} // OK
//	void foo (void) throw (string) {} // OK
	void foo (void) throw (string, int) {} // OK
//	void foo (void) throw (double) {} // 无效覆盖
};
class C {
public:
	virtual ~C (void) throw () {}
};
class D : public C {
public:
	~D (void) throw () {}
//	char m_name[1024];
	string m_name;
};
int main (void) {
	try {
		foo (1); // -> int
//		foo (2); // -> double
//		foo (3); // -> string
//		foo (4); // -> char const*
	}
	catch (int& ex) {
		cout << ex << endl;
	}
	catch (double& ex) {
		cout << ex << endl;
	}
	catch (string& ex) {
		cout << ex << endl;
	}
	catch (char const*& ex) {
		cout << ex << endl;
	}
	catch (...) {
		cout << "其它" << endl;
	}
	return 0;
}
void bar (void) throw (string, int) {}
