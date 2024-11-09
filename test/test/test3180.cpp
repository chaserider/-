#include<iostream>
#include <vector>
#include<algorithm>

using namespace std;


//分支限界法
int maxreward(vector<int>& rewardValues, int reward, int i)
{
	if (i >= rewardValues.size())
		return reward;
	else
	{
		int reward0 =reward;//不选择
		int reward1;//选择
		reward0 = maxreward(rewardValues, reward, i + 1);
		if (rewardValues[i] > reward)
		{
			reward1 = maxreward(rewardValues, reward + rewardValues[i], i + 1);
			return max(reward0, reward1);
		}
		return reward0;
		
	}
}
int maxTotalReward(vector<int>& rewardValues)
{
	sort(rewardValues.begin(), rewardValues.end());
	int reward = 0;
	return maxreward(rewardValues, 0, 0);
}

int main()
{

	vector<int>  vec = { 6,13,9,19 };
	maxTotalReward(vec);

	std::cin.get();
}