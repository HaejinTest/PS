#include <iostream>
#include <string>
#include <stack>

struct Element
{
	char type;
	int index;
};

void PS10799()
{
	std::string input;
	std::stack<Element> stack;

	std::getline(std::cin, input);

	int input_size = static_cast<int>(input.size());
	int total = 0;

	for (int index = 0; index < input_size; index++)
	{
		if (stack.empty())
		{
			stack.push(Element{ input[index], index });

			continue;
		}

		Element e = stack.top();

		if (e.type == '(')
		{
			if (input[index] == '(')
			{
				stack.push(Element{ input[index], index });
			}

			if (input[index] == ')')
			{
				stack.pop();

				if (e.index == index - 1)
				{
					total += static_cast<int>(stack.size());
				}
				else
				{
					total += 1;
				}
			}
		}
	}

	std::cout << total;
}
