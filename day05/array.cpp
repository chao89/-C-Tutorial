#include <iostream>
using namespace std;
class Array {
public:
	int& operator[] (size_t i) {
		return m_array[i];
	}
	int const& operator[] (size_t i) const {
//		return m_array[i];
		return const_cast<Array&> (*this)[i];
	}
private:
	int m_array[5];
};
void print (Array const& array) {
	for (size_t i = 0; i < 5; ++i)
		cout << array[i] << ' ';
//		cout << array.operator[] (i) << ' ';
	cout << endl;
}
int main (void) {
	Array array;
	array[0] = 10; // array.operator[] (0) = 10;
	array[1] = 20;
	array[2] = 30;
	array[3] = 40;
	array[4] = 50;
	print (array);
	return 0;
}
