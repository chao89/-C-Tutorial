#include <iostream>
#include <cstdio>
using namespace std;
class A {
public:
	A (void) { cout << "A构造" << endl; }
	~A (void) { cout << "A析构" << endl; }
};
void hum (void) {
	A a;
	// ...
	FILE* fp = fopen ("none", "r");
	if (! fp)
		throw 1;
	// ...
}
void bar (void) {
	A a;
	// ...
	hum ();
	// ...
}
void foo (void) {
	A a;
	// ...
	bar ();
	// ...
}
int main (void) {
	// ...
	try {
		foo ();
	}
	catch (int ex) {
		if (ex == 1) {
			cout << "配置文件无法打开！" << endl;
			return -1;
		}
	}
	// ...
	cout << "成功！" << endl;
	return 0;
}
