#include <iostream>
#include <vector>

/**
	@brief PS11725 트리의 부모 찾기 : https://www.acmicpc.net/problem/11725
	@details
	한 번에 못풀었음.
	왜?
	시간초과가 났기 때문에.
	왜?
	std::endl를 사용하여
	사실 여태까지 별거 아니라고 생각했는데, 매번 flush를 해주는 일이 생각보다 비용이 엄청나군
	앞으론 \n로 통일
*/
namespace ps11725
{
	constexpr int MAX_NUM = 100001;

	std::vector<int> gTree[MAX_NUM];
	int gParent[MAX_NUM];
	bool bVisited[MAX_NUM];

	void DFS(int start)
	{
		bVisited[start] = true;
		auto size = gTree[start].size();

		for (int index = 0; index < size; index++)
		{
			auto node = gTree[start][index];

			if (bVisited[node] == false)
			{
				gParent[node] = start;
				DFS(node);
			}
		}
	}

	int main(void)
	{
		std::ios_base::sync_with_stdio(false);

		int num;
		std::cin >> num;

		int count = num - 1;

		while (count--)
		{
			int vertex1;
			int vertex2;

			std::cin >> vertex1 >> vertex2;
			gTree[vertex1].push_back(vertex2);
			gTree[vertex2].push_back(vertex1);
		}

		DFS(1);

		for (int index = 2; index <= num; index++)
		{
			std::cout << gParent[index] << "\n";
		}

		return 0;
	}
}
