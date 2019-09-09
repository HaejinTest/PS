#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Info
{
	int StageUser;
	int StageEnterUser;
};

struct FailRatioInfo
{
	float FailRatio;
	int Stage;
};

bool Comp(const FailRatioInfo& lhs, const FailRatioInfo& rhs)
{
	if (lhs.FailRatio == rhs.FailRatio)
	{
		return lhs.Stage < rhs.Stage;
	}

	return lhs.FailRatio > rhs.FailRatio;
}

// stages 길이 1 <= N <= 200000
// stages의 각 원소는 1 <= E <= N+1
// N + 1은 마지막 스테이지까지 클리어한 유저
vector<int> solution(int N, vector<int> stages) {
	vector<Info> stagePerUser(N + 2); // 0제외에 N+1 추가하니까

	int size = static_cast<int>(stages.size());

	for (int index = 0; index < size; index++)
	{
		int stage = stages[index];
		stagePerUser[stage].StageUser++;

		for (int count = 1; count <= stage; count++)
		{
			stagePerUser[count].StageEnterUser++;
		}
	}

	// 실패율 구해야함
	vector<FailRatioInfo> failRatio;
	size = static_cast<int>(stagePerUser.size());

	for (int index = 1; index < size; index++)
	{
		if (index == size - 1)
		{
			continue;
		}

		float ratio;

		if (stagePerUser[index].StageUser == 0 || stagePerUser[index].StageEnterUser == 0)
		{
			ratio = 0.0f;
		}
		else
		{
			ratio = static_cast<float>(stagePerUser[index].StageUser) / stagePerUser[index].StageEnterUser;
		}

		FailRatioInfo info;
		info.FailRatio = ratio;
		info.Stage = index;

		failRatio.push_back(info);
	}

	sort(failRatio.begin(), failRatio.end(), Comp);

	size = static_cast<int>(failRatio.size());
	vector<int> answer;

	for (int index = 0; index < size; index++)
	{
		answer.push_back(failRatio[index].Stage);
	}

	return answer;
}

//int main(void)
//{
//	std::vector<int> stages;
//	stages.push_back(2);
//	stages.push_back(1);
//	stages.push_back(2);
//	stages.push_back(6);
//	stages.push_back(2);
//	stages.push_back(4);
//	stages.push_back(3);
//	stages.push_back(3);
//
//	solution(5, stages);
//}