#include <iostream>
using namespace std;
class A {
public:
	A (void) : m_x (1234) {
		cout << "A缺省构造" << endl;
	}
	A (int x) : m_x (x) {}
	A (A const& that) : m_x (that.m_x) {
		cout << "A拷贝构造" << endl;
	}
	A& operator= (A const rhs) {
		cout << "A拷贝赋值" << endl;
		m_x = rhs.m_x;
		return *this;
	}
	int m_x;
};
class B : public A {
public:
	B (int x, int y) : A (x), m_y (y) {}
	int m_y;
};
class C : public A {
public:
	C (int x, int y) : A (x), m_y (y) {}
	C (C const& that) : m_y (that.m_y) {}
	C& operator= (C const& rhs) {
		m_y = rhs.m_y;
		return *this;
	}
	int m_y;
};
class D : public A {
public:
	D (int x, int y) : A (x), m_y (y) {}
	D (D const& that) : m_y (that.m_y), A (that) {}
	D& operator= (D const& rhs) {
//		A::operator= (rhs);
		static_cast<A&> (*this) = rhs;
		m_y = rhs.m_y;
		return *this;
	}
	int m_y;
};
int main (void) {
	B b1 (1000, 2000);
	cout << b1.m_x << ' ' << b1.m_y << endl;
	B b2 = b1;
	cout << b2.m_x << ' ' << b2.m_y << endl;
	B b3 (3000, 4000);
	b3 = b1;
	cout << b3.m_x << ' ' << b3.m_y << endl;
	cout << "----------" << endl;
	C c1 (1000, 2000);
	cout << c1.m_x << ' ' << c1.m_y << endl;
	C c2 = c1;
	cout << c2.m_x << ' ' << c2.m_y << endl;
	C c3 (3000, 4000);
	c3 = c1;
	cout << c3.m_x << ' ' << c3.m_y << endl;
	cout << "----------" << endl;
	D d1 (1000, 2000);
	cout << d1.m_x << ' ' << d1.m_y << endl;
	D d2 = d1;
	cout << d2.m_x << ' ' << d2.m_y << endl;
	D d3 (3000, 4000);
	d3 = d1;
	cout << d3.m_x << ' ' << d3.m_y << endl;
	return 0;
}
