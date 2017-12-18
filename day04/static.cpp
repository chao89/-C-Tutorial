#include <iostream>
using namespace std;
class A {
public:
	int m_data;
	static int s_data;
};
int A::s_data = 10;
int main (void) {
	cout << &A::s_data << endl;
	A a1, a2;
	cout << &a1.m_data << ' ' << &a2.m_data << endl;
	cout << &a1.s_data << ' ' << &a2.s_data << endl;
	return 0;
}
