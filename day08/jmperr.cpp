#include <iostream>
#include <cstdio>
#include <csetjmp>
using namespace std;
jmp_buf g_env;
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
		longjmp (g_env, 1);
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
	if (setjmp (g_env) == 1) {
		cout << "配置文件无法打开！" << endl;
		return -1;
	}
	foo ();
	// ...
	cout << "成功！" << endl;
	return 0;
}
