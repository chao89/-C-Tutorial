#include <iostream>
using namespace std;
int main (void) {
	int i = 100, j = 200;
	const int* p1 = &i; // 常量指针，目标只读
	i = 300;
//	*p1 = 300;
	int const* p2 = &i; // 同上
	int *const p3 = &i; // 指针常量，指针本身只读
//	p3 = &j;
	*p3 = 300;
	const int* const p4 = &i; // 常量指针常量
	int const* const p5 = &i; // 指针的目标和指针
	                          // 本身都只读
//	*p4 = 300;
//	p4 = &j;
//	*p5 = 500;
//	p5 = &j;
	const int& r1 = i; // 常量引用，引用目标只读
//	++r1;
	int const& r2 = i; // 同上
//	r2--;
//	int& const r3 = i; // 引用本身没有常属性
//	const int& const r4 = i;
//	int const& const r5 = i;
	int const& r6 = 3 + 4;
	cout << &r6 << ' ' << r6 << endl;
//	int const* p = &(3+4);
	return 0;
}

