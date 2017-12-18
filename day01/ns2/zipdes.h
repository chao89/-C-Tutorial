#ifndef _ZIPDES_H
#define _ZIPDES_H
#include <sys/types.h>
namespace zip {
	void zip (void* buf, size_t len);
	void unzip (void* buf, size_t len);
}
namespace des {
	void des (void* buf, size_t len);
	void undes (void* buf, size_t len);
}
#endif // _ZIPDES_H
