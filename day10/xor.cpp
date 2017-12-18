#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
size_t const BLOCK_SIZE = 1024;
// src ^ key -> dst
int _xor (char const* src, char const* dst,
	unsigned char key) {
	ifstream ifs (src, ios::binary);
	if (! ifs) {
		cout << "源文件打开失败！" << endl;
		return -1;
	}
	ofstream ofs (dst, ios::binary);
	if (! ofs) {
		cout << "目标文件打开失败！" << endl;
		ifs.close ();
		return -1;
	}
	char block[BLOCK_SIZE];
	while (ifs.read (block, BLOCK_SIZE)) {
		for (size_t i = 0; i < BLOCK_SIZE; ++i)
			block[i] ^= key;
		if (! ofs.write (block, BLOCK_SIZE)) {
			cout << "写入目标文件失败！" << endl;
			ofs.close ();
			ifs.close ();
			return -1;
		}
	}
	if (! ifs.eof ()) {
		cout << "读取源文件失败！" << endl;
		ofs.close ();
		ifs.close ();
		return -1;
	}
	for (size_t i = 0; i < ifs.gcount (); ++i)
		block[i] ^= key;
	if (! ofs.write (block, ifs.gcount ())) {
		cout << "写入目标文件失败！" << endl;
		ofs.close ();
		ifs.close ();
		return -1;
	}
	ofs.close ();
	ifs.close ();
	return 0;
}
int enc (char const* plain, char const* cipher) {
	srand (time (NULL));
	unsigned char key = rand () % 256;
	if (_xor (plain, cipher, key) == -1)
		return -1;
	cout << "密钥：" << (unsigned int)key << endl;
	return 0;
}
int dec (char const* cipher, char const* plain,
	unsigned char key) {
	return _xor (cipher, plain, key);
}
int main (int argc, char* argv[]) {
	if (argc < 3) {
		cout << "加密：" << argv[0]
			<< " <明文> <密文>" << endl;
		cout << "解密：" << argv[0]
			<< " <密文> <明文> <密钥>" << endl;
		return -1;
	}
	if (argc < 4)
		return enc (argv[1], argv[2]);
	else
		return dec (argv[1], argv[2],
			atoi (argv[3]));
	return 0;
}
