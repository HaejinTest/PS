#include <iostream>
#include <cstring>

constexpr int MAX_NUM = 1000;
int gMemo[MAX_NUM + 1];
int gA[MAX_NUM + 1];

auto Max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int main(void)
{
	int num;

	std::cin >> num;

	int count = num;
	int index = 1;

	while (count--)
	{
		int val;
		std::cin >> val;
		gA[index++] = val;
	}

	for (int count = 1; count <= num; count++)
	{
		gMemo[count] = 1;
	}

	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (gA[j] < gA[i] && gMemo[i] < gMemo[j] + 1)
			{
				gMemo[i] = gMemo[j] + 1;
			}
		}
	}

	int max = gMemo[1];

	for (int i = 1; i <= num; i++)
	{
		if (gMemo[i] > max)
		{
			max = gMemo[i];
		}
	}

	std::cout << max << std::endl;
}