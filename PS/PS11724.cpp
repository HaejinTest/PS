#include <iostream>
#include <vector>
#include <utility>

/**
	@brief PS11724 ���� ����� ���� : https://www.acmicpc.net/problem/11724
	@details
	�� ���� ������. ��?
	1) 
	���� ����� ������ ���ϴµ� �־ DFS�� ���� ������ ã�ƾ��ϴµ�
	DFS �߿� ã������ �߱� ������ �ߺ��� �����ϱ� �������
	2)
	u - v �� �ִٸ�, v - u �� ����� ��.
*/
namespace ps11724
{
	// 3��
	// 256MB
	constexpr int VERTEX_COUNT_MAX = 1000;
	constexpr int EDGE_COUNT_MAX = (VERTEX_COUNT_MAX * (VERTEX_COUNT_MAX - 1)) / 2;
	std::vector<int> gGraph[VERTEX_COUNT_MAX + 1];
	bool gbVisited[VERTEX_COUNT_MAX + 1];
	int gConnectedComponentCount = 0;

	void DFS(int start)
	{
		gbVisited[start] = true;

		size_t edgeSize = gGraph[start].size();

		for (int index = 0; index < edgeSize; index++)
		{
			int vertex = gGraph[start][index];

			if (gbVisited[vertex] == false)
			{
				DFS(vertex);
			}
		}
	}

	int main(void)
	{
		std::ios_base::sync_with_stdio(false);

		int vertexCount;
		int edgeCount;
		std::cin >> vertexCount >> edgeCount;

		int inputCount = edgeCount;

		while (inputCount--)
		{
			int vertex1;
			int vertex2;
			std::cin >> vertex1 >> vertex2;

			gGraph[vertex1].push_back(vertex2);
			gGraph[vertex2].push_back(vertex1);
		}

		for (int index = 1; index <= VERTEX_COUNT_MAX; index++)
		{
			gbVisited[index] = false;
		}

		for (int index = 1; index <= vertexCount; index++)
		{
			if (gbVisited[index] == false)
			{
				DFS(index);
				gConnectedComponentCount++;
			}
		}

		std::cout << gConnectedComponentCount << "\n";

		return 0;
	}
}
