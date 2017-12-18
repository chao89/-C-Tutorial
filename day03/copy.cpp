#include <iostream>
using namespace std;
class A {
public:
	A (int i, double d, string const& s) {
		m_i = i;
		m_d = d;
		m_s = s;
	}
	/*
	// 拷贝构造函数
	A (A const& that) {
		cout << "拷贝构造开始执行..." << endl;
		m_i = that.m_i;
		m_d = that.m_d;
		m_s = that.m_s;
		cout << "拷贝构造执行完毕！" << endl;
	}
	*/
	void show (void) {
		cout << m_i << ',' << m_d << ',' << m_s
			<< endl;
	}
private:
	int m_i;
	double m_d;
	string m_s;
};
int main (void) {
	A a1 (123, 4.56, "ABCDE");
	a1.show ();
	A a2 = a1; // 拷贝构造
//	A a2 (a1); // 与上等价
	a2.show ();
//	A a3;
	return 0;
}
