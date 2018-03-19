#include "stdafx.h"
#include "CppUnitTest.h"

#include "../chant/base4096.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace chanttest
{
	TEST_CLASS(BASE_4K_LOSS)
	{
	public:
		TEST_METHOD(LossLess0)
		{
			const char orig[] = { 0x00, 0x00, 0x35, 0xe8, 0x94, 0x26, 0xfe, 0x83, 0x00 };
			const int sz = 0;
			uint16_t pool[300];
			char targ[300];
			memset(targ, 0xCC, 300);
			int len1 = base4096_encode(orig, sz, pool, 300);
			int len2 = base4096_decode(pool, len1, targ, 300);
			Assert::AreEqual(sz, len2, L"len");
			Assert::AreEqual(0, memcmp(orig, targ, sz), L"content");
		}
		TEST_METHOD(LossLess1)
		{
			const char orig[] = { 0x00, 0x00, 0x35, 0xe8, 0x94, 0x26, 0xfe, 0x83, 0x00 };
			const int sz = 1;
			uint16_t pool[300];
			char targ[300];
			memset(targ, 0xCC, 300);
			int len1 = base4096_encode(orig, sz, pool, 300);
			int len2 = base4096_decode(pool, len1, targ, 300);
			Assert::AreEqual(sz, len2, L"len");
			Assert::AreEqual(0, memcmp(orig, targ, sz), L"content");
		}
		TEST_METHOD(LossLess2)
		{
			const char orig[] = { 0x00, 0x00, 0x35, 0xe8, 0x94, 0x26, 0xfe, 0x83, 0x00 };
			const int sz = 2;
			uint16_t pool[300];
			char targ[300];
			memset(targ, 0xCC, 300);
			int len1 = base4096_encode(orig, sz, pool, 300);
			int len2 = base4096_decode(pool, len1, targ, 300);
			Assert::AreEqual(sz, len2, L"len");
			Assert::AreEqual(0, memcmp(orig, targ, sz), L"content");
		}
		TEST_METHOD(LossLess3)
		{
			const char orig[] = { 0x00, 0x00, 0x35, 0xe8, 0x94, 0x26, 0xfe, 0x83, 0x00 };
			const int sz = 3;
			uint16_t pool[300];
			char targ[300];
			memset(targ, 0xCC, 300);
			int len1 = base4096_encode(orig, sz, pool, 300);
			int len2 = base4096_decode(pool, len1, targ, 300);
			Assert::AreEqual(sz, len2, L"len");
			Assert::AreEqual(0, memcmp(orig, targ, sz), L"content");
		}
		TEST_METHOD(LossLess4)
		{
			const char orig[] = { 0x00, 0x00, 0x35, 0xe8, 0x94, 0x26, 0xfe, 0x83, 0x00 };
			const int sz = 4;
			uint16_t pool[300];
			char targ[300];
			memset(targ, 0xCC, 300);
			int len1 = base4096_encode(orig, sz, pool, 300);
			int len2 = base4096_decode(pool, len1, targ, 300);
			Assert::AreEqual(sz, len2, L"len");
			Assert::AreEqual(0, memcmp(orig, targ, sz), L"content");
		}
		TEST_METHOD(LossLess5)
		{
			const char orig[] = { 0x00, 0x00, 0x35, 0xe8, 0x94, 0x26, 0xfe, 0x83, 0x00 };
			const int sz = 5;
			uint16_t pool[300];
			char targ[300];
			memset(targ, 0xCC, 300);
			int len1 = base4096_encode(orig, sz, pool, 300);
			int len2 = base4096_decode(pool, len1, targ, 300);
			Assert::AreEqual(sz, len2, L"len");
			Assert::AreEqual(0, memcmp(orig, targ, sz), L"content");
		}
		TEST_METHOD(LossLess6)
		{
			const char orig[] = { 0x00, 0x00, 0x35, 0xe8, 0x94, 0x26, 0xfe, 0x83, 0x00 };
			const int sz = 6;
			uint16_t pool[300];
			char targ[300];
			memset(targ, 0xCC, 300);
			int len1 = base4096_encode(orig, sz, pool, 300);
			int len2 = base4096_decode(pool, len1, targ, 300);
			Assert::AreEqual(sz, len2, L"len");
			Assert::AreEqual(0, memcmp(orig, targ, sz), L"content");
		}
		TEST_METHOD(LossLess7)
		{
			const char orig[] = { 0x00, 0x00, 0x35, 0xe8, 0x94, 0x26, 0xfe, 0x83, 0x00 };
			const int sz = 7;
			uint16_t pool[300];
			char targ[300];
			memset(targ, 0xCC, 300);
			int len1 = base4096_encode(orig, sz, pool, 300);
			int len2 = base4096_decode(pool, len1, targ, 300);
			Assert::AreEqual(sz, len2, L"len");
			Assert::AreEqual(0, memcmp(orig, targ, sz), L"content");
		}
		TEST_METHOD(LossLess8)
		{
			const char orig[] = { 0x00, 0x00, 0x35, 0xe8, 0x94, 0x26, 0xfe, 0x83, 0x00 };
			const int sz = 8;
			uint16_t pool[300];
			char targ[300];
			memset(targ, 0xCC, 300);
			int len1 = base4096_encode(orig, sz, pool, 300);
			int len2 = base4096_decode(pool, len1, targ, 300);
			Assert::AreEqual(sz, len2, L"len");
			Assert::AreEqual(0, memcmp(orig, targ, sz), L"content");
		}
		TEST_METHOD(LossLess9)
		{
			const char orig[] = { 0x00, 0x00, 0x35, 0xe8, 0x94, 0x26, 0xfe, 0x83, 0x00 };
			const int sz = 9;
			uint16_t pool[300];
			char targ[300];
			memset(targ, 0xCC, 300);
			int len1 = base4096_encode(orig, sz, pool, 300);
			int len2 = base4096_decode(pool, len1, targ, 300);
			Assert::AreEqual(sz, len2, L"len");
			Assert::AreEqual(0, memcmp(orig, targ, sz), L"content");
		}
	};
}