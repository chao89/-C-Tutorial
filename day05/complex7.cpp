#include <iostream>
using namespace std;
class Complex {
public:
	Complex (int r = 0, int i = 0) :
		m_r (r), m_i (i) {}
	friend ostream& operator<< (ostream& lhs,
		Complex const& rhs) {
		return lhs << rhs.m_r << '+'
			<< rhs.m_i << 'i';
	}
	friend istream& operator>> (istream& lhs,
		Complex& rhs) {
		return lhs >> rhs.m_r >> rhs.m_i;
	}
private:
	int m_r;
	int m_i;
};
int main (void) {
	Complex c1 (1, 2), c2 (3, 4);
	cout << c1 << ", " << c2 << endl; // 1+2i, 3+4i
//	cout.operator<< (c1)，必须把operator<<定义为cout
//	的类ostream的成员函数，而ostream类并非自己定义的
//	::operator<< (cout, c1)，返回cout本身以支持后续
//	插入
//	::operator<< (
//		::operator<< (cout, c1).
//			operator<< (", "), c2).
//				operator<< (endl);
	cin >> c1 >> c2;
//	::operator>> (::operator>> (cin, c1), c2);
	cout << c1 << ", " << c2 << endl;
	return 0;
}
