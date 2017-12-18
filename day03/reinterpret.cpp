#include <iostream>
#include <cstdio>
using namespace std;
int main (void) {
	int i = 0x12345678;
	char* p = reinterpret_cast<char*> (&i);
	printf ("%#x %#x %#x %#x\n", p[0], p[1],
		p[2], p[3]); // 0x78 0x56 0x34 0x12
	i = 100;
	float f = i;
	cout << f << endl; // 100
	cout << &f << ' ' << &i << endl;
	float& r = reinterpret_cast<float&> (i);
	cout << r << endl; // ?
	cout << &r << ' ' << &i << endl;
	i = reinterpret_cast<int> (&i);
	printf ("%#x %p\n", i, &i);
//	f = reinterpret_cast<float> (&f);
	p = reinterpret_cast<char*> (0x1234);
	printf ("%p\n", p);
	return 0;
}
