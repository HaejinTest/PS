#include <iostream>

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