#include <errno.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
// 一般异常
class Exception {
public:
	Exception (string const& file,
		string const& function, int line,
		string const& desc) :
		m_file (file), m_function (function),
		m_line (line), m_desc (desc) {}
	friend ostream& operator<< (ostream& os,
		Exception const& ex) {
		return os << "在" << ex.m_file << "文件的第"
			<< ex.m_line << "行的" << ex.m_function
			<< "函数中发生异常：" << ex.m_desc;
	}
private:
	string m_file;
	string m_function;
	int    m_line;
	string m_desc;
};
// 文件异常
class FileException : public Exception {
public:
	FileException (string const& file,
		string const& function, int line,
		string const& desc) :
		Exception (file, function, line, desc) {}
};
// 内存异常
class MemoryException : public Exception {
public:
	MemoryException (string const& file,
		string const& function, int line,
		string const& desc) :
		Exception (file, function, line, desc) {}
};
// 除零异常
class DivByZeroException : public Exception {
public:
	DivByZeroException (string const& file,
		string const& function, int line,
		string const& desc) :
		Exception (file, function, line, desc) {}
};
class A {
public:
	A (void) : m_p (new char[1024]) {
		strcpy (m_p, "Hello, Exception !");
	}
	~A (void) {
		delete[] m_p;
	}
	char* m_p;
};
int foo (string const& file, string const& size,
	int x, int y) {
	FILE* fp = fopen (file.c_str (), "r");
	if (! fp)
		throw FileException (__FILE__, __FUNCTION__,
			__LINE__, strerror (errno));
	// ...
	fclose (fp);
	size_t bytes;
	sscanf (size.c_str (), "%x", &bytes);
	void* pv = malloc (bytes);
	if (! pv)
		throw MemoryException (__FILE__,
			__FUNCTION__, __LINE__,
			strerror (errno));
	// ...
	free (pv);
	if (! y)
		throw DivByZeroException (__FILE__,
			__FUNCTION__, __LINE__, "被除数为0");
	if (! x)
		throw Exception (__FILE__, __FUNCTION__,
			__LINE__, "除数为0");
//	throw A ();
	return x / y;
}
int main (int argc, char* argv[]) {
	if (argc < 5) {
		cout << "用法：" << argv[0] << " <文件名> "
			"<字节数> <除数> <被除数>" << endl;
		return -1;
	}
	try {
		foo (argv[1], argv[2], atoi (argv[3]),
			atoi (argv[4]));
	}
	catch (FileException& ex) {
		cout << ex << endl;
		cout << "针对文件异常的处理..." << endl;
		return -1;
	}
	catch (MemoryException& ex) {
		cout << ex << endl;
		cout << "针对内存异常的处理..." << endl;
		return -1;
	}
	catch (DivByZeroException& ex) {
		cout << ex << endl;
		cout << "针对除零异常的处理..." << endl;
		return -1;
	}
	catch (Exception& ex) {
		cout << ex << endl;
		cout << "针对一般异常的处理..." << endl;
		return -1;
	}
	catch (A& ex) {
		cout << ex.m_p << endl;
		return -1;
	}
	catch (...) {
		cout << "发生系统异常！" << endl;
		// 针对系统异常的处理...
		return -1;
	}
	cout << "成功！" << endl;
	return 0;
}
