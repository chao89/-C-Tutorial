#include <cmath>
#include <iostream>
#include <iomanip> // 带有参数的流控制符
using namespace std;
ostream& red (ostream& os) {
	return os << "\033[;;31m";
}
ostream& def (ostream& os) {
	return os << "\033[0m";
}
int main (void) {
	cout << sqrt (200) << endl;
	/*
	cout.precision (10); // 取10位有效数字精度
	cout << sqrt (200) << endl;
	*/
	cout << setprecision (10) << sqrt (200) << endl;
	/*
	cout.setf (ios::scientific, ios::floatfield);
	cout << sqrt (200) << endl;
	*/
	cout << scientific << sqrt (200) << endl;
	cout << '[';
	/*
	cout.width (10); // 10字符域宽
	cout.fill ('-'); // 用'-'填充空白
	cout.setf (ios::showpos); // 显示正号
	cout.setf (ios::internal, ios::adjustfield);
	// 设置内插对齐
	cout << 12345;
	*/
	cout << setw (10) << setfill ('-') << showpos
		<< internal << 12345;
    cout << ']' << endl;
	cout << "我在" << red << "达内" << def
		<< "学习" << endl;
	return 0;
}
