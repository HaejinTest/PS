#include <iostream>

/**
	@brief PS11047 동전 0 : https://www.acmicpc.net/problem/11047
	@details
	// n 종류의 동전
	// 동전을 적절히 골라서 가치의 합을 K로
	// 이때 필요한 동전 개수의 최소값
	// 그리디로 풀수 있는 이유는
	// 코인의 가치가 A0....AN까지 배수이기 때문 2배수, 3배수 혹은 등등
	// 따라서 가장 가치가 큰 코인부터 하나씩 비교해서 제거하면됨.
*/
namespace ps11047
{
	constexpr int MAX_COIN_KIND = 10;
	int gCoinValue[MAX_COIN_KIND + 1];

	int main()
	{
		std::ios_base::sync_with_stdio(false);

		int N;
		int K;

		std::cin >> N >> K;

		for (int& e : gCoinValue)
		{
			e = -1;
		}

		for (int index = 1; index <= N; index++)
		{
			int val;
			std::cin >> val;
			gCoinValue[index] = val;
		}

		int coinSum = 0;

		while (K != 0)
		{
			int coinCount = 0;

			coinCount = K / gCoinValue[N];
			K -= coinCount * gCoinValue[N];
			N--;
			coinSum += coinCount;
		}

		std::cout << coinSum;

		return 0;
	}
}