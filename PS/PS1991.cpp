#include <iostream>
#include <vector>

/**
	@brief PS1991 트리 순회 : https://www.acmicpc.net/problem/1991
	@details
	첫 제출에 실패했음?
	왜?
	InOdrer를 생각해보면
	Left
	출력
	Right
	인데

	나는 그냥 트리 출력하듯이 Left와 Right를 구별하지 않았기 때문.
	그냥 바로 인오더니까 바로 size가 1인 경우
	Inorder
	출력

	이라고 가정을해버렸음.
*/

namespace ps1991
{
	struct Node
	{
		char Symbol;
		bool bLeft;
	};

	constexpr int NODE_MAX = 26;
	std::vector<Node> gTree[NODE_MAX + 1];

	void PreeOrderTraversal(int start)
	{
		size_t size = gTree[start].size();

		if (size == 0)
		{
			std::cout << (char)(start + 'A');

			return;
		}
		else if (size == 1)
		{
			Node node = gTree[start][0];

			std::cout << (char)(start + 'A');
			PreeOrderTraversal(node.Symbol - 'A');
		}
		else
		{
			Node node1 = gTree[start][0];
			Node node2 = gTree[start][1];

			std::cout << (char)(start + 'A');
			PreeOrderTraversal(node1.Symbol - 'A');
			PreeOrderTraversal(node2.Symbol - 'A');
		}
	}

	void InOrderTraversal(int start)
	{
		size_t size = gTree[start].size();

		if (size == 0)
		{
			std::cout << (char)(start + 'A');

			return;
		}
		else if (size == 1)
		{
			Node node = gTree[start][0];

			if (node.bLeft)
			{
				InOrderTraversal(node.Symbol - 'A');
				std::cout << (char)(start + 'A');
			}
			else
			{
				std::cout << (char)(start + 'A');
				InOrderTraversal(node.Symbol - 'A');
			}
		}
		else
		{
			Node node1 = gTree[start][0];
			Node node2 = gTree[start][1];

			InOrderTraversal(node1.Symbol - 'A');
			std::cout << (char)(start + 'A');
			InOrderTraversal(node2.Symbol - 'A');
		}
	}

	void PostOrderTraversal(int start)
	{
		size_t size = gTree[start].size();

		if (size == 0)
		{
			std::cout << (char)(start + 'A');

			return;
		}
		else if (size == 1)
		{
			Node node = gTree[start][0];

			PostOrderTraversal(node.Symbol - 'A');
			std::cout << (char)(start + 'A');
		}
		else
		{
			Node node1 = gTree[start][0];
			Node node2 = gTree[start][1];

			PostOrderTraversal(node1.Symbol - 'A');
			PostOrderTraversal(node2.Symbol - 'A');
			std::cout << (char)(start + 'A');
		}
	}

	int main(void)
	{
		std::ios_base::sync_with_stdio(false);

		int nodeCount;
		std::cin >> nodeCount;

		for (int count = 0; count < nodeCount; count++)
		{
			char node1;
			char node2;
			char node3;

			std::cin >> node1 >> node2 >> node3;

			if (node2 != '.')
			{
				Node node;
				node.Symbol = node2;
				node.bLeft = true;

				gTree[(int)(node1 - 'A')].push_back(node);
			}

			if (node3 != '.')
			{
				Node node;
				node.Symbol = node3;
				node.bLeft = false;

				gTree[(int)(node1 - 'A')].push_back(node);
			}
		}

		PreeOrderTraversal(0);
		std::cout << "\n";
		InOrderTraversal(0);
		std::cout << "\n";
		PostOrderTraversal(0);

		return 0;
	}
}
