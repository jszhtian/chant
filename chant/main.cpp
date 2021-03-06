
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <io.h>
#include <fcntl.h>

#include "../libbase/base32.h"
#include "../libbase/base4096.h"

class chant
{
	wchar_t *table;
	int tbl_len;

	const wchar_t tn_0 = 0;     // on tail, 0 byte is null
	const wchar_t tn_1 = L'也'; // on tail, 1 byte is null
	const wchar_t tn_2 = L'哉'; // on tail, 2 byte is null

public:
	chant(const wchar_t *f)
	{
		FILE *fp = _wfopen(f, L"rb");
		fseek(fp, 0, SEEK_END);
		tbl_len = ftell(fp) / 2;
		fseek(fp, 0, SEEK_SET);

		table = new wchar_t[tbl_len];
		fread(table, 2, tbl_len, fp);
		fclose(fp);
	}
	~chant()
	{
		delete[] table;
	}
	wchar_t operator[] (const int i)
	{
		if (i == 0xF001)
		{
			return tn_1;
		}
		if (i == 0xF002)
		{
			return tn_2;
		}
		return table[i];
	}
};

int wmain(int argc, wchar_t **argv)
{
	_setmode(_fileno(stdout), _O_U16TEXT);

	chant ch(L"table.bin");

	char buf[2000];
	wchar_t rs[2000];
	char bin[2000];

	while (1)
	{
		fgets(buf, 2000, stdin);
		for (int i = 0; i < 2000; ++i)
		{
			if (buf[i] == 0x0d || buf[i] == 0x0a)
			{
				buf[i] = 0;
			}
		}

		int s = base32_decode((uint8_t*)buf, (uint8_t*)bin, 2000);
		int l = base4096_encode(bin, s, (uint16_t *)rs, 2000);

		for (int i = 0; i < l; ++i)
		{
			wprintf(L"%c", ch[rs[i]]);
		}
		wprintf(L"\n");
	}

	return 0;
}