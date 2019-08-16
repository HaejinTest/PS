#include <iostream>
#include <vector>

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
}