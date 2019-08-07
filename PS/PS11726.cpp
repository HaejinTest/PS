#include <iostream>
#include <cstring>

/**
	@brief PS11726 2��n Ÿ�ϸ� : https://www.acmicpc.net/problem/11726
	@details
	DP ����, ���� �簢�� Ÿ���� �׷����� �� �߿��ϴ�.
	������ Ʋ�� ������
	1) % 10007�� ������ ���� �ؼ� : �����÷ο� �߻�
	2) ����� string�� ����ؼ�(cstring���� ��Ȯ�� �������)
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