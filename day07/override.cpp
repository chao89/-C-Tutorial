#include <iostream>
using namespace std;
class X {};
/*
class Y {};
*/
class Y : public X {};
//virtual void foo (void) {}
class A {
public:
//	static virtual void foo (void) {}
	void foo (void) {
		cout << "A::foo()" << endl;
	}
	virtual void bar (void) {
		cout << "A::bar()" << endl;
	}
	virtual void hum (void) {
		cout << "A::hum(void)" << endl;
	}
	virtual X* fun (void) {
		cout << "A::fun(void)" << endl;
	}
	virtual X& dum (void) {
		cout << "A::dum(void)" << endl;
	}
};
class B : public A {
public:
	virtual void foo (void) {
		cout << "B::foo()" << endl;
	}
	void Bar (void) { // 函数名不一致
		cout << "B::Bar(void)" << endl;
	}
	void bar (int) { // 形参表不一致
		cout << "B::bar(int)" << endl;
	}
	void bar (void) const { // 常属性不一致
		cout << "B::bar(void) const" << endl;
	}
	void bar (void) { // 有效覆盖
		cout << "B::bar(void)" << endl;
	}
	/*
	int hum (void) { // 返回类型不一致，不正当关系
		cout << "B::hum(void)" << endl;
	}
	*/
	/*X*/Y* fun (void) { // 返回类型协变
		cout << "B::fun(void)" << endl;
	}
private:
	/*X*/Y& dum (void) { // 返回类型协变
		cout << "B::dum(void)" << endl;
	}
};
int main (void) {
	B b;
	A& a = b;
	a.foo ();
	a.bar ();
	a.fun ();
	a.dum ();
	A o = b; // 对象截切
	o.foo ();
	return 0;
}
