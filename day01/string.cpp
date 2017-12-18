#include <iostream>
#include <cstring>
using namespace std;
int main (void) {
	string s1 = "abcd", s2 = "12345678";
	cout << s1 << ' ' << s2 << endl;
	// 赋值运算
	s1 = s2;
	cout << s1 << ' ' << s2 << endl;
	// 关系运算
	string s3 = "hello";
	cout << boolalpha << (s1 == s2) << endl;
	cout << (s3 > s2) << endl;
	// 算术运算
	s2 = s3 + s1;
	cout << s2 << endl;
	// 复合赋值运算
	s3 += s1;
	cout << s3 << endl;
	// 下标运算
	s3[1] = 'E';
	cout << s3 << endl;
	cout << s3.length () << endl;
	cout << s3.size () << endl;
	cout << s1.length () << endl;
	cout << s1.size () << endl;
	cout << sizeof (s3) << endl;
	cout << sizeof (s1) << endl;
	cout << strlen (s1.c_str ()) << endl;
	char const* p = "达内科技";
	string s5 = p; // C串隐式转换为C++串
	cout << s5 << endl;
	return 0;
}
