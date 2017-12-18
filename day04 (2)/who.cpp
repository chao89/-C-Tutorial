#include <iostream>
using namespace std;
class A {
public:
	~A (void) {
		int a = 1111;
		cout << "析构函数" << endl;
	}
};
int main (void) {
	{
		A a1, *a2 = new A;
		cout << 1 << endl;
		delete a2; // -> A::~A()
		cout << 3 << endl;
		int b = 2222;
	} // -> A::~A()
	int c = 3333;
	cout << 2 << endl;
	return 0;
}
