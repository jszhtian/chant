
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <io.h>
#include <fcntl.h>

class chant
{
	wchar_t *table;
	int tbl_len;

	const wchar_t tn_0 = 0;     // on tail, 0 byte is null
	const wchar_t tn_1 = L'也'; // on tail, 1 byte is null
	const wchar_t tn_2 = L'哉'; // on tail, 2 byte is null

	std::vector<wchar_t> enc(const void *s, const int l)
	{
		std::vector<wchar_t> ret;
		char *tmp = new char[l + 3];
		memcpy(tmp, s, l);

		for (int i = 0; i < l; i += 3)
		{
			int v = *(int *)(tmp + i) & 0x00FFFFFF;
			int v1 = (v & 0x00FFF000) >> 12;
			int v2 = v & 0x00000FFF;
			ret.push_back(table[v1]);
			ret.push_back(table[v2]);
		}

		switch (l % 3)
		{
		case 1:
			ret.push_back(tn_2);
			break;
		case 2:
			ret.push_back(tn_1);
			break;
		}

		return ret;
	}
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
	std::wstring encode(const std::string str)
	{
		auto e = enc(str.c_str(), str.size());
		return std::wstring(e.begin(), e.end());
	}
	std::wstring decode(const std::wstring str);
};

int wmain(int argc, wchar_t **argv)
{
	_setmode(_fileno(stdout), _O_U16TEXT);

	//
	chant ch(L"table.bin");

	char buf[2000];

	while (1)
	{
		fgets(buf, 2000, stdin);
		auto ws = ch.encode(buf);
		wprintf(L"%s\n", ws.c_str());
	}

	return 0;
}