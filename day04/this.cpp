#include <iostream>
using namespace std;
class A {
public:
	A (int data = 0) : m_data (data) {
		cout << "构造函数：" << this << endl;
	}
	void print (void) {
		cout << "成员函数：" << this << endl;
		cout << this->m_data << endl;
	}
	int m_data;
};
/*
void _ZN1A5printEv (A* this) {
	cout << this->m_data << endl;
}
*/
class B {
public:
	B (int i) {
		this->i = i;
	}
	void show (void) {
		void print (B const* p);
		print (this);
	}
	B& inc (void) {
		++i;
		return *this; // 返回自引用
	}
	void killMe (void) {
		delete this; // 对象自毁
	}
	int i;
};
void print (B const* p) {
	cout << p->i << endl;
}
int main (void) {
	A a1 (123), a2 (456);
	cout << "a1的地址：" << &a1 << endl;
	cout << "a2的地址：" << &a2 << endl;
	cout << a1.m_data << endl; // 123
	cout << a2.m_data << endl; // 456
	a1.print (); // 123
//	_ZN1A5printEv (&a1);
	a2.print (); // 456
//	_ZN1A5printEv (&a2);
	B b (1000);
	cout << b.i << endl;
	print (&b);
	b.show ();
	b.inc ().inc ().inc ();
	cout << b.i << endl; // 1003
	B* p = new B (2000);
	cout << p->i << endl;
	p->killMe ();
	return 0;
}
