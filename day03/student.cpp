#include <iostream>
using namespace std;
class Student {
public:
	// 构造函数
	Student (string const& name, int age,
		int no) {
		m_name = name;
		m_age = age;
		m_no = no;
	} 	
	// 吃饭
	void eat (string const& food) {
		cout << "我在吃" << food << "。" << endl;
	}
	// 睡觉
	void sleep (int duration) {
		cout << "我睡了" << duration << "小时。"
			<< endl;
	}
	// 学习
	void learn (string const& course) {
		cout << "我在学" << course << "。" << endl;
	}
	// 自我介绍
	void who (void) {
		cout << "我叫" << m_name << "，今年"
			<< m_age << "岁。我的学号是" << m_no
			<< "。" << endl;
	}
	// 起名
	void setName (string const& name) {
		if (name == "SB")
			cout << "拒绝不雅的姓名！" << endl;
		else
			m_name = name;
	}
private:
	string m_name; // 姓名
public:
	int m_age; // 年龄
	int m_no; // 学号
};
int main (void) {
	Student s1 ("张飞", 22, 1001);
//	s1.m_name = "张飞";
//	s1.m_name = "SB";
	/*
	s1.setName ("SB");
	s1.setName ("张飞");
	s1.m_age = 22;
	s1.m_no = 1001;
	*/
	s1.who ();
	s1.eat ("拉面");
	s1.sleep (2);
	s1.learn ("C++");
	Student sa[/*3*/] = {
		Student ("张飞", 22, 1001),
		Student ("赵云", 20, 1002),
		Student ("关羽", 25, 1003)};
	sa[0].who ();
	sa[1].who ();
	sa[2].who ();
	Student* ps = new Student ("张飞", 22, 1001);
	ps->who ();
	delete ps;
	ps = new Student[3] {
		Student ("张飞", 22, 1001),
		Student ("赵云", 20, 1002),
		Student ("关羽", 25, 1003)};
	ps[0].who ();
	ps[1].who ();
	ps[2].who ();
	delete[] ps;
	return 0;
}
