#include <stdio.h>
//struct A {};
int main (void) {
	/*
	struct A a;
	printf ("%d\n", sizeof (a));
	printf ("%p\n", &a);*/
	int a = 4;
	(++a) += (a++);
//	printf ("%d\n", a); // 11
	return 0;
}
