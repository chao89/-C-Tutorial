#include <cstring>
#include <iostream>
using namespace std;
class String {
public:
	String (char const* str = NULL) :
		m_str (strcpy (
			new char[strlen (str ? str : "") + 1],
			str ? str : "")) {}
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
int main (void) {
	String s1 = "Hello, World !";
	cout << s1.c_str () << endl;
	return 0;
}
