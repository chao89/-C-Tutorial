#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
int main (void) {
//	int* pi = (int*)malloc (sizeof (int));
//	*pi = 100;
//	free (pi);
	int* pi = new int; // 不做初始化
	*pi = 100;
	cout << pi << ' ' << *pi << endl;
	delete pi;
	pi = new int (); // 初始化为0
	cout << *pi << endl;
	delete pi;
	pi = new int (200); // 初始化为200
	cout << *pi << endl;
	delete pi;
//	pi = (int*)malloc (5 * sizeof (int));
//	free (pi);
	pi = new int[5];
	for (size_t i = 0; i < 5; ++i)
		pi[i] = i + 1;
	for (size_t i = 0; i < 5; ++i)
		cout << *(pi + i) << ' ';
	cout << endl;
	delete[] pi;
	pi = new int[5] {1, 2, 3, 4, 5};
	for (size_t i = 0; i < 5; ++i)
		cout << *(pi + i) << ' ';
	cout << endl;
	delete[] pi;
	pi = NULL;
	delete[] pi;
	int (*pa)[4] = new int[3][4];
	for (size_t i = 0; i < 3; ++i)
		for (size_t j = 0; j < 4; ++j)
			pa[i][j] = (i + 1) * 10 + j + 1;
	for (size_t i = 0; i < 3; ++i) {
		for (size_t j = 0; j < 4; ++j)
			cout << pa[i][j] << ' ';
		cout << endl;
	}
	delete[] pa;
	cout << "----------------" << endl;
	int (*pb)[3][4] = new int[2][3][4];
	for (size_t i = 0; i < 2; ++i)
		for (size_t j = 0; j < 3; ++j)
			for (size_t k = 0; k < 4; ++k)
				pb[i][j][k] = (i+1)*100+(j+1)*10+
					(k+1);
	for (size_t i = 0; i < 2; ++i) {
		for (size_t j = 0; j < 3; ++j) {
			for (size_t k = 0; k < 4; ++k)
				cout << pb[i][j][k] << ' ';
			cout << endl;
		}
		cout << endl;
	}
	delete[] pb;
	if (! (pi = (int*)malloc (0xFFFFFFFF)))
		perror ("malloc");
	try {
		pi = new int[0xFFFFFFFF];
		// ...
		delete[] pi;
	}
	catch (exception& ex) {
		cout << ex.what () << endl;
		perror ("new");
	}
	return 0;
}
