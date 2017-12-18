#include <iostream>
using namespace std;
class Complex {
public:
	Complex (int r = 0, int i = 0) :
		m_r (r), m_i (i) {}
	void show (void) const {
		cout << m_r << '+' << m_i << 'i' << endl;
	}
	// 从左向右三个const依次为：
	// 第一个const：返回常对象，禁止修改表达式的值
	// 第二个const：支持常量型的右操作数
	// 第三个const：支持常量型的左操作数
	Complex const operator+ (
		Complex const& rhs) const {
		return Complex (m_r + rhs.m_r,
			m_i + rhs.m_i);
	}
private:
	int m_r;
	int m_i;
	// 在友元函数中可以访问类的私有成员
	friend Complex const operator- (
		Complex const&, Complex const&);
};
Complex const operator- (Complex const& lhs,
	Complex const& rhs) {
	return Complex (lhs.m_r - rhs.m_r,
		lhs.m_i - rhs.m_i);
}
int main (void) {
	/*
	int a = 10, b = 20, c = 30;
	(a + b) = c;
	*/
	Complex const c1 (1, 2);
	Complex const c2 (3, 4);
	c1.show (); // 1+2i
	c2.show (); // 3+4i
	Complex c3 = c1 + c2;
//	Complex c3 = c1.operator+ (c2);
	c3.show (); // 4+6i
//	(c1 + c2) = c3;
	Complex c4 = c3 - c2;
//	Complex c4 = ::operator- (c3, c2);
	c4.show (); // 1+2i
	Complex c5 = c3 - (c1 + c2);
//	Complex c5 = ::operator- (c3,
//		c1.operator+ (c2));
	c5.show (); // 0+0i
	Complex c6 = c3 - c1 + c2;
//	Complex c6 = ::operator- (c3,c1).operator+ (c2);
	c6.show (); // 6+8i
	return 0;
}
