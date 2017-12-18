#include <iostream>
using namespace std;
typedef void (*VFUN) (void*); // 虚函数
typedef VFUN* VPTR; // 虚指针
class A {
public:
	A (int data) : m_data (data) {}
	virtual void foo (void) {
		cout << "A::foo() : " << m_data << endl;
	}
	virtual void bar (void) {
		cout << "A::bar() : " << m_data << endl;
	}
protected:
	int m_data;
};
class B : public A {
public:
	B (int data) : A (data) {}
	void foo (void) {
		cout << "B::foo() : " << m_data << endl;
	}
};
int main (void) {
	/*
	B b (100);
	A& a = b;
	a.foo (); // B::foo()
	a.bar (); // A::bar()
	cout << sizeof (A) << endl;
	*/
	A a (100);
	VPTR vptr = *(VPTR*)&a;
	cout << vptr << "->[" << (void*)vptr[0] << ','
		<< (void*)vptr[1] << ']' << endl;
	vptr[0] (&a); // A::foo
	vptr[1] (&a); // A::bar
	B b (200);
	vptr = *(VPTR*)&b;
	cout << vptr << "->[" << (void*)vptr[0] << ','
		<< (void*)vptr[1] << ']' << endl;
	vptr[0] (&b); // B::foo
	vptr[1] (&b); // A::bar
	B b2 (300);
	vptr = *(VPTR*)&b;
	cout << vptr << "->[" << (void*)vptr[0] << ','
		<< (void*)vptr[1] << ']' << endl;
	vptr[0] (&b2); // B::foo
	vptr[1] (&b2); // A::bar
	return 0;
}
