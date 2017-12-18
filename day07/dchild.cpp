#include <iostream>
using namespace std;
class A {
public:
	A (void) {
		cout << "A构造：" << this << endl;
	}
	~A (void) {
		cout << "A析构：" << this << endl;
	}
private:
	int m_data;
};
class B {
public:
	B (void) {
		cout << "B构造：" << this << endl;
	}
	~B (void) {
		cout << "B析构：" << this << endl;
	}
private:
	int m_data;
};
class C {
public:
	C (void) {
		cout << "C构造：" << this << endl;
	}
	~C (void) {
		cout << "C析构：" << this << endl;
	}
private:
	int m_data;
};
class D {
public:
	D (void) {
		cout << "D构造：" << this << endl;
	}
	~D (void) {
		cout << "D析构：" << this << endl;
	}
private:
	int m_data;
};
class E : public A, public B {
public:
	E (void) {
		cout << "E构造：" << this << endl;
	}
	~E (void) {
		cout << "E析构：" << this << endl;
	}
private:
	C m_c;
	D m_d;
	int m_data;
};
int main (void) {
	/*
	E e;
	cout << sizeof (e) << endl;
	*/
	B* pb = new E;
	cout << pb << endl;
//	delete pb; // 内存泄漏的风险
	E* pe = static_cast<E*> (pb);
	cout << pe << endl;
	delete pe;
	return 0;
}
