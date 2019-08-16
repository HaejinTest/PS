#include <iostream>
#include <cassert>
#include <cstring>
#include <numeric>

/**
	@brief PS2193 이친수 : https://www.acmicpc.net/problem/2193  
	@details
	왜인지는 모르겠지만, 피보나치 수열과 동일
	따라서 특정 수를 넘어가면 int의 크기를 넘어감
	피보나치는 대략 50쯤 전후로 100억을 넘어감 따라서
	int가 다룰 수 있는 -21~21억을 넘김
	즉, 경우의 수를 저장하는 Memo배열에 int가 아니라 int64_t
*/
namespace ps2193
{
	constexpr int MIN_N = 1;
	constexpr int MAX_N = 90;

	int64_t gMemo[MAX_N + 1];

	auto PSRecursively(int num)
	{
		if (num == 1 || num == 2)
		{
			return gMemo[num];
		}

		if (gMemo[num] == -1)
		{
			gMemo[num] = PSRecursively(num - 1) + PSRecursively(num - 2);
		}

		return gMemo[num];
	}

	int main(void)
	{
		int num;

		std::cin >> num;

		if (std::cin.fail())
		{
			assert(0 && L"Invalid Number");

			return 0;
		}

		memset(gMemo, -1, sizeof gMemo);
		gMemo[1] = 1;
		gMemo[2] = 1;
		std::cout << PSRecursively(num) << std::endl;
	}
}
