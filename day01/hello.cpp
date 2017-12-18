#include <iostream>
//#include <stdio.h>
#include <cstdio>
int main (void) {
	std::cout << "Hello, World !" << std::endl;
	printf ("Hello, World !\n");
	int x;
	double y;
	std::cin >> x >> y;
//	scanf ("%d%lf", &x, &y);
	std::cout << x << ' ' << y << std::endl;
//	printf ("%d%c%g\n", x, ' ' ,y);
	return 0;
}
