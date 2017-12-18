#include <iostream>
#include <cstdlib>
using namespace std;
class A {
public:
	A (void) {
		cout << "A构造" << endl;
	}
	~A (void) {
		cout << "A析构" << endl;
	}
//	virtual void foo (void) {}
	double m_data;
	static void operator delete (void* pv) {
		cout << "A::delete接收" << pv << endl;
		free (pv);
	}
};
class B {
public:
	B (void) {
		cout << "B构造" << endl;
	}
	virtual ~B (void) {
		cout << "B析构" << endl;
	}
};
class C : public A, public B {
public:
	C (void) {
		cout << "C构造" << endl;
	}
	~C (void) {
		cout << "C析构" << endl;
	}
	static void* operator new (size_t size) {
		void* pv = malloc (size);
		cout << "C::new返回" << pv << endl;
		return pv;
	}
};
int main (void) {
	A* pa = new C;
	delete pa;
	return 0;
}
