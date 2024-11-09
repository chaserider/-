#include<iostream>

#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;
int maxTotalReward(vector<int>& rewardValues)
{
    sort(rewardValues.begin(), rewardValues.end());
    // 用一个dp数组来表示是否当前这个总价值能够获得
    // 转移方程，因为只有大于m才能选，所以每次转移最多是当前价值的两倍
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