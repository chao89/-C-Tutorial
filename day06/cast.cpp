#include <iostream>
using namespace std;
class Integer {
public:
	// 从int转换来，explicit关键字表明基于该构造函数
	// 的类型转换必须显式进行
	explicit Integer (int i = 0) : m_i (i) {}
	// 向int转换去，C++2011支持对类型转换操作符函数
	// 使用exlicit关键字，C++98语法不支持
	/*explicit*/ operator int (void) const {
		return m_i;
	}
	void show (void) const {
		cout << m_i << endl;
	}
private:
	int m_i;
};
int main (void) {
//	Integer i = (Integer)10;
//	Integer i = Integer (10);
	Integer i = static_cast<Integer> (10);
	i.show ();
	int n = i;
//	int n = i.operator int ();
	cout << n << endl;
	return 0;
}
