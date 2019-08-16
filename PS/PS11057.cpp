#include <iostream>

/**
	@brief PS11057 오르막 수 https://www.acmicpc.net/problem/11057
	@details
	이번 문제는 그닥 어렵지는 않았음.
	그러나 DP의 항목을 공부하면서 나온 문제이므로
	DP를 고려한 풀이를 가장 먼저 했기 때문에 그럴 수 있음.
	DP는 
	1) Overlapping Subproblem : 큰 문제의 풀이와 작은 문제의 풀이가 동일함. 문제를 작은 문제로 쪼갤 수 있음.
	2) Optimal Substructure임 : 큰 문제의 정답은 작은 문제의 정답에서 구할 수 있음.
*/
namespace ps11057
{
	constexpr int MIN_N = 1;
	constexpr int MAX_N = 1000;
	constexpr int MOD = 10007;
	constexpr int DIGIT = 10;
	int gMemo[MAX_N + 1][DIGIT];

	int main(void)
	{
		std::ios_base::sync_with_stdio(false);

		for (int index = 0; index < DIGIT; index++)
		{
			gMemo[1][index] = 1;
		}

		int num;
		std::cin >> num;

		for (int n = 2; n <= num; n++)
		{
			for (int index = 0; index < DIGIT; index++)
			{
				gMemo[n][index] = 0;

				for (int count = 0; count <= index; count++)
				{
					gMemo[n][index] += gMemo[n - 1][count];
				}

				gMemo[n][index] %= MOD;
			}
		}

		int result = 0;

		for (int index = 0; index < DIGIT; index++)
		{
			result = (result + gMemo[num][index]) % MOD;
		}

		std::cout << result << std::endl;

		return 0;
	}
}