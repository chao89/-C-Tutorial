#include <iostream>
using namespace std;
class A {
public:
	A (void) {
		m_data = 100;
		cout << "A构造" << endl;
	}
	int m_data;
};
class B {
public:
	B (void) {
		cout << "B构造" << endl;
	}
	A m_a; // 成员子对象
};
int main (void) {
	/*
	A a;
	cout << a.m_data << endl; // 100
	*/
	B b;
	cout << b.m_a.m_data << endl; // 100
	return 0;
}
