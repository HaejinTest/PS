#include <iostream>
#include <vector>
#include <utility>

/**
	@brief PS11724 연결 요소의 개수 : https://www.acmicpc.net/problem/11724
	@details
	한 번에 못맞춤. 왜?
	1) 
	연결 요소의 개수를 구하는데 있어서 DFS가 끝난 다음에 찾아야하는데
	DFS 중에 찾으려고 했기 때문에 중복을 구별하기 어려웠음
	2)
	u - v 가 있다면, v - u 도 해줘야 함.
*/
namespace ps11724
{
	// 3초
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
