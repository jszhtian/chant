
#include <cstdio>
#include <vector>

int wmain(int argc, wchar_t **argv)
{
	if (argc != 2)
	{
		return 0;
	}

	FILE *f = _wfopen(argv[1], L"rb");
	fseek(f, 0, SEEK_END);
	int len = ftell(f) / 2;
	wchar_t *buf = new wchar_t[len];
	fseek(f, 0, SEEK_SET);
	fread(buf, 2, len, f);
	fclose(f);

	std::vector<wchar_t> pool;
	for (int i = 0; i < len; ++i)
	{
		if (buf[i] >= 0xD800 && buf[i] <= 0xDFFF)
		{
			continue;
		}
		if (std::find(pool.begin(), pool.end(), buf[i]) == pool.end())
		{
			pool.push_back(buf[i]);
		}
	}

	delete[] buf;

	f = _wfopen(L"table.bin", L"wb");
	fwrite(pool.data(), 2, pool.size(), f);
	fclose(f);

	return 0;
}