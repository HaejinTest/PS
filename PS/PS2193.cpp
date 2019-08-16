#include <iostream>
#include <cassert>
#include <cstring>
#include <numeric>

/**
	@brief PS2193 ��ģ�� : https://www.acmicpc.net/problem/2193  
	@details
	�������� �𸣰�����, �Ǻ���ġ ������ ����
	���� Ư�� ���� �Ѿ�� int�� ũ�⸦ �Ѿ
	�Ǻ���ġ�� �뷫 50�� ���ķ� 100���� �Ѿ ����
	int�� �ٷ� �� �ִ� -21~21���� �ѱ�
	��, ����� ���� �����ϴ� Memo�迭�� int�� �ƴ϶� int64_t
*/
namespace ps2193
{
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
}
