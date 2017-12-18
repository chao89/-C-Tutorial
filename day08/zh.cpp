#include <iostream>
using namespace std;
class Base {
public:
	virtual void foo (void) const {
		cout << "Base::foo(void) const" << endl;
	}
};
class Derived : public Base {
public:
	void foo (void) const {
		cout << "Derived::foo(void) const" << endl;
	}
};
int main (void) {
	Base* p = new Derived;
	p->foo ();
	return 0;
}
