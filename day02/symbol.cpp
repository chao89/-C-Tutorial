#include <iostream>
using namespace std;
/*
int main (void) {
	int a[] = {13, 21, 37, 49, 58};
	int b[] = {79, 63, 45, 31, 16};
	for (int i = 0; i < 5; ++i)
		cout << (a[i] & b[i]) +
			((a[i] ^ b[i]) >> 1) << ' ';
	cout << endl;
	return 0;
}
*/
int main (void) <%
	int a<::> = <%13, 21, 37, 49, 58%>;
	int b<::> = <%79, 63, 45, 31, 16%>;
	for (int i = 0; i < 5; ++i)
		cout << (a<:i:> bitand b<:i:>) +
			((a<:i:> xor b<:i:>) >> 1) << ' ';
	cout << endl;
	return 0;
%>
