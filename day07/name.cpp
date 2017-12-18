#include <iostream>
using namespace std;
class A {
public:
	void foo (void) {
		cout << "A::foo(void)" << endl;
	}
	int xyz;
};
class B {
public:
	void foo (int arg) {
		cout << "B::foo(int)" << endl;
	}
	typedef int xyz;
};
class C : public A, public B {
public:
	using A::foo;
	using B::foo;
};
int main (void) {
	C c;
	/*
	c.A::foo ();
	c.B::foo (100);
	*/
	c.foo ();
	c.foo (100);
	c.A::xyz = 100;
	C::B::xyz i = 100;
	return 0;
}
