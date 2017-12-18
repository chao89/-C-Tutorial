#include <iostream>
using namespace std;
int main (void) {
	int i = 0;
	cout << ++i << endl; // 1
	cout << i << endl;   // 1
	cout << i++ << endl; // 1
	cout << i << endl;   // 2
	++++++++i; // 前缀自增减表达式的值是左值，就是
	           // 操作数本身(引用)
	cout << i << endl;   // 6
//	i++++++++; // 后缀自增减表达式的值是右值，是保
	           // 存操作数自增减之前值的临时变量
	++i = 10;
	cout << i << endl; // 10
//	i++ = 20;
	cout << &i << ' ' << &++i << endl;
	int const& r = i++;
	cout << &i << ' ' << &r << endl;
	return 0;
}
