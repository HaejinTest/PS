#include <iostream>
#include <cassert>
#include <cstring>
#include <numeric>

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