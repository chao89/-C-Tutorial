#include <iostream>
using namespace std;
class A {
public:
	virtual void foo (void) = 0;
	int m_x;
};
class B : virtual public A {
public:
	int m_y;
};
int main (void) {
	cout << sizeof (B) << endl; // 8/12/16
	return 0;
}
