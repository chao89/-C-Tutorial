#include <iostream>
using namespace std;
class Square {
public:
	int operator() (int x) const {
		return x * x;
	}
	int operator() (int x, int y) const {
		return (*this) (x) + (*this) (y);
	}
};
int calc (int x, int y, int (*func) (int, int)) {
	return func (x, y);
}
int add (int x, int y) { return x + y; }
int sub (int x, int y) { return x - y; }
int mul (int x, int y) { return x * y; }
int div (int x, int y) { return x / y; }
int mod (int x, int y) { return x % y; }
class Calc {
public:
	Calc (char op) : m_op (op) {}
	int operator() (int x, int y) const {
		switch (m_op) {
			case '+': return x + y;
			case '-': return x - y;
			case '*': return x * y;
			case '/': return x / y;
			case '%': return x % y;
		}
	}
private:
	char m_op;
};
int calc (int x, int y, Calc const& cal) {
	return cal (x, y);
}
int main (void) {
	Square square; // 函数对象，仿函数，函数子
	cout << square (13) << endl; // 169
//	cout << square.operator() (13) << endl;
	cout << square (3, 4) << endl; // 25
//	cout << square.operator() (3, 4) << endl;
	cout << calc (8, 3, add) << endl;
	cout << calc (8, 3, sub) << endl;
	cout << calc (8, 3, mul) << endl;
	cout << calc (8, 3, div) << endl;
	cout << calc (8, 3, mod) << endl;
	cout << calc (8, 3, Calc ('+')) << endl;
	cout << calc (8, 3, Calc ('-')) << endl;
	cout << calc (8, 3, Calc ('*')) << endl;
	cout << calc (8, 3, Calc ('/')) << endl;
	cout << calc (8, 3, Calc ('%')) << endl;
	return 0;
}
