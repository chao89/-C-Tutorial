#include <iostream>
using namespace std;
void foo (char a = '$', int b = 1000,
	double c = 0.01, string d = "XYZ");
//void foo (void) {}
int main (void) {
	foo ('A', 123, 3.14, "Hello, World !");
	foo ('A', 123, 3.14);
	foo ('A', 123);
	foo ('A');
	foo ();
	return 0;
}
void foo (char a, int b, double c, string d) {
	cout << a << ' ' << b << ' ' << c << ' ' << d
		<< endl;
}
