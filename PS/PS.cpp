#include <iostream>
#include <algorithm>
#include <array>

constexpr int MAX_JUICE_COUNT = 10000;
int gQuantity[MAX_JUICE_COUNT + 1];
int gMemo[MAX_JUICE_COUNT + 1];

int main(void)
{
	int num;
	int index = 1;
	int quantity = 0;

	std::cin >> num;
	int count = num;
	while (count--)
	{
		std::cin >> quantity;
		gQuantity[index++] = quantity;
	}

	gMemo[1] = gQuantity[1];
	gMemo[2] = gQuantity[1] + gQuantity[2];
	
	for (int index = 3; index < num + 1; index++)
	{
		std::array<int, 3> arr = {gMemo[index - 1], gQuantity[index] + gMemo[index -2], gQuantity[index] + gQuantity[index - 1] + gMemo[index - 3]};
		gMemo[index] = *std::max_element(arr.begin(), arr.end());
	}

	std::cout << gMemo[num] << std::endl;
}