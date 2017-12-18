#include <iostream>
using namespace std;
enum Color {RED, YELLOW, BLUE, WHITE, BLACK};
void foo (Color color) {
	cout << color << endl;
}
Color bar (void) {
	return YELLOW;
//	return 1;
}
int main (void) {
	Color color;
	color = RED;
	cout << color << endl; // 0
//	color = 0;
	int i = color;
	cout << i << endl;
	foo (WHITE); // 3
//	foo (3);
	cout << bar () << endl; // 1
	return 0;
}
