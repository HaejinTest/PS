#include <iostream>
#include <cstring>

/**
	@brief PS11726 2×n 타일링 : https://www.acmicpc.net/problem/11726
	@details
	DP 문제, 직접 사각형 타일을 그려보는 게 중요하다.
	문제를 틀린 이유는
	1) % 10007을 마지막 값에 해서 : 오버플로우 발생
	2) 헤더를 string을 사용해서(cstring으로 정확히 해줘야함)
*/

namespace ps11726
{
	int gMemo[1001];

	int PSRecursively(int num)
	{
		if (gMemo[num] == -1)
		{
			gMemo[num] = (PSRecursively(num - 1) + PSRecursively(num - 2)) % 10007;

			return gMemo[num];
		}

		return gMemo[num];
	}

	/*int main()
	{
		std::ios_base::sync_with_stdio(false);
		memset(gMemo, -1, sizeof gMemo);

		int num;
		std::cin >> num;

		gMemo[1] = 1;
		gMemo[2] = 2;

		int result = PSRecursively(num);

		std::cout << result << std::endl;
	}*/
}