#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
class File {
public:
	File (char const* path, char const* mode) :
		m_fp (fopen (path, mode)) {}
	~File (void) {
		if (m_fp)
			fclose (m_fp);
	}
	size_t write (char const* text) {
		return fwrite (text, sizeof (text[0]),
			strlen (text), m_fp);
	}
	char operator[] (size_t i) const {
		fseek (m_fp, i, SEEK_SET);
		char c;
		fread (&c, sizeof (c), 1, m_fp);
		return c;
	}
private:
	FILE* m_fp;
};
int main (void) {
	File file ("test.txt", "w+");
	file.write ("ABCDEFG");
	for (size_t i = 0; i < 7; ++i)
		cout << file[i] << endl;
	return 0;
}
