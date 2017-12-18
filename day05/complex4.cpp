#include <iostream>
using namespace std;
class Complex {
public:
	Complex (int r = 0, int i = 0) :
		m_r (r), m_i (i) {}
	void show (void) const {
		cout << m_r << '+' << m_i << 'i' << endl;
	}
	Complex& operator+= (Complex const& rhs) {
		m_r += rhs.m_r;
		m_i += rhs.m_i;
		return *this;
	}
	friend Complex& operator-= (Complex& lhs,
		Complex const& rhs) {
		lhs.m_r -= rhs.m_r;
		lhs.m_i -= rhs.m_i;
		return lhs;
	}
private:
	int m_r;
	int m_i;
};
int main (void) {
	Complex c1 (1, 2), c2 (3, 4);
	c1.show (); // 1+2i
	c2.show (); // 3+4i
	c1 += c2;
//	c1.operator+= (c2);
	c1.show (); // 4+6i
	(c1 += c2) = c2;
//	c1.operator+= (c2).operator= (c2);
	c1.show (); // 3+4i
	c1 -= c2;
//	::operator-= (c1, c2);
	c1.show (); // 0+0i
	(c1 -= c2) = Complex (5, 6);
//	::operator-= (c1, c2).operator= (Complex (5,6));
	c1.show (); // 5+6i
	return 0;
}
