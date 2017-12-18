#include <iostream>
using namespace std;
class A {
public:
	// 缺省构造函数，初始化对象为缺省状态
	A (void) {
		m_x = 0;
		m_y = 0;
		m_z = 0;
	}
	// 类型转换构造函数，支持从int类型转换
	A (int x) {
		m_x = x;
		m_y = 0;
		m_z = 0;
	}
	A (int x, int y) {
		m_x = x;
		m_y = y;
		m_z = 0;
	}
	A (int x, int y, int z) {
		m_x = x;
		m_y = y;
		m_z = z;
	}
	void show (void) const {
		cout << m_x << ',' << m_y << ',' << m_z
			<< endl;
	}
private:
	int m_x, m_y, m_z;
};
class B {
public:
//	B (int i) {}
	int m_i;
	A m_a;
};
//void foo (A a) {
void foo (A const& a) {
	a.show ();
}
A bar (void) {
	return 4000;
}
int main (void) {
	A a1;
//	A a1 (); // 被看作函数声明而非创建对象
	a1.show (); // 0,0,0
	A a2 (100);
	a2.show (); // 100,0,0
	A a3 (100, 200);
	a3.show (); // 100,200,0
	A a4 (100, 200, 300);
	a4.show (); // 100,200,300
	A a5 = 1000; // 通过类型转换构造函数将1000
	             // 转换为A类型的对象,初始化a5
	a5.show (); // 1000,0,0
	a4 = 2000;
	a4.show (); // 2000,0,0
	foo (3000); // 3000,0,0
	bar ().show (); // 4000,0,0
//	B b (1);
	B b;
	cout << b.m_i << endl;
	b.m_a.show ();
	return 0;
}
