#include <iostream>
#include <vector>
#include <numeric>

/**
	@brief PS10844 쉬운 계단수 문제 https://www.acmicpc.net/problem/10844
	@details
	d[n]을 구할 때, 단순히 하나 혹은 두 가지 케이스가 있는 것이 아니고,
	문제가 주어진상황에 따라 여러 케이스가 있을 수 있음.
	이 경우엔, d[n]을 구하는 과정에서 0~9까지 10가지 케이스를 모두 생각해서 다 더해야함.

	또한, 대단히 큰 수를 다루기 때문이 중간 중간 문제가 요구한대로 MOD를 해줘야함.
	만약, 마지막에만 한다면 오버플로우에 의하여 잘못된 값이 나올 수 있음.
	중간중간에 MOD를 해도 상관이 없는 이유는, 오버플로우가 없다고 가정할 시에
	5 + 9 % 10은
	(5 % 10 + 9 % 10) % 10과 동일하기 때문임
*/
namespace ps10844
{
	constexpr int MIN_N = 1;
	constexpr int MAX_N = 100;
	constexpr int64_t MOD = 1000000000;
	std::vector<std::vector<int64_t>> gMemo(MAX_N + 1, std::vector<int64_t>(10));

	int main(void)
	{
		for (int index = 1; index <= 9; index++)
		{
			gMemo[1][index] = 1;
		}

		int num;

		std::cin >> num;

		for (int n = 2; n <= num; n++)
		{
			for (int index = 0; index <= 9; index++)
			{
				gMemo[n][index] = 0;

				if (index == 0)
				{
					gMemo[n][index] += gMemo[n - 1][index + 1];
				}
				else if (index == 9)
				{
					gMemo[n][index] += gMemo[n - 1][index - 1];
				}
				else
				{
					gMemo[n][index] = gMemo[n - 1][index - 1] + gMemo[n - 1][index + 1];
				}

				gMemo[n][index] %= MOD;
			}
		}

		int64_t result = 0;

		for (int index = 0; index <= 9; index++)
		{
			result += gMemo[num][index];
			result %= MOD;
		}

		std::cout << result << std::endl;

		return 0;
	}
}