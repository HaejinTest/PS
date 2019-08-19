#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

/**
	@brief PS1260 DFS와 BFS : https://www.acmicpc.net/problem/1260
	@details
	보통의 DFS와 BFS처럼 보이는데 약간의 함정 카드가 있음.
	그것은 바로 DFS나 BFS를 할 때, 정점 번호가 작은 것부터 선택하는것.
	보통의 경우 무작위인데 이경우는 아니였던 것이다.
	즉, 인접리스트 안에서 오름차순으로 정렬을 해야함.
*/
namespace ps1260
{
	constexpr int VERTEX_MAX = 1000;
	std::vector<int> gGraph[VERTEX_MAX + 1];
	bool gbVisited[VERTEX_MAX + 1];

	void DFS(int start)
	{
		gbVisited[start] = true;
		std::cout << start << " ";

		int size = static_cast<int>(gGraph[start].size());

		for (int count = 0; count < size; count++)
		{
			int vertex = gGraph[start][count];

			if (gbVisited[vertex] == false)
			{
				DFS(vertex);
			}
		}
	}

	void BFS(int start)
	{
		std::queue<int> q;

		q.push(start);
		gbVisited[start] = true;

		while (q.empty() == false)
		{
			int vertex = q.front();
			q.pop();
			std::cout << vertex << " ";

			int size = static_cast<int>(gGraph[vertex].size());

			for (int count = 0; count < size; count++)
			{
				int node = gGraph[vertex][count];

				if (gbVisited[node] == false)
				{
					gbVisited[node] = true;
					q.push(node);
				}
			}
		}
	}

	// vertex 1~N
	int main(void)
	{
		std::ios_base::sync_with_stdio(false);

		int vertexCount;
		int edgeCount;
		int startVertex;

		std::cin >> vertexCount >> edgeCount >> startVertex;

		for (int count = 1; count < VERTEX_MAX + 1; count++)
		{
			gbVisited[count] = false;
		}

		for (int count = 0; count < edgeCount; count++)
		{
			int vertex1;
			int vertex2;

			std::cin >> vertex1 >> vertex2;

			gGraph[vertex1].push_back(vertex2);
			gGraph[vertex2].push_back(vertex1);
		}

		for (int count = 1; count < VERTEX_MAX + 1; count++)
		{
			std::sort(gGraph[count].begin(), gGraph[count].end());
		}

		// graph complete
		DFS(startVertex);

		std::cout << "\n";

		for (int count = 1; count < VERTEX_MAX + 1; count++)
		{
			gbVisited[count] = false;
		}

		BFS(startVertex);


		return 0;
	}
}