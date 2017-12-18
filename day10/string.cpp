#include <cstdio>
#include <iostream>
#include <sstream>
using namespace std;
int main (void) {
	int i = 1234;
	double d = 56.78;
	char c = 'T';
	char s[256] = "HELLO, WORLD !";
	/*
	char buf[1024];
	sprintf (buf, "%d %g %c %s", i, d, c, s);
	cout << buf << endl;
	*/
	ostringstream oss;
	oss << i << ' ' << d << ' ' << c << ' ' << s;
	string str = oss.str ();
	cout << str << endl;
	int a;
	double b;
	char x;
	char y[3][256];
//	istringstream iss (str);
	istringstream iss;
	iss.str (str);
	iss >> a >> b >> x >> y[0] >> y[1] >> y[2];
	cout << a << ',' << b << ',' << x << ',' << y[0]
		<< ' ' << y[1] << ' ' << y[2] << endl;
	iss.seekg (ios::beg);
	iss.str ("100 9.99 A XYZ");
	iss >> a >> b >> x >> y[0];
	cout << a << ',' << b << ',' << x << ',' << y[0]
		<< endl;
	return 0;
}
