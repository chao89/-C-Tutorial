#include <iostream>
using namespace std;
class Complex {
public:
	Complex (int r = 0, int i = 0) :
		m_r (r), m_i (i) {}
	void show (void) const {
		cout << m_r << '+' << m_i << 'i' << endl;
	}
	Complex add (Complex c) {
		return Complex (m_r + c.m_r, m_i + c.m_i);
	}
	Complex sub (Complex c) {
		return Complex (m_r - c.m_r, m_i - c.m_i);
	}
private:
	int m_r;
	int m_i;
};
int main (void) {
	Complex c1 (1, 2), c2 (3, 4);
	c1.show (); // 1+2i
	c2.show (); // 3+4i
	Complex c3 = c1.add (c2);
	c3.show (); // 4+6i
	Complex c4 = c3.sub (c2);
	c4.show (); // 1+2i
	// c5 = c3 - (c1 + c2)
	Complex c5 = c3.sub (c1.add (c2));
	c5.show (); // 0+0i
	// c6 = c3 - c1 + c2
	Complex c6 = c3.sub (c1).add (c2);
	c6.show (); // 6+8i
	return 0;
}
