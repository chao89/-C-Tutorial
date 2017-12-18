#include <iostream>
using namespace std;
int main (void) {
	int const volatile i = 100; // 只读变量
//	i = 200;
	int* p = const_cast<int*> (&i);
	*p = 200;
	cout << p << ' ' << &i << endl;
	cout << *p << endl;
	cout << i << endl; // cout << 100 << endl;
	int& r = const_cast<int&> (i);
	++r;
	cout << i << endl; // 201
	int const* cp = p;
	int const& cr = r;
	return 0;
}
