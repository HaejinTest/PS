#include <iostream>
#include <vector>
#include <utility>
#include <queue>
// 2초
// 256MB

enum class eColor
{
	NotVisited = 0,
	Red = 1,
	Blue = 2
};

constexpr short VERTEX_MAX = 20000;
constexpr int EDGE_MAX = 200000;
std::vector<short> gGraph[VERTEX_MAX + 1];
eColor gColor[VERTEX_MAX + 1];

void DFS(short start, eColor color)
{
	gColor[start] = color;
	size_t size = gGraph[start].size();

	for (short index = 0; index < size; index++)
	{
		short vertex = gGraph[start][index];

		if (gColor[vertex] == eColor::NotVisited)
		{
			if (color == eColor::Blue)
			{
				DFS(vertex, eColor::Red);
			}
			else
			{
				DFS(vertex, eColor::Blue);
			}
		}
	}
}

void BFS(int start)
{
	std::queue<short> vertexQueue;

	if (gColor[start] != eColor::NotVisited)
	{
		return;
	}

	vertexQueue.push(start);
	gColor[start] = eColor::Red;

	while (vertexQueue.empty() == false)
	{
		short vertex = vertexQueue.front();
		vertexQueue.pop();

		size_t size = gGraph[vertex].size();

		for (short index = 0; index < size; index++)
		{
			short node = gGraph[vertex][index];

			if (gColor[node] == eColor::NotVisited)
			{
				if (gColor[vertex] == eColor::Red)
				{
					gColor[node] = eColor::Blue;
				}
				else
				{
					gColor[node] = eColor::Red;
				}

				vertexQueue.push(node);
			}
		}
	}
}

int main(void)
{
	std::cin.sync_with_stdio(false);

	short testCaseCount;
	std::cin >> testCaseCount;	
	
	while (testCaseCount--)
	{
		for (short index = 1; index <= VERTEX_MAX; index++)
		{
			gColor[index] = eColor::NotVisited;
			gGraph[index].clear();
		}

		short vertexCount;
		int edgeCount;
		std::cin >> vertexCount >> edgeCount;

		for (int count = 0; count < edgeCount; count++)
		{
			short vertex1;
			short vertex2;
			std::cin >> vertex1 >> vertex2;

			gGraph[vertex1].push_back(vertex2);
			gGraph[vertex2].push_back(vertex1);
		}
		// --그래프 완성 끝--

		for (int count = 1; count <= vertexCount; count++)
		{
			if (gColor[count] == eColor::NotVisited)
			{
				DFS(count, eColor::Red);
			}
		}

		//DFS(1, eColor::Red);
		// -- 색칠 끝 -- 		

		bool bColorEqual = false;

		for (int index = 1; index <= vertexCount; index++)
		{
			size_t size = gGraph[index].size();
			eColor color = gColor[index];

			for (short count = 0; count < size; count++)
			{
				short vertex = gGraph[index][count];

				if (color == gColor[vertex])
				{
					bColorEqual = true;

					break;
				}
			}
		}

		if (bColorEqual)
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