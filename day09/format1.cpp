#include <cmath>
#include <iostream>
using namespace std;
int main (void) {
	cout << sqrt (200) << endl;
	cout.precision (10); // 取10位有效数字精度
	cout << sqrt (200) << endl;
	cout.setf (ios::scientific, ios::floatfield);
	cout << sqrt (200) << endl;
	cout << '[';
	cout.width (10); // 10字符域宽
	cout.fill ('-'); // 用'-'填充空白
	cout.setf (ios::showpos); // 显示正号
	cout.setf (ios::internal, ios::adjustfield);
	// 设置内插对齐
	cout << 12345;
    cout << ']' << endl;
	return 0;
}
