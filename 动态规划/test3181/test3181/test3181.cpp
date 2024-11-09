#include<iostream>

#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;
int maxTotalReward(vector<int>& rewardValues)
{
    sort(rewardValues.begin(), rewardValues.end());
    // ��һ��dp��������ʾ�Ƿ�ǰ����ܼ�ֵ�ܹ����
    // ת�Ʒ��̣���Ϊֻ�д���m����ѡ������ÿ��ת������ǵ�ǰ��ֵ������
    bitset<100000> dp = { 0 };
    dp[0] = 1;
    for (int& val : rewardValues)
    {
        int off = dp.size() - val;
        dp |= dp <<off>>off<<val;
    }
    for (int i = 100000 - 1; i >= 0; i--)
    {
        if (dp[i] == 1)
            return i;
    }
    return 0;
}
int main()
{
    vector<int> reward = { 1,1,3,3 };
    maxTotalReward(reward);
    std::cin.get();
}