#include "stdafx.h"
#include "CppUnitTest.h"

#include "../libbase/base4096.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace chanttest
{
	const uint16_t input[] = { 0x2d8, 0xf47, 0x5e9, 0x035, 0xfce, 0xc7c  };
	const int input_sz = sizeof(input) / 2;
	char output[300] = { 0 };
	const char answer[] = { 0x2d, 0x8f, 0x47, 0x5e, 0x90, 0x35, 0xfc, 0xec, 0x7c, 0x00 };
	const int answer_sz = 9;

	TEST_CLASS(BASE_4K_DEC)
	{
	public:
		TEST_METHOD(Invalid1)
		{
			memset(output, 0, sizeof(output));
			const uint16_t inputA[] = { 0xf001, 0x022, 0x8cd };
			int len = base4096_decode(inputA, 3, output, sizeof(output));
			const char ansA[] = { 0 };
			Assert::AreEqual(0, len, L"len");
			Assert::AreEqual(0, memcmp(ansA, output, 0), L"content");
		}
		TEST_METHOD(Invalid2)
		{
			memset(output, 0, sizeof(output));
			const uint16_t inputA[] = { 0xf002, 0x022, 0x8cd };
			int len = base4096_decode(inputA, 3, output, sizeof(output));
			const char ansA[] = { 0 };
			Assert::AreEqual(0, len, L"len");
			Assert::AreEqual(0, memcmp(ansA, output, 0), L"content");
		}
		TEST_METHOD(Invalid3)
		{
			memset(output, 0, sizeof(output));
			const uint16_t inputA[] = { 0x07ef, 0xf002, 0x022, 0x8cd };
			int len = base4096_decode(inputA, 4, output, sizeof(output));
			const char ansA[] = { 0 };
			Assert::AreEqual(0, len, L"len");
			Assert::AreEqual(0, memcmp(ansA, output, 0), L"content");
		}
		TEST_METHOD(CutC)
		{
			memset(output, 0, sizeof(output));
			const uint16_t inputA[] = { 0x07f2, 0x022, 0x8cd, 0x594, 0xf001 };
			int len = base4096_decode(inputA, 5, output, sizeof(output));
			const char ansA[] = { 0x7f, 0x20, 0x22, 0x8c, 0xd5 };
			Assert::AreEqual(5, len, L"len");
			Assert::AreEqual(0, memcmp(ansA, output, 5), L"content");
		}
		TEST_METHOD(CutB_0)
		{
			memset(output, 0, sizeof(output));
			const uint16_t inputA[] = { 0xe47, 0x022 };
			int len = base4096_decode(inputA, 2, output, 0);
			const char ansA[] = { 0xe4, 0x70, 0x22 };
			Assert::AreEqual(0, len, L"len");
			Assert::AreEqual(0, memcmp(ansA, output, 0), L"content");
		}
		TEST_METHOD(CutB_1)
		{
			memset(output, 0, sizeof(output));
			const uint16_t inputA[] = { 0xe47, 0x022 };
			int len = base4096_decode(inputA, 2, output, 1);
			const char ansA[] = { 0xe4, 0x70, 0x22 };
			Assert::AreEqual(1, len, L"len");
			Assert::AreEqual(0, memcmp(ansA, output, 1), L"content");
		}
		TEST_METHOD(CutB_2)
		{
			memset(output, 0, sizeof(output));
			const uint16_t inputA[] = { 0xe47, 0x022 };
			int len = base4096_decode(inputA, 2, output, 2);
			const char ansA[] = { 0xe4, 0x70, 0x22 };
			Assert::AreEqual(2, len, L"len");
			Assert::AreEqual(0, memcmp(ansA, output, 2), L"content");
		}
		TEST_METHOD(CutB_3)
		{
			memset(output, 0, sizeof(output));
			const uint16_t inputA[] = { 0xe47, 0x022 };
			int len = base4096_decode(inputA, 2, output, 3);
			const char ansA[] = { 0xe4, 0x70, 0x22 };
			Assert::AreEqual(3, len, L"len");
			Assert::AreEqual(0, memcmp(ansA, output, 3), L"content");
		}
		TEST_METHOD(CutB)
		{
			memset(output, 0, sizeof(output));
			const uint16_t inputA[] = { 0xe47, 0x022 };
			int len = base4096_decode(inputA, 2, output, sizeof(output));
			const char ansA[] = { 0xe4, 0x70, 0x22 };
			Assert::AreEqual(3, len, L"len");
			Assert::AreEqual(0, memcmp(ansA, output, sizeof(ansA)), L"content");
		}
		TEST_METHOD(CutA)
		{
			memset(output, 0, sizeof(output));
			const uint16_t inputA[] = { 0xe47 };
			int len = base4096_decode(inputA, 1, output, sizeof(output));
			const char ansA[] = { 0xe4 };
			Assert::AreEqual(1, len, L"len");
			Assert::AreEqual(0, memcmp(ansA, output, sizeof(ansA)), L"content");
		}
		TEST_METHOD(CutA_L)
		{
			memset(output, 0, sizeof(output));
			const uint16_t inputA[] = { 0xe47, 0x022, 0x8cd };
			int len = base4096_decode(inputA, 3, output, sizeof(output));
			const char ansA[] = { 0xe4, 0x70, 0x22, 0x8c };
			Assert::AreEqual(4, len, L"len");
			Assert::AreEqual(0, memcmp(ansA, output, sizeof(ansA)), L"content");
		}
		TEST_METHOD(Cut_0)
		{
			memset(output, 0, sizeof(output));
			int len = base4096_decode(input, input_sz, output, 0);
			Assert::AreEqual(0, len, L"len");
			Assert::AreEqual(0, memcmp(answer, output, 0), L"content");
		}
		TEST_METHOD(Cut_1)
		{
			memset(output, 0, sizeof(output));
			int len = base4096_decode(input, input_sz, output, 1);
			Assert::AreEqual(1, len, L"len");
			Assert::AreEqual(0, memcmp(answer, output, 1), L"content");
		}
		TEST_METHOD(Cut_2)
		{
			memset(output, 0, sizeof(output));
			int len = base4096_decode(input, input_sz, output, 2);
			Assert::AreEqual(2, len, L"len");
			Assert::AreEqual(0, memcmp(answer, output, 2), L"content");
		}
		TEST_METHOD(Cut_3)
		{
			memset(output, 0, sizeof(output));
			int len = base4096_decode(input, input_sz, output, 3);
			Assert::AreEqual(3, len, L"len");
			Assert::AreEqual(0, memcmp(answer, output, 3), L"content");
		}
		TEST_METHOD(Null)
		{
			Assert::AreEqual(0, base4096_decode(0, 0, 0, 0));
		}
		TEST_METHOD(Null_0)
		{
			Assert::AreEqual(0, base4096_decode(0, input_sz, output, sizeof(output)));
		}
		TEST_METHOD(Null_1)
		{
			Assert::AreEqual(0, base4096_decode(input, 0, output, sizeof(output)));
		}
		TEST_METHOD(Null_2)
		{
			Assert::AreEqual(0, base4096_decode(input, input_sz, 0, answer_sz));
		}
		TEST_METHOD(Null_3)
		{
			Assert::AreEqual(0, base4096_decode(input, input_sz, output, 0));
		}
		TEST_METHOD(Negative)
		{
			Assert::AreEqual(0, base4096_decode(input, -1, output, -1));
		}
		TEST_METHOD(Negative1)
		{
			Assert::AreEqual(0, base4096_decode(input, -1, output, sizeof(output)));
			Assert::AreEqual(0, base4096_decode(input, -2, output, sizeof(output)));
			Assert::AreEqual(0, base4096_decode(input, -175, output, sizeof(output)));
		}
		TEST_METHOD(Negative2)
		{
			Assert::AreEqual(0, base4096_decode(input, input_sz, output, -1));
			Assert::AreEqual(0, base4096_decode(input, input_sz, output, -2));
			Assert::AreEqual(0, base4096_decode(input, input_sz, output, -175));
		}
		TEST_METHOD(Full)
		{
			memset(output, 0, sizeof(output));
			int len = base4096_decode(input, input_sz, output, sizeof(output));
			Assert::AreEqual(answer_sz, len, L"len");
			Assert::AreEqual(answer, output, L"content");
		}
	};
}