#include <iostream>
#include <string>
#include <cstdint>
#include <cstring>

/**
	@brief PS1541 잃어버린 괄호 : https://www.acmicpc.net/problem/1541
	@details
	왜 틀렸는지?
	atoi를 하고난 후에 문자열을 초기화해줘야하는데 안해줌 ㅡ.ㅡ;;
*/
namespace ps1541
{
	// 55-50+49....
// 식은 0~9 + - 그리고 두 개이상연산자 없고 처음과 끝은 숫자
// 5자리보다 큰 숫자 없고, 0으로 시작할 수 있음 대신 09 이런건없겟지
	constexpr int64_t MAX_DIGIT = 6;
	void ClearNum(char* num)
	{
		memset(num, '\0', MAX_DIGIT + 1);
	}

	int main()
	{
		std::string input;
		int64_t sum = 0;
		bool bFindFirstMinus = false;
		char num[MAX_DIGIT + 1];
		ClearNum(num);

		std::cin >> input;
		size_t size = input.size();
		const char* rawInput = input.c_str();
		int64_t length = 0;

		for (size_t index = 0; index <= size; index++)
		{
			if (input[index] != '-' && input[index] != '+' && input[index] != '\0')
			{
				num[length++] = input[index];

				continue;
			}

			if (bFindFirstMinus)
			{
				sum -= atoi(num);
				length = 0;
				ClearNum(num);
			}
			else
			{
				sum += atoi(num);
				length = 0;
				ClearNum(num);
			}

			if (input[index] == '-')
			{
				bFindFirstMinus = true;
			}
		}

		std::cout << sum;

		return 0;
	}
}