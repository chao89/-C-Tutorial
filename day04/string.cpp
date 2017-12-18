#include <cstring>
#include <iostream>
using namespace std;
class String {
public:
	String (char const* str = NULL) :
		m_str (strcpy (
			new char[strlen (str ? str : "") + 1],
			str ? str : "")) {}
	/*
	// 只支持浅拷贝的缺省拷贝构造函数
	String (String const& that) :
		m_str (that.m_str) {} */
	// 支持深拷贝的拷贝构造函数
	String (String const& that) :
		m_str (strcpy (
			new char[strlen (that.m_str) + 1],
			that.m_str)) {}
	/*
	// 只支持浅拷贝的缺省拷贝赋值运算符函数
	void operator= (String const& rhs) {
		m_str = rhs.m_str;
	} */
	// 支持深拷贝的拷贝赋值运算符函数
	/* 菜鸟版
	void operator= (String const& rhs) {
		strcpy (m_str, rhs.m_str);
	} */
	/* 小鸟版
	String& operator= (String const& rhs) {
		if (&rhs != this) {
			delete[] m_str;
			m_str = strcpy (
				new char[strlen (rhs.m_str) + 1],
				rhs.m_str);
		}
		return *this;
	} */
	/* 大鸟版
	String& operator= (String const& rhs) {
		if (&rhs != this) {
			char* str =
				new char[strlen (rhs.m_str) + 1];
			delete[] m_str;
			m_str = strcpy (str, rhs.m_str);
		}
		return *this;
	} */
	// 老鸟版
	String& operator= (String const& rhs) {
		if (&rhs != this) {
			String str = rhs;
			swap (m_str, str.m_str);
		}
		return *this;
	}
	// 析构函数
	~String (void) {
		if (m_str) {
			delete[] m_str;
			m_str = NULL;
		}
	}
	char const* c_str (void) const {
		return m_str;
	}
private:
	char* m_str;
};
class A {
public:
	A (int data = 0) : m_data (data) {}
private:
	A (A const& that);
	A& operator= (A const& rhs);
	int m_data;
};
void print (ostream& os) {
	os << "Hello, World !" << endl;
}
int main (void) {
	String s1 = "Hello, World !";
	cout << s1.c_str () << endl;
	String s2 = s1; // 拷贝构造
	cout << s2.c_str () << endl;
	String s3 = "你好，世界！";
	s2 = s3; // 拷贝赋值
//	s2.operator= (s3);
	cout << s2.c_str () << endl;
	/*
	int x = 10, y = 20, z = 30;
	(x = y) = z;
	cout << x << endl; // 30 */
	A a1 (100);
//	A a2 = a1;
	A a3 (200);
//	a1 = a3;
	print (cout);
	return 0;
}
