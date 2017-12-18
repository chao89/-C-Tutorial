// 提供操作符支持的3X3矩阵类
#include <iostream>
#include <iomanip>
using namespace std;
// 3X3矩阵
class M33 {
public:
	M33 (int n = 0) {
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				m_a[i][j] = n;
	}
	M33 (int a[][3]) {
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				m_a[i][j] = a[i][j];
	}
	// +操作符
	M33 const operator+ (M33 const& m) const {
		int a[3][3];
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				a[i][j] = m_a[i][j] + m.m_a[i][j];
		return a;
	}
	// -操作符
	M33 const operator- (M33 const& m) const {
		int a[3][3];
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				a[i][j] = m_a[i][j] - m.m_a[i][j];
		return a;
	}
	// *操作符
	M33 const operator* (M33 const& m) const {
		int a[3][3] = {0};
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				for (int k = 0; k < 3; ++k)
					a[i][j] += m_a[i][k] *
						m.m_a[k][j];
		return a;
	}
	// +=操作符
	M33& operator+= (M33 const& m) {
		return *this = *this + m;
	}
	// -=操作符
	M33& operator-= (M33 const& m) {
		return *this = *this - m;
	}
	// *=操作符
	M33& operator*= (M33 const& m) {
		return *this = *this * m;
	}
	// 负号操作符
	M33 const operator- (void) const {
		return M33 () - *this;
	}
	// 前++操作符
	M33& operator++ (void) {
		return *this += M33 (1);
	}
	// 前--操作符
	M33& operator-- (void) {
		return *this -= M33 (1);
	}
	// 后++操作符
	M33 const operator++ (int) {
		M33 m = *this;
		++*this;
		return m;
	}
	// 后--操作符
	M33 const operator-- (int) {
		M33 m = *this;
		--*this;
		return m;
	}
	// 下标操作符
	int* operator[] (size_t i) {
		return m_a[i];
	}
	int const* operator[] (size_t i) const {
		return const_cast<M33&> (*this)[i];
	}
	// 插入操作符
	friend ostream& operator<< (ostream& os,
		M33 const& m) {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j)
				os << setw (4) << m.m_a[i][j];
			os << endl;
		}
		return os;
	}
private:
	int m_a[3][3];
};
// 测试用例
int main (void) {
	M33 m1 = 7;
	cout << m1 << endl;
	int a1[3][3] = {1,2,3,4,5,6,7,8,9};
	m1 = a1;
	cout << m1 << endl;
	int a2[3][3] = {9,8,7,6,5,4,3,2,1};
	M33 m2 (a2);
	cout << m2 << endl;
	cout << m1 + m2 << endl;
	cout << m1 - m2 << endl;
	cout << m1 * m2 << endl;
	m1 += m2;
	cout << m1 << endl;
	m1 -= m2;
	cout << m1 << endl;
	m1 *= m2;
	cout << m1 << endl;
	cout << -m1 << endl;
	cout << ++m2 << endl;
	cout << m2 << endl;
	cout << --m2 << endl;
	cout << m2 << endl;
	cout << m2++ << endl;
	cout << m2 << endl;
	cout << m2-- << endl;
	cout << m2 << endl;
	++m2[1][1]; // ++*(m2.operator[](1)+1);
	M33 const& cr = m2;
	cout << /*++*/cr[1][1] << endl;
	return 0;
}
