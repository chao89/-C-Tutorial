#include <iostream>
using namespace std;
class Integer {
public:
	// 从int转换来
	Integer (int i = 0) : m_i (i) {}
	// 向int转换去
	operator int (void) const {
		return m_i;
	}
	void show (void) const {
		cout << m_i << endl;
	}
private:
	int m_i;
};
int main (void) {
	Integer i = 10;
	i.show ();
	int n = i;
//	int n = i.operator int ();
	cout << n << endl;
	return 0;
}
