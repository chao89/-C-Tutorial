#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;
int main (void) {
	fstream fs ("seek.txt", ios::in | ios::out);
	if (! fs) {
		perror ("fstream::fstream");
		return -1;
	}
	fs << "0123456789";
	cout << fs.tellp () << endl; // 10
	cout << fs.tellg () << endl; // 0/10
	fs.seekg (-3, ios::end);
	int x;
	fs >> x;
	cout << x << endl; // 789
	fs.seekg (-5, ios::cur);
	x = 0;
	fs >> x;
	cout << x << endl;
	fs.clear (); // 清除流状态标志
	fs.seekp (2, ios::beg);
	cout << fs.tellp () << endl; // 2
	fs << "ABC";
	cout << fs.tellp () << endl; // 5
	fs.seekg (ios::beg); // 将读指针设置在文件头
	fs >> x;
	cout << fs.tellg () << endl; // 2
	cout << x << endl; // 1
	fs.seekg (ios::beg);
	string s;
	fs >> s;
	fs.clear (); // 当读到文件尾时，流状态为EOF，如
	             // 不清除该状态标志，无法获取读位置
	cout << boolalpha << fs.eof () << endl; // false
	cout << fs.good () << endl; // true
	cout << fs.tellg () << ' '
		<< fs.tellp () << endl; // 10 10
	cout << s << endl; // 01ABC56789
	fs.close ();
	return 0;
}
