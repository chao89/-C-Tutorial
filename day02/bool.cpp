#include <iostream>
using namespace std;
int main (void) {
	bool b;
	cout << sizeof (b) << endl;
	cout << boolalpha;
	b = true;
	cout << b << endl;
	b = false;
	cout << b << endl;
	b = 12 * 3;
	cout << b << endl;
	double x = 0.0, y = 123.456;
	b = x * y;
	cout << b << endl;
	char const* p = "Hello, World !";
	b = p;
	cout << b << endl;
	int*** q = NULL;
	b = q;
	cout << b << endl;
	if (p)
		cout << "不是空指针！" << endl;
	return 0;
}
