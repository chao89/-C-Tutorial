#include <iostream>
using namespace std;
class A {
public:
	A (void) {
		cout << "A构造" << endl;
	}
	~A (void) {
		cout << "A析构" << endl;
	}
};
class B {
	A m_a;
};
class X {
public:
	X (void) {
		cout << "X构造" << endl;
	}
	~X (void) {
		cout << "X析构" << endl;
	}
private:
	A m_a;
};
int main (void) {
//	B b;
	X x;
	return 0;
}
