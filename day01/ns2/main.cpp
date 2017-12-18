#include "net1.h"
#include "net2.h"
#include "zipdes.h"
int main (void) {
	unsigned char data[1024];
	// ...
	zip::zip (data, 1024);
	des::des (data, 512);
	network::send (data, 512);
	// ...
	network::recv (data, 512);
	des::undes (data, 512);
	zip::unzip (data, 1024);
	// ...
	return 0;
}
