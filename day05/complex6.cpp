#include <iostream>
using namespace std;
class Complex {
public:
	Complex (int r = 0, int i = 0) :
		m_r (r), m_i (i) {}
	void show (void) const {
		cout << m_r << '+' << m_i << 'i' << endl;
	}
	// 前++
	Complex& operator++ (void) {
		++m_r;
		++m_i;
		return *this;
	}
	// 前--
	friend Complex& operator-- (Complex& opd) {
		--opd.m_r;
		--opd.m_i;
		return opd;
	}
	// 后++
	Complex const operator++ (int) {
		Complex old = *this;
		++*this;
		return old;
	}
	// 后--
	friend Complex const operator-- (Complex& opd,
		int) {
		Complex old = opd;
		--opd;
		return old;
	}
private:
	int m_r;
	int m_i;
};
int main (void) {
	Complex c1 (1, 2), c2 (3, 4);
	c1.show (); // 1+2i
	c2.show (); // 3+4i
	Complex c3 = ++c1;
//	Complex c3 = c1.operator++ ();
	c3.show (); // 2+3i
	c1.show (); // 2+3i
	++++c1;
//	c1.operator++ ().operator++ ();
	c1.show (); // 4+5i
	c3 = --c1;
//	c3 = ::operator-- (c1);
	c3.show (); // 3+4i
	c1.show (); // 3+4i
	----c1;
//	::operator-- (::operator-- (c1));
	c1.show (); // 1+2i
	c3 = c1++;
//	c3 = c1.operator++ (0);
	c3.show (); // 1+2i
	c1.show (); // 2+3i
//	c1++++; // 错误
//	c1.operator++ (0).operator++ (0);
	c3 = c1--;
//	c3 = ::operator-- (c1, 0);
	c3.show (); // 2+3i
	c1.show (); // 1+2i
//	c1----; // 错误
//	::operator-- (::operator-- (c1, 0), 0);
	return 0;
}
