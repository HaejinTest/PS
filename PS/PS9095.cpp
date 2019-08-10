#include <iostream>
#include <cstring>

namespace ps9095
{
	/**
		@brief PS9095 1,2,3 더하기 https://www.acmicpc.net/problem/9095
		@details
		d[n]을 구할 때 케이스를 잘 생각할것.
		예를 들어,
		1+2 = 3
		2+1 = 3
		문제에 따라 이 두 가지를 다르게 보는 경우도 있고 같게 보는 경우도 있는데 주의
	*/

	constexpr int MAX_N = 10;
	int gMemo[MAX_N + 1];

	int PSRecursively(int num)
	{
		if (num == 1 || num == 2 || num == 3)
		{
			return gMemo[num];
		}

		if (gMemo[num] == -1)
		{
			gMemo[num] = PSRecursively(num - 1) + PSRecursively(num - 2) + PSRecursively(num - 3);
		}

		return gMemo[num];
	}

	int main()
	{
		int testCase;

		std::cin >> testCase;
		std::memset(gMemo, -1, sizeof gMemo);

		gMemo[1] = 1;
		gMemo[2] = 2;
		gMemo[3] = 4;

		while (testCase--)
		{
			int num;
			std::cin >> num;

			int result = PSRecursively(num);

			std::cout << result << std::endl;
		}

		return 0;
	}
}