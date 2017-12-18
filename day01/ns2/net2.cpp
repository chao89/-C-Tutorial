#include <iostream>
#include "net2.h"
void network::recv (void* pack, size_t size) {
	std::cout << "通过网络接收" << size << "字节"
		<< "的数据包..." << std::endl;
}
