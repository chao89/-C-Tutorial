#include <cstdio>
#include <iostream>
using namespace std;
int main (void) {
	union {
		int n;
		char c[4];
	};
	n = 10;
	c[0] = 0x78;
	c[1] = 0x56;
	c[2] = 0x34;
	c[3] = 0x12;
	printf ("%#x\n", n); // 0xa->0x12345678
	return 0;
}
