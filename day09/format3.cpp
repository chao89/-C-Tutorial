#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;
int main (void) {
	ofstream ofs ("format3.txt");
	if (! ofs) {
		perror ("ofstream::ofstream");
		return -1;
	}
	ofs << 1234 << ' ' << 56.78 << ' ' << "apples"
		<< endl;
	ofs.close ();
	ifstream ifs ("format3.txt");
	if (! ifs) {
		perror ("ifstream::ifstream");
		return -1;
	}
	int i;
	double d;
	string s;
	ifs >> i >> d >> s;
	cout << i << ' ' << d << ' ' << s << endl;
	ifs.close ();
	return 0;
}
