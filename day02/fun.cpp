#include <iostream>
using namespace std;
extern "C" char fun (short h, int i) {
	cout << "fun(short,int)" << endl;
	return 'a';
}
/*extern "C" */void fun (float x, double y) {
	cout << "fun(float,double)" << endl;
}
