#include <iostream>
#include <cstring>
using namespace std;
class Student {
public:
	Student (string const& name, int age) :
		m_name (name), m_age (age) {}
	void who (void) const {
		cout << m_name << "，" << m_age << endl;
	}
	static void where (void) {
		cout << s_school << endl;
	}
	static string s_school;
	double m_weight; // 0
	string m_name;   // 8
/*private:*/
	int    m_age;    // 12
};
string Student::s_school = "达内科技";
int add (int x, int y) {
	return x + y;
}
int main (void) {
	string Student::*pname = &Student::m_name;
	int Student::*page = &Student::m_age;
	int x, y;
	memcpy (&x, &pname, sizeof (x));
	memcpy (&y, &page, sizeof (y));
	cout << x << ' ' << y << endl;
	Student s1 ("张飞", 22), *s2 = &s1;
	Student s3 ("赵云", 20), *s4 = &s3;
	cout << s1.*pname << "，" << s2->*page << endl;
	cout << s3.*pname << "，" << s4->*page << endl;
	void (Student::*pwho) (void) const =
		&Student::who;
	int z;
	memcpy (&z, &pwho, sizeof (z));
	cout << showbase << hex << z << dec << endl;
	(s1.*pwho) ();
	(s4->*pwho) ();
	int (*padd) (int, int) = &add;
	cout << (*padd) (100, 200) << endl;
	string *pschool = &Student::s_school;
	cout << *pschool << endl;
	void (*pwhere) (void) = Student::where;
	pwhere ();
	return 0;
}
