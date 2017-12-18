// 声明学生类
#ifndef _STUDENT_H
#define _STUDENT_H
#include <string>
using namespace std;
// 学生类
class Student {
public:
	Student (string const& name, int age);
	void who (void) const;
	static void where (void);
private:
	static string s_school;
	string m_name;
	int m_age;
};
#endif // _STUDENT_H
