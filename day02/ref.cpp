#include <iostream>
using namespace std;
int foo (int i) {
	return i;
}
int main (void) {
	int a = 10;
	int& b = a;
	cout << b << endl; // 10
	++b;
	cout << a << endl; // 11
	a = 20;
	cout << b << endl; // 20
	cout << &a << ' ' << &b << endl;
	int const& c = 30;
	cout << &c << endl;
	int x = 40, y = 50;
	int const& d = x + y;
	cout << d << endl;
	char z = 'A';
	int const& e = (int)z;
	cout << e << endl;
	int const& f = foo (a);
	cout << f << endl;
	int& g = a; // 引用必须初始化
	int i;
	g = i; // 把i的值赋值给g也就是赋值给a
	return 0;
}
