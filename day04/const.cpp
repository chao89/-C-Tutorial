#include <iostream>
using namespace std;
class A {
public:
	A (int data = 0) : m_data (data) {}
	void show (void) const { // 常函数
		cout << m_data/*++*/ << endl;
	}
private:
	int m_data;
};
/*
void _ZN1A4showEv (A const* this) {
	cout << this->m_data++ << endl;
}
*/
class Document {
public:
	Document (string const& text) : m_text (text),
   		m_times (0) {}
	void update (string const& text) {
		m_text = text;
	}
	void render (void) const {
		if (m_times < 10) {
			cout << m_text << endl;
//			++const_cast<Document*> (this)->m_times;
			++m_times;
		}
		else
			cout << "请付费！" << endl;
	}
private:
	string m_text;
	mutable size_t m_times;
};
class B {
public:
	void foo (void) const {}
	void bar (void) {}
	void hum (void) const {
		cout << "hum函数的常版本" << endl;
	} // B const* this
	void hum (void) {
		cout << "hum函数的非常版本" << endl;
	} // B* this
};
int main (void) {
	A a (123);
	a.show (); // 123
	a.show ();
	Document doc ("Hello, World !");
	for (int i = 0; i < 10; ++i)
		doc.render ();
	doc.render ();
	B b;
	b.foo (); // &b : B* -> this : B const*
	b.bar (); // &b : B* -> this : B*
	B const& r = b;
	r.foo (); // &r : B const* -> this : B const*
//	r.bar (); // &r : B const* -> this : B*, 错误
	B const* p = &b;
	p->foo (); // p : B const* -> this : B const*
//	p->bar (); // p : B const* -> this : B*, 错误
	b.hum ();
	r.hum ();
	p->hum ();
	return 0;
}
