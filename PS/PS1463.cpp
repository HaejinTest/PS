#include <iostream>
#include <cstring>

/**
	@brief https://www.acmicpc.net/problem/1463
	@details
	DP문제, 조건에 따라 두 가지 방향으로 나뉘며 두 가지 방향 모두 시도하여 작은 값을 선택하여 메모하면서 풀이
	첫 번째 시도에서 틀렸는데, 그 이유는 배열의 크기를 1백만으로 잡았기 때문, 왜냐? 마지막 1백만을 한다고 했을 때,
	gMemo[1000000]으로 접근하는데, gMemo[1000000]은 배열에 할당된 크기보다 인덱스가 하나 더 크기때문
	따라서 1000001만큼 할당해야함.
*/

char gMemo[1000001];

int Min(int a, int b)
{
	if (a >= b)
	{
		return b;
	}
	else
	{
		return a;
	}
}

int PSRecursively(int num)
{
	if (num == 1)
	{
		gMemo[num] = 0;

		return gMemo[num];
	}

	if (num == 2)
	{
		gMemo[num] = 1;

		return gMemo[num];
	}

	if (num == 3)
	{
		gMemo[num] = 1;

		return gMemo[num];
	}

	if ((num % 2) != 0 && (num % 3) != 0)
	{
		if (gMemo[num] != -1)
		{
			return gMemo[num];
		}

		gMemo[num] = PSRecursively(num - 1) + 1;

		return gMemo[num];
	}

	if (num % 3 == 0)
	{
		if (gMemo[num] != -1)
		{
			return gMemo[num];
		}

		int d1 = PSRecursively(num / 3) + 1;
		int d2 = PSRecursively(num - 1) + 1;
		gMemo[num] = Min(d1, d2);

		return gMemo[num];
	}

	if ((num % 2) == 0)
	{
		if (gMemo[num] != -1)
		{
			return gMemo[num];
		}

		int d1 = PSRecursively(num - 1) + 1;
		int d2 = PSRecursively(num / 2) + 1;
		gMemo[num] = Min(d1, d2);

		return gMemo[num];
	}

	// 모든 경우의 수를 다루었으므로 여기선 아무것도 return 하지 않음.
}

//int main()
//{
//	std::ios_base::sync_with_stdio(false);
//
//	int num;
//
//	std::cin >> num;
//	std::memset(gMemo, -1, sizeof gMemo);
//
//	int result = PSRecursively(num);
//
//	std::cout << result << std::endl;
//}