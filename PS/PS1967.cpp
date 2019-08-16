#include <iostream>
#include <cstdint>
#include <vector>
#include <utility>
#include <assert.h>
#include <queue>

/**
	@brief PS1967 트리의 지름 : https://www.acmicpc.net/problem/1967
	@details
	한 번에 못풀었음.
	왜?
	DFS를 이용하여 풀었는데 런타임 에러가 났기 때문.
	BFS를 이용하였더니 통과.
	이 차이는 무엇일까?
	DFS를 통한 재귀호출이 용량 부분에 연관이 있을 것이란 추측함.
	BFS의 경우 재귀 호출이 아니므로 용량 부분에서 이득.
	이번엔 마지막이나 처음 원소를 잘못 건들이는 문제는 없었음. 계속 주의할 것.
*/

namespace ps1967
{
	constexpr int MAX_NUM = 10000;
	int gMaxNodeIndex = 0;
	int gMaxNodeDistance = 0;

	std::vector<std::pair<int, int>> tree[MAX_NUM + 1];
	bool bVisitedNode[MAX_NUM + 1];
	int distance[MAX_NUM + 1];

	void DFS(std::vector<std::pair<int, int>>* const tree, int index, bool* const bVisitedNode, int* const distance)
	{
		bVisitedNode[index] = true;
		size_t size = tree[index].size();

		for (size_t count = 0; count < size; count++)
		{
			auto node = tree[index][count].first;

			if (bVisitedNode[node] == false)
			{
				distance[node] = tree[index][count].second + distance[index];

				if (distance[node] > gMaxNodeDistance)
				{
					gMaxNodeDistance = distance[node];
					gMaxNodeIndex = node;
				}

				DFS(tree, node, bVisitedNode, distance);
			}
		}
	}

	void BFS(std::vector<std::pair<int, int>>* const tree, int index, bool* const bVisitedNode, int* const distance)
	{
		std::queue<int> q;
		bVisitedNode[index] = true;
		q.push(index);

		while (q.empty() == false)
		{
			int x = q.front();
			q.pop();

			for (int i = 0; i < tree[x].size(); i++)
			{
				std::pair<int, int>& edge = tree[x][i];

				if (bVisitedNode[edge.first] == false)
				{
					distance[edge.first] = distance[x] + edge.second;
					q.push(edge.first);
					bVisitedNode[edge.first] = true;

					if (distance[edge.first] > gMaxNodeDistance)
					{
						gMaxNodeDistance = distance[edge.first];
						gMaxNodeIndex = edge.first;
					}
				}
			}
		}
	}

	void ClearVisitedNode(bool* bVisitedNode, int num)
	{
		assert(num > 0 && num < (MAX_NUM + 1));
		assert(bVisitedNode != nullptr);

		for (int index = 1; index <= num; index++)
		{
			bVisitedNode[index] = false;
		}
	}

	void ClearDistance(int* distance, int num)
	{
		assert(num > 0 && num < (MAX_NUM + 1));
		assert(distance != nullptr);

		for (int index = 1; index <= num; index++)
		{
			distance[index] = 0;
		}
	}

	int main(void)
	{
		std::ios_base::sync_with_stdio(false);

		int num;
		std::cin >> num;

		ClearVisitedNode(bVisitedNode, MAX_NUM);
		ClearDistance(distance, MAX_NUM);

		int count = num - 1;

		while (count--)
		{
			int parent; // 루트는 1
			int child;
			int weight; // 가중치 100보다 작음

			std::cin >> parent >> child >> weight;
			tree[parent].push_back(std::pair<int, int>(child, weight));
			tree[child].push_back(std::pair<int, int>(parent, weight));
		}

		BFS(tree, 1, bVisitedNode, distance);

		ClearVisitedNode(bVisitedNode, MAX_NUM);
		ClearDistance(distance, MAX_NUM);

		BFS(tree, gMaxNodeIndex, bVisitedNode, distance);

		std::cout << gMaxNodeDistance << std::endl;

		return 0;
	}
}
