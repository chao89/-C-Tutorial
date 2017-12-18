#include <iostream>
using namespace std;
// 单例模式
class A {
public:
	static A& getInstance (void) {
		/*
		if (! s_instance)
			s_instance = new A (1234);
		return *s_instance;
		*/
		return s_instance;
	}
private:
	A (int data = 0) : m_data (data) {}
	A (A const& that);
	int m_data;
	/*
	static A* s_instance;
	*/
	static A s_instance;
};
/*
A* A::s_instance = NULL;
*/
A A::s_instance (1234);
int main (void) {
//	A a;
//	A* a = new A (1234);
	A& a1 = A::getInstance ();
	A& a2 = A::getInstance ();
	cout << &a1 << ' ' << &a2 << endl;
//	A a3 = a1;
	return 0;
}
