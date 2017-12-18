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
	return 0;
}
