
#ifndef __BASE4096_H__
#define __BASE4096_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

	int base4096_encode(const void *data, const int length, uint16_t *result, int bufSize);

#ifdef __cplusplus
}
#endif

#endif // !__BASE4096_H__
