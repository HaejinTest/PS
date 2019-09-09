#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

constexpr int ARRAY_MAX = 100000;
// KEY : ID, VAL : Nick
std::map<std::string, std::string> gUsers;

enum class eType
{
	Enter = 0,
	Leave = 1,
	Change = 2,
};

struct Message
{
	eType Type;
	std::string ID;
};

vector<string> solution(vector<string> record) {
	vector<string> answer;
	vector<Message> msg;
	int size = static_cast<int>(record.size());

	for (int index = 0; index < size; index++)
	{
		istringstream str(record[index]);
		string type;
		string ID;
		string nickname;

		getline(str, type, ' ');
		getline(str, ID, ' ');
		getline(str, nickname, ' ');

		if (type == "Enter")
		{
			Message newMessage;

			newMessage.Type = eType::Enter;
			newMessage.ID = ID;
			gUsers[ID] = nickname;
			msg.push_back(newMessage);
		}
		else if (type == "Leave")
		{
			Message newMessage;

			newMessage.Type = eType::Leave;
			newMessage.ID = ID;
			msg.push_back(newMessage);
		}
		else
		{
			// Change
			gUsers[ID] = nickname;
		}
	}

	size = static_cast<int>(msg.size());

	for (int index = 0; index < size; index++)
	{
		Message& current = msg[index];
		ostringstream str;

		if (current.Type == eType::Enter)
		{
			str << gUsers[current.ID] << "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
		}
		else if (current.Type == eType::Leave)
		{
			str << gUsers[current.ID] << "´ÔÀÌ ³ª°¬½À´Ï´Ù.";
		}

		answer.push_back(str.str());
		str.clear();
	}

	return answer;
}