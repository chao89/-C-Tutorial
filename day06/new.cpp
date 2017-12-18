#include <cstdlib>
#include <iostream>
using namespace std;
class A {
public:
	A (void) {
		cout << "A构造：" << this << endl;
	}
	~A (void) {
		cout << "A析构：" << this << endl;
	}
	static void* operator new (size_t size) {
		void* p = malloc (size);
		cout << "A::new(" << size << ")返回" << p
			<< endl;
		return p;
	}
	static void operator delete (void* p) {
		cout << "A::delete(" << p << ')' << endl;
		free (p);
	}
	static void* operator new[] (size_t size) {
		void* p = malloc (size);
		cout << "A::new[](" << size << ")返回" << p
			<< endl;
		return p;
	}
	static void operator delete[] (void* p) {
		cout << "A::delete[](" << p << ')' << endl;
		free (p);
	}
private:
	int m_data;
};
int main (void) {
	A* pa = new A;
//	A* pa = (A*)malloc (sizeof (A)); -> 定制
//	A* pa = (A*)A::operator new (sizeof (A));
//	A::A (pa);
	delete pa;
//	A::~A (pa);
//	free (pa); -> 定制
//	A::operator delete (pa);
	cout << "----------------" << endl;
	pa = new A[3];
//	pa = (A*)(A::operator new[](sizeof(A)*3+4)+4);
//	依次调用3次构造函数，初始化数组元素
	cout << pa << endl;
	cout << *((int*)pa - 1) << endl;
	delete[] pa;
//	delete pa;
	return 0;
}
