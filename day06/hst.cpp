#include <iostream>
using namespace std;
// 人类
class Human {
public:
	Human (string const& name, int age) :
		m_name (name), m_age (age), m_id (100) {}
	void eat (string const& food) const {
		cout << "我在吃" << food << "。" << endl;
	}
	void sleep (int durations) const {
		cout << "我睡了" << durations << "小时。"
			<< endl;
	}
protected: // 保护型成员可以在类的内部和子类中被访问
	int const& id (void) const {
		return m_id;
	}
	string m_name;
	int m_age;
private:
	int m_id;
};
// 学生
class Student : public Human {
public:
	// 基类的构造函数和析构函数不能被继承，因此子类
	// 需要根据实际情况定义自己的构造函数
	Student (string const& name, int age, int no) :
		Human (name, age), m_no (no) {}
	// 子类的构造函数可以显式指明其基类的初始化方式
	// ，否则其基类部分将按照缺省方式被初始化，但是
	// 前提是该基类必须支持缺省构造
	void who (void) const {
		// 基类中的公有和保护成员可以在子类中直接访
		// 问，就象它们被声明在子类中一样	
		cout << "我叫" << m_name << "，今年"
			<< m_age << "岁。我的学号是" << m_no
			<< "。" << endl;
		cout << id () << endl;
	}
	void learn (string const& course) const {
		cout << "我在学" << course << "。" << endl;
	}
	void printAddr (void) const {
		cout << &m_name << endl;
		cout << &m_age << endl;
		cout << &m_no << endl;
		cout << this << endl;
		cout << sizeof (Human) << endl;
		cout << sizeof (Student) << endl;
	}
private:
	int m_no;
};
// 教师
class Teacher : public Human {
public:
	Teacher (string const& name, int age,
		double salary) : Human (name, age),
		m_salary (salary) {}
	void who (void) const {
		cout << "我叫" << m_name << "，今年"
			<< m_age << "岁。我一个月挣" << m_salary
			<< "。" << endl;
	}
	void teach (string const& course) const {
		cout << "我在教" << course << "。" << endl;
	}
private:
	double m_salary;
};
int main (void) {
	Student s ("张飞", 22, 1001);
	s.who ();       // 可以通过子类对象直接访问其从
	s.eat ("米饭"); // 基类继承的成员，就如同它们是
	s.sleep (1);    // 子类的成员
	s.learn ("标C");
	Teacher t ("杨健", 40, 20000);
	t.who ();
	t.eat ("面条");
	t.sleep (2);
	t.teach ("标C");
	s.printAddr ();
	Human* ph = &s; // 向上造型
	ph->eat ("A");
	ph->sleep (100);
	Human h ("马如忠", 20);
	Teacher& rt = static_cast<Teacher&> (h);
	// 危险的向下造型
	rt.who ();
	Student* ps = static_cast<Student*> (ph);
	// 安全的向下造型
	ps->who ();
	return 0;
}
