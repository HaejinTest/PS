#include <iostream>
#include <vector>
#include <utility>
#include <queue>
// 2초
// 256MB

/**
	@brief PS1707 이분 그래프 : https://www.acmicpc.net/problem/1707
	다시풀어 왜?
	1) 잔 실수가 너무 많았다. <= 나 <  혹은 vertexCount vs edgeCount 집중력 최악
	2) 이분 그래프에 대한 이해 부족
	start를 1만 하면 안되고 다른 것도 해야함왜?
	A  -- E

	B  -- F

	C  -- G

	이것도 이분그래프거등
*/
namespace ps1707
{
	enum class eStatus
	{
		NonVisited = 0,
		Blue = 1,
		Red = 2
	};

	constexpr int VERTEX_MAX = 20000;
	std::vector<int> gGraph[VERTEX_MAX + 1];
	eStatus gVertexStatus[VERTEX_MAX + 1];
	bool gbVertexEqual = false;

	void ClearVertexStatus(eStatus* status, int max)
	{
		for (int count = 1; count < max; count++)
		{
			status[count] = eStatus::NonVisited;
		}
	}

	void DFS(int start, eStatus status)
	{
		if (gVertexStatus[start] != eStatus::NonVisited)
		{
			return;
		}

		gVertexStatus[start] = status;

		size_t size = gGraph[start].size();

		for (int count = 0; count < size; count++)
		{
			int vertex = gGraph[start][count];

			if (gVertexStatus[vertex] == eStatus::NonVisited)
			{
				if (gVertexStatus[start] == eStatus::Blue)
				{
					DFS(vertex, eStatus::Red);
				}
				else
				{
					DFS(vertex, eStatus::Blue);
				}
			}
			else
			{
				if (gVertexStatus[vertex] == gVertexStatus[start])
				{
					gbVertexEqual = true;

					return;
				}
			}
		}
	}

	int main(void)
	{
		int testCase;
		std::cin >> testCase;

		while (testCase--)
		{
			int vertexCount; // 1~20000, 1~v
			int edgeCount; // 1~200000

			std::cin >> vertexCount >> edgeCount;

			for (int count = 0; count < VERTEX_MAX + 1; count++)
			{
				gGraph[count].clear();
			}

			ClearVertexStatus(gVertexStatus, VERTEX_MAX + 1);
			gbVertexEqual = false;

			for (int count = 0; count < edgeCount; count++)
			{
				int vertex1;
				int vertex2;

				std::cin >> vertex1 >> vertex2;
				gGraph[vertex1].push_back(vertex2);
				gGraph[vertex2].push_back(vertex1);
			}

			for (int count = 1; count <= vertexCount; count++)
			{
				DFS(count, eStatus::Blue);
			}

			if (gbVertexEqual)
			{
				std::cout << "NO\n";
			}
			else
			{
				std::cout << "YES\n";
			}
		}

		return 0;
	}
}