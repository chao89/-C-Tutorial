#include <iostream>
#include "zipdes.h"
void zip::zip (void* buf, size_t len) {
	std::cout << "压缩" << len << "字节的数据..."
		<< std::endl;
}
void zip::unzip (void* buf, size_t len) {
	std::cout << "解压" << len << "字节的数据..."
		<< std::endl;
}
void des::des (void* buf, size_t len) {
	std::cout << "加密" << len << "字节的数据..."
		<< std::endl;
}
void des::undes (void* buf, size_t len) {
	std::cout << "解密" << len << "字节的数据..."
		<< std::endl;
}
