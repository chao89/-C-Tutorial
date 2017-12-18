#include <iostream>
#include "net1.h"
void network::send (void* pack, size_t size) {
	std::cout << "通过网络发送" << size << "字节"
		<< "的数据包..." << std::endl;
}
