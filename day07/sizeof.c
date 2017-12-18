#include <stdio.h>
int main (void) {
	printf ("%d\n", sizeof (6 > 5.0));
	printf ("%d\n", sizeof (0 < 1 ? 6 : 5.0));
	return 0;
}
