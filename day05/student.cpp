// 实现学生类
#include <iostream>
using namespace std;
#include "student.h"
string Student::s_school = "达内科技";
Student::Student (string const& name, int age) :
	m_name (name), m_age (age) {}
void Student::who (void) const {
	cout << m_name << "，" << m_age << endl;
}
void Student::where (void) {
	cout << s_school << endl;
}
