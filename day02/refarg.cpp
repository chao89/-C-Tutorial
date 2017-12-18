#include <iostream>
using namespace std;
int maximum (int x, int y) {
	return x < y ? y : x;
}
int max_min (int x, int y, int* z) {
	*z = x < y ? x : y;
	return x < y ? y : x;
}
int max_min (int x, int y, int& z) {
	z = x < y ? x : y;
	return x < y ? y : x;
}
void swap1 (int x, int y) {
	int z = x;
	x = y;
	y = z;
}
void swap2 (int* x, int* y) {
	int z = *x;
	*x = *y;
	*y = z;
}
void swap3 (int& x, int& y) {
	int z = x;
	x = y;
	y = z;
}
void swap4 (char const* x, char const* y) {
	char const* z = x;
	x = y;
	y = z;
}
void swap5 (char const** x, char const** y) {
	char const* z = *x;
	*x = *y;
	*y = z;
}
void swap6 (char const*& x, char const*& y) {
	char const* z = x;
	x = y;
	y = z;
}
struct Student {
	char name[64];
	int age;
	char info[1024];
};
void print (Student const& s) {
	cout << s.name << ',' << s.age/*++*/ << ','
		<< s.info << endl;
}
void print (int const& i) {
	cout << i << endl;
}
int foo (int i) {
	return i;
}
int main (void) {
	int a = 123, b = 456;
	cout << maximum (a, b) << endl;
	int c, d = max_min (a, b, &c);
	cout << d << ' ' << c << endl;
	int e, f = max_min (a, b, e);
	cout << f << ' ' << e << endl;
	swap1 (a, b); // 不成功的交换
	cout << a << ' ' << b << endl; // 123 456
	swap2 (&a, &b);
	cout << a << ' ' << b << endl; // 456 123
	swap3 (a, b);
	cout << a << ' ' << b << endl; // 123 456
	char const* g = "hello", *h = "world";
	swap4 (g, h); // 不成功的交换
	cout << g << ' ' << h << endl; // hello world
	swap5 (&g, &h);
	cout << g << ' ' << h << endl; // world hello
	swap6 (g, h);
	cout << g << ' ' << h << endl; // hello world
	Student sa = {"张飞", 22, "达内的1505班的学生"};
	print (sa);
	print (sa);
	print (10);
	print (a + b);
	print ('A');
	print (foo (a));
	return 0;
}
