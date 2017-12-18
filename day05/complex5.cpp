#include <cmath>
#include <iostream>
using namespace std;
class Complex {
public:
	Complex (int r = 0, int i = 0) :
		m_r (r), m_i (i) {}
	void show (void) const {
		cout << m_r << '+' << m_i << 'i' << endl;
	}
	Complex const operator- (void) const {
		return Complex (-m_r, -m_i);
	}
	friend int operator~ (Complex const& opd) {
		return sqrt (opd.m_r * opd.m_r +
			opd.m_i * opd.m_i);
	}
private:
	int m_r;
	int m_i;
};
int main (void) {
	Complex c1 (1, 2), c2 (3, 4);
	c1.show (); // 1+2i
	c2.show (); // 3+4i
	Complex c3 = -c1;
//	Complex c3 = c1.operator- ();
	c3.show (); // -1+-2i
	int r = ~c2;
//	int r = ::operator~ (c2);
	cout << r << endl; // 5
	return 0;
}
