#include <iostream>
#include <cstring>
using namespace std;
class A {
public:
	A (int i = 0, double d = 3.14,
		string const& s = "XYZ") : m_i (i),
	 	m_d (d), m_s (s) {
		/*
		m_i = i;
		m_d = d;
		m_s = s;
		*/
	}
	void show (void) {
		cout << m_i << ',' << m_d << ',' << m_s
			<< endl;
	}
private:
	int m_i;
	double m_d;
	string m_s;
};
class B { // 无缺省构造函数
public:
	B (int i) : m_i (i) {}
private:
	int m_i;
};
class C {
public:
	C (int i) : m_b (i) {
		m_i = i;
//		m_b = i;
	}
private:
	int m_i;
	B m_b; // 成员子对象，其类型无缺省构造函数
};
int g_global = 10;
class D {
public:
	D (int i) : m_i (i), m_r (g_global) {
//		m_i = i;
//		m_r = g_global;
	}
	int const m_i;
	int& m_r;
};
class E {
public:
	E (char const* str) : m_str (str),
		m_len (strlen (str)) {}
	size_t m_len;
	string m_str;
};
int main (void) {
	A a (123, 4.56);
	a.show (); // 123,4.56,XYZ
	C c (789);
	D d (987);
	cout << d.m_i << ' ' << d.m_r << endl;
	E e ("abcde");
	cout << e.m_len << ' ' << e.m_str << endl;
	// 5 abcde
	return 0;
}
