#include <iostream>
using namespace std;
int x = 123;
namespace ns1 {
	int x = 456;
	void foo (void) {
		int x = 789;
		cout << x << endl; // 789
		cout << ns1::x << endl; // 456
		cout << ::x << endl; // 123
	}
}
int main (void) {
	ns1::foo ();
	cout << x << endl; // 123
	/*
	using ns1::x;
	cout << x << ' ' << ::x << endl; // 456 123
	*/
	using namespace ns1;
//	cout << x << endl; // 歧义错误
	cout << ns1::x << ' ' << ::x << endl; // 456 123
	return 0;
}
