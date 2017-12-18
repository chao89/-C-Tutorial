#include <iostream>
using namespace std;
class A {
public:
	A (void) {
		cout << "缺省构造" << endl;
	}
	A (A const& that) {
		cout << "拷贝构造" << endl;
	}
};
void foo (A a) {} // 拷贝构造，以对象的形式传参
void bar (A& a) {} // 以引用传参避免拷贝构造
A hum (void) {
	A a; // 缺省构造
	cout << "hum:  " << &a << endl;
	return a;
}
int main (void) {
#if 0
	A a1; // 缺省构造
	/*
	A a2 = a1; // 拷贝构造，直接构造对象副本
	*/
//	foo (a1);
	bar (a1);
#endif
	A const& ra = hum (); // 拷贝构造，
	                      // 以对象的形式返回
	cout << "main: " << &ra << endl;
	return 0;
}
