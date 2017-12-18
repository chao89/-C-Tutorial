#include <iostream>
using namespace std;
class A {
public:
	void foo (void) {
		cout << "foo(void) " << this << endl;
		bar (400);
		foo (500);
		cout << s_var << endl;
		cout << m_var << endl;
	}
	void foo (int arg) {
		cout << "foo(int) " << this << endl;
	}
	static void bar (void) /*const*/ {
		cout << "A::bar(void)" /*<< this*/ << endl;
		bar (400);
//		foo (500);
		cout << s_var << endl;
//		cout << m_var << endl;
	}
	static void bar (int arg) {
		cout << "A::bar(int)" /*<< this*/ << endl;
	}
	int m_var;
	static int s_var;
};
int A::s_var = 100;
int main (void) {
	cout << A::s_var << endl;
	A::bar ();
	A::bar (200);
	A a, *p = &a;
	a.foo ();
	p->foo (300);
	a.bar ();
	p->bar (600);
	return 0;
}
