#include <iostream>
using namespace std;
class A {
public:
	A (void) {
		cout << "A构造" << endl;
	}
	virtual ~A (void) { // 虚析构函数
		cout << "A析构" << endl;
	}
};
class B : public A {
public:
	B (void) {
		cout << "B构造" << endl;
	}
	~B (void) {
		cout << "B析构" << endl;
	}
};
class C {
public:
	virtual ~C (void) {}
	// 缺省析构函数一定不是虚函数，因此尽管C类本身
	// 并不需要析构函数，但是也要自定义一个析构函数
	// 仅仅是为了通过虚析构保证子类对象中的动态资源
	// 不至于形成内存泄漏
	int m_i;
};
class D : public C {
public:
	D (void) : m_array (new int[128]) {}
	~D (void) {
		cout << "D析构" << endl;
		delete[] m_array;
	}
	int* m_array;
};
int main (void) {
	A* pa = new B;
//	delete static_cast<B*> (pa);
	delete pa;
	C* pc = new D;
	delete pc;
	return 0;
}
