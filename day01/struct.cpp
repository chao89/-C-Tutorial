#include <iostream>
using namespace std;
struct Student {
	// 成员变量
	char name[64];
	int age;
	// 成员函数
	void who (void) {
		cout << "我是" << name << "，今年" << age
			<< "岁。" << endl;
	}
};
int main (void) {
	Student s1 = {"张飞", 22}, s2 = {"赵云", 20},
		*s3 = &s2;
//	who ();
//	Student::who ();
	s1.who ();
	s3->who ();
	cout << sizeof (s1) << endl;
	return 0;
}
