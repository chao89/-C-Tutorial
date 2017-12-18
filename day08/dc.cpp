#include <iostream>
using namespace std;
class A { virtual void foo (void) {} };
class B : public A {};
class C : public B {};
class D {};
int main (void) {
	B b;
	A* pa = &b;
	cout << pa << endl;
	A& ra = b;
	// 转换成功，pa指向的就是B对象
	B* pb = dynamic_cast<B*> (pa);
	cout << pb << endl;
	// 转换失败，pa指向的不是C对象，安全
	C* pc = dynamic_cast<C*> (pa);
	cout << pc << endl; // 0
	try {
		C& rc = dynamic_cast<C&> (ra);
	}
	catch (exception& ex) {
		cout << "将ra动态转换为rc失败："
			<< ex.what () << endl;
	}
	// 转换失败，pa指向的不是D对象，安全
	D* pd = dynamic_cast<D*> (pa);
	cout << pd << endl; // 0
	cout << "----------" << endl;
	// 转换成功，B是A的子类
	pb = static_cast<B*> (pa);
	// 转换成功，C是A的子类的子类，危险
	pc = static_cast<C*> (pa);
	// 转换失败，D和A没有继承关系，安全
//	pd = static_cast<D*> (pa);
	cout << "----------" << endl;
	// 转换永远成功，无论编译期还是运行期都不做类型
	// 一致性检查，最危险！
	pb = reinterpret_cast<B*> (pa);
	cout << pb << endl;
	pc = reinterpret_cast<C*> (pa);
	cout << pc << endl;
	pd = reinterpret_cast<D*> (pa);
	cout << pd << endl;
	return 0;
}
