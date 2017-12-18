#include <iostream>
using namespace std;
class A {
public:
	void foo (void) {
		cout << "A::foo(void)" << endl;
	}
	int xyz;
};
class B : public A {
public:
	void foo (int i) {
		cout << "B::foo(int)" << endl;
	}
	void bar (void) {
		/*A::*/foo ();
		foo (20);
	}
	using A::foo;
	typedef int xyz;
};
int main (void) {
	B b;
	b./*A::*/foo ();
	b.foo (10);
	b.bar ();
//	b.xyz = 100;
	B::xyz i = 100;
	b.A::xyz = 200;
	return 0;
}
