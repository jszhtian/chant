#include "stdafx.h"
#include "CppUnitTest.h"

#include "../chant/base4096.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace chanttest
{
	const char input[] = { 0x2d, 0x8f, 0x47, 0x5e, 0x90, 0x35, 0xfc, 0xec, 0x00 };
	const int input_sz = sizeof(input);
	wchar_t output[300] = { 0 };
	const wchar_t answer[] = { 0x2d8, 0xf47, 0x5e9, 0x035, 0xfce, 0xc00, 0 };
	const int answer_sz = wcslen(answer);

	TEST_CLASS(BASE_4K_ENC)
	{
	public:
		TEST_METHOD(CutD_0)
		{
			memset(output, 0, sizeof(output));
			const char inputA[] = { 0x2f, 0xec };
			int len = base4096_encode(inputA, sizeof(inputA), (uint16_t *)output, 0);
			const wchar_t ansA[] = { 0x2fe, 0xc00, 0xF001 };
			Assert::AreEqual(0, len, L"len");
			Assert::AreEqual(0, memcmp(ansA, output, 0), L"content");
		}
		TEST_METHOD(CutD_1)
		{
			memset(output, 0, sizeof(output));
			const char inputA[] = { 0x2f, 0xec };
			int len = base4096_encode(inputA, sizeof(inputA), (uint16_t *)output, 1);
			const wchar_t ansA[] = { 0x2fe, 0xc00, 0xF001 };
			Assert::AreEqual(1, len, L"len");
			Assert::AreEqual(0, memcmp(ansA, output, 2), L"content");
		}
		TEST_METHOD(CutD_2)
		{
			memset(output, 0, sizeof(output));
			const char inputA[] = { 0x2f, 0xec };
			int len = base4096_encode(inputA, sizeof(inputA), (uint16_t *)output, 2);
			const wchar_t ansA[] = { 0x2fe, 0xc00, 0xF001 };
			Assert::AreEqual(2, len, L"len");
			Assert::AreEqual(0, memcmp(ansA, output, 4), L"content");
		}
		TEST_METHOD(CutD_3)
		{
			memset(output, 0, sizeof(output));
			const char inputA[] = { 0x2f, 0xec };
			int len = base4096_encode(inputA, sizeof(inputA), (uint16_t *)output, 3);
			const wchar_t ansA[] = { 0x2fe, 0xc00, 0xF001 };
			Assert::AreEqual(3, len, L"len");
			Assert::AreEqual(0, memcmp(ansA, output, 6), L"content");
		}
		TEST_METHOD(CutD)
		{
			memset(output, 0, sizeof(output));
			const char inputA[] = { 0x2f, 0xec };
			int len = base4096_encode(inputA, sizeof(inputA), (uint16_t *)output, sizeof(output));
			const wchar_t ansA[] = { 0x2fe, 0xc00, 0xF001 };
			Assert::AreEqual(3, len, L"len");
			Assert::AreEqual(0, memcmp(ansA, output, sizeof(ansA)), L"content");
		}
		TEST_METHOD(CutC)
		{
			memset(output, 0, sizeof(output));
			const char inputA[] = { 0x00, 0x00, 0x00 };
			int len = base4096_encode(inputA, sizeof(inputA), (uint16_t *)output, sizeof(output));
			const wchar_t ansA[] = { 0x000, 0x000 };
			Assert::AreEqual(2, len, L"len");
			Assert::AreEqual(0, memcmp(ansA, output, sizeof(ansA)), L"content");
		}
		TEST_METHOD(CutB)
		{
			memset(output, 0, sizeof(output));
			const char inputA[] = { 0x00, 0x00 };
			int len = base4096_encode(inputA, sizeof(inputA), (uint16_t *)output, sizeof(output));
			const wchar_t ansA[] = { 0x000, 0x000, 0xF001 };
			Assert::AreEqual(3, len, L"len");
			Assert::AreEqual(0, memcmp(ansA, output, sizeof(ansA)), L"content");
		}
		TEST_METHOD(CutA)
		{
			memset(output, 0, sizeof(output));
			const char inputA[] = { 0x00 };
			int len = base4096_encode(inputA, sizeof(inputA), (uint16_t *)output, sizeof(output));
			const wchar_t ansA[] = { 0x000, 0xF002 };
			Assert::AreEqual(2, len, L"len");
			Assert::AreEqual(0, memcmp(ansA, output, sizeof(ansA)), L"content");
		}
		TEST_METHOD(Cut_0)
		{
			memset(output, 0, sizeof(output));
			int len = base4096_encode(input, input_sz, (uint16_t *)output, 0);
			const wchar_t ans0[] = { 0 };
			Assert::AreEqual(0, len, L"len");
			Assert::AreEqual(0, memcmp(ans0, output, sizeof(ans0)), L"content");
		}
		TEST_METHOD(Cut_1)
		{
			memset(output, 0, sizeof(output));
			int len = base4096_encode(input, input_sz, (uint16_t *)output, 1);
			const wchar_t ans0[] = { 0x2d8 };
			Assert::AreEqual(1, len, L"len");
			Assert::AreEqual(0, memcmp(ans0, output, sizeof(ans0)), L"content");
		}
		TEST_METHOD(Cut_2)
		{
			memset(output, 0, sizeof(output));
			int len = base4096_encode(input, input_sz, (uint16_t *)output, 2);
			const wchar_t ans0[] = { 0x2d8, 0xf47 };
			Assert::AreEqual(2, len, L"len");
			Assert::AreEqual(0, memcmp(ans0, output, sizeof(ans0)), L"content");
		}
		TEST_METHOD(Cut_3)
		{
			memset(output, 0, sizeof(output));
			int len = base4096_encode(input, input_sz, (uint16_t *)output, 3);
			const wchar_t ans0[] = { 0x2d8, 0xf47, 0x5e9 };
			Assert::AreEqual(3, len, L"len");
			Assert::AreEqual(0, memcmp(ans0, output, sizeof(ans0)), L"content");
		}
		TEST_METHOD(Null)
		{
			Assert::AreEqual(0, base4096_encode(0, 0, 0, 0));
		}
		TEST_METHOD(Null_0)
		{
			Assert::AreEqual(0, base4096_encode(0, input_sz, (uint16_t *)output, sizeof(output)));
		}
		TEST_METHOD(Null_1)
		{
			Assert::AreEqual(0, base4096_encode(input, 0, (uint16_t *)output, sizeof(output)));
		}
		TEST_METHOD(Null_2)
		{
			Assert::AreEqual(0, base4096_encode(input, input_sz, 0, answer_sz));
		}
		TEST_METHOD(Null_3)
		{
			Assert::AreEqual(0, base4096_encode(input, input_sz, (uint16_t *)output, 0));
		}
		TEST_METHOD(Negative)
		{
			Assert::AreEqual(0, base4096_encode(input, -1, (uint16_t *)output, -1));
		}
		TEST_METHOD(Negative1)
		{
			Assert::AreEqual(0, base4096_encode(input, -1, (uint16_t *)output, sizeof(output)));
			Assert::AreEqual(0, base4096_encode(input, -2, (uint16_t *)output, sizeof(output)));
			Assert::AreEqual(0, base4096_encode(input, -175, (uint16_t *)output, sizeof(output)));
		}
		TEST_METHOD(Negative2)
		{
			Assert::AreEqual(0, base4096_encode(input, input_sz, (uint16_t *)output, -1));
			Assert::AreEqual(0, base4096_encode(input, input_sz, (uint16_t *)output, -2));
			Assert::AreEqual(0, base4096_encode(input, input_sz, (uint16_t *)output, -175));
		}
		TEST_METHOD(Full)
		{
			memset(output, 0, sizeof(output));
			int len = base4096_encode(input, input_sz, (uint16_t *)output, sizeof(output));
			Assert::AreEqual(answer_sz, len, L"len");
			Assert::AreEqual(answer, output, L"content");
		}
	};
}