#include <iostream>
#include <vector>
#include <numeric>

/**
	@brief PS10844 ���� ��ܼ� ���� https://www.acmicpc.net/problem/10844
	@details
	d[n]�� ���� ��, �ܼ��� �ϳ� Ȥ�� �� ���� ���̽��� �ִ� ���� �ƴϰ�,
	������ �־�����Ȳ�� ���� ���� ���̽��� ���� �� ����.
	�� ��쿣, d[n]�� ���ϴ� �������� 0~9���� 10���� ���̽��� ��� �����ؼ� �� ���ؾ���.

	����, ����� ū ���� �ٷ�� ������ �߰� �߰� ������ �䱸�Ѵ�� MOD�� �������.
	����, ���������� �Ѵٸ� �����÷ο쿡 ���Ͽ� �߸��� ���� ���� �� ����.
	�߰��߰��� MOD�� �ص� ����� ���� ������, �����÷ο찡 ���ٰ� ������ �ÿ�
	5 + 9 % 10��
	(5 % 10 + 9 % 10) % 10�� �����ϱ� ������
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