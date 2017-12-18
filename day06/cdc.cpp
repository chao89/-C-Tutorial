#include <iostream>
using namespace std;
class A {
public:
	A (void) : m_x (0) {
		cout << "A缺省构造" << endl;
	}
	A (int x) : m_x (x) {
		cout << "A有参构造" << endl;
	}
protected:
	int m_x;
};
class B : public A {
public:
	B (int y) : m_y (y) {}
	B (int x, int y) : A (x), m_y (y) {}
	friend ostream& operator<< (ostream& os,
		B const& b) {
		return os << b.m_x << ", " << b.m_y;
	}
private:
	int m_y;
};
int main (void) {
	B b1 (200);
	cout << b1 << endl;
	B b2 (100, 200);
	cout << b2 << endl;
	return 0;
}
