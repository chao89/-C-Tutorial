#include <iostream>
#include <cstdio>
using namespace std;
class A {
public:
	A (void) { cout << "A构造" << endl; }
	~A (void) { cout << "A析构" << endl; }
};
int hum (void) {
	A a;
	// ...
	FILE* fp = fopen ("none", "r");
	if (! fp)
		return -1;
	// ...
	return 0;
}
int bar (void) {
	A a;
	// ...
	if (hum () == -1)
		return -1;
	// ...
	return 0;
}
int foo (void) {
	A a;
	// ...
	if (bar () == -1)
		return -1;
	// ...
	return 0;
}
int main (void) {
	// ...
	if (foo () == -1) {
		cout << "配置文件无法打开！" << endl;
		return -1;
	}
	// ...
	return 0;
}
