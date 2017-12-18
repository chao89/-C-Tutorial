#include <iostream>
using namespace std;
class A {
public:
	A (int data) : m_data (data) {
		cout << "A构造：" << this << endl;
	}
	void set (int data) {
		cout << "A::set() " << &m_data << endl;
		m_data = data;
	}
	int get (void) const {
		cout << "A::get() " << &m_data << endl;
		return m_data;
	}
private:
	int m_data;
};
class B : public A {
public:
	B (int data) : A (data) {
		cout << "B构造：" << this << endl;
	}
};
class C : public A {
public:
	C (int data) : A (data) {
		cout << "C构造：" << this << endl;
	}
};
class D : public B, public C {
public:
	D (int data) : B (data), C (data) {
		cout << "D构造：" << this << endl;
	}
};
//   A
//  / \
// B   C
//  \ /
//   D
int main (void) {
	D d (1000);
	d.B::set (2000);
	cout << d.C::get () << endl;
	cout << sizeof (A) << endl; // 4
	cout << sizeof (B) << endl; // 4
	cout << sizeof (C) << endl; // 4
	cout << sizeof (D) << endl; // 8
	B b (3000);
	return 0;
}
