
#include <string.h>
#include <malloc.h>

#include "base4096.h"

int base4096_encode(const void *data, const int length,
	uint16_t *result, int bufSize)
{
	int i = 0;
	int j = 0;
	int ret = 0;

	uint8_t *tmp = 0;
	uint16_t *out = 0;

	int tail = length % 3;
	int size = (length + 2) / 3 * 2 + 1;

	if (bufSize <= 0 || length <= 0 || !data || !result)
	{
		goto done;
	}

	tmp = calloc(length + 2, 1);
	out = calloc(size, 2);

	if (!tmp || !out)
	{
		goto done;
	}

	memcpy(tmp, data, length);

	for (i = 0; i < length; i += 3)
	{
		out[j++] = tmp[i] << 4 | tmp[i + 1] >> 4;
		out[j++] = (tmp[i + 1] & 0x0F) << 8 | tmp[i + 2];
	}

	if (tail == 1)
	{
		out[j - 1] = 0xF002; // pad 2 when tail size 1
	}
	if (tail == 2)
	{
		out[j++] = 0xF001; // pad 1 when tail size 2
	}

	ret = bufSize > j ? j : bufSize;
	memcpy(result, out, ret * sizeof(uint16_t));

done:
	free(tmp);
	free(out);
	return ret;
}