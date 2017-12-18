#include <cstdio>
#include <iostream>
using namespace std;
class Student {
public:
	Student (void) {
		cout << "Student构造：" << this << endl;
	}
	~Student (void) {
		cout << "Student析构：" << this << endl;
	}
	string m_name;
	void who (void) const {
		cout << m_name << endl;
	}
};
class PStudent {
public:
	PStudent (Student* ps = NULL) : m_ps (ps) {}
	~PStudent (void) {
		if (m_ps) {
			delete m_ps;
			m_ps = NULL;
		}
	}
	Student& operator* (void) const {
		return *m_ps;
	}
	Student* operator-> (void) const {
		return &**this;
	}
private:
	Student* m_ps;
};
int foo (void) {
	PStudent ps (new Student);
	// 使用ps...
	(*ps).m_name = "张飞";
//	ps.operator* ().m_name = "张飞";
	ps->who ();
//	ps.operator-> ()->who ();
	// 使用ps...
	FILE* fp = fopen ("none", "r");
	if (! fp) {
		perror ("fopen");
		return -1;
	}
	// 使用ps...
	return 0;
}
int main (void) {
	foo ();
	return 0;
}
