#include <iostream>
using namespace std;
class A {
public:    int m_pub; // 公有成员
protected: int m_pro; // 保护成员
private:   int m_pri; // 私有成员
};
class B : public    A {}; // 公有子类
class C : protected A {}; // 保护子类
class D : private   A {}; // 私有子类
class E : public B {
public:
	void foo (void) {
		m_pub = 1; // Ok
		m_pro = 2; // Ok
//		m_pri = 3; // No
	}
};
class F : public C {
	void foo (void) {
		m_pub = 4; // Ok
		m_pro = 5; // Ok
//		m_pri = 6; // No
	}
};
class G : public D {
	void foo (void) {
//		m_pub = 7; // No
//		m_pro = 8; // No
//		m_pri = 9; // No
	}
};
int main (void) {
	B b;
	b.m_pub = 1; // Ok
//	b.m_pro = 2; // No
//	b.m_pri = 3; // No
	C c;
//	c.m_pub = 4; // No
//	c.m_pro = 5; // No
//	c.m_pri = 6; // No
	D d;
//	d.m_pub = 7; // No
//	d.m_pro = 8; // No
//	d.m_pri = 9; // No
};
