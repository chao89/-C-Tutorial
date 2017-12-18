#include <iostream>
using namespace std;
class X {
public:
	virtual void hum (void) {
		cout << 'X' << endl;
	}
};
class Y : public X {
public:
	void hum (void) {
		cout << 'Y' << endl;
	}
};
class A {
public:
	A (void) : m_x (new Y) {
		foo (); // 构造函数中调用虚函数没有多态性
		m_x->hum (); // 多态性
	}
	~A (void) {
		foo (); // 析构函数中调用虚函数没有多态性
		m_x->hum (); // 多态性
		delete m_x;
	}
	virtual void foo (void) {
		cout << 'A' << endl;
	}
	void bar (void) {
		this->foo (); // this是一个指向B对象的A*
	}
private:
	X* m_x;
};
class B : public A {
public:
	void foo (void) {
		cout << 'B' << endl;
	}
};
int main (void) {
	B b;
	b.bar ();
	return 0;
}
