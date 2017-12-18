#include <errno.h>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <memory>
using namespace std;
class X {
public:
	X (void) { cout << "X构造" << endl; }
	~X (void) { cout << "X析构" << endl; }
};
class Y {
public:
	Y (void) { cout << "Y构造" << endl; }
	~Y (void) { cout << "Y析构" << endl; }
};
class A {
public:
	A (size_t size) : m_x (new X) {
		if (! (m_p = (char*)malloc (size))) {
//			delete m_x;
			throw strerror (errno);
		}
	}
	~A (void) {
		free (m_p);
//		delete m_x;
	}
	void set (char const* p) {
		strcpy (m_p, p);
	}
	char const* get (void) const {
		return m_p;
	}
private:
	char* m_p;
//	X* m_x;
	auto_ptr<X> m_x;
	Y m_y; // 成员子对象
};
int main (void) {
	try {
		A a (/*1024*/0xFFFFFFFF);
		a.set ("Hello, World !");
		cout << a.get () << endl;
	}
	catch (char const*& ex) {
		cout << ex << endl;
		return -1;
	}
	return 0;
}
