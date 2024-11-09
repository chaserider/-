#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
int maxSum(vector<int>& nums) // 求不相邻的最大和
{
    int sum = 0;
    int max = 0;
    long n = nums.size();
    // 用位运算简化选择操作
    // 保证不存在两个相邻的1才能进行选择
    bitset<50000> bit;
    for (int i = 0; i < (1 << n); i++)
    {
        if (!(i >> 1 & i)) // 不包含相邻的1则可以进行选择
        {
            bit = i;
            for (int j = 0; j < n; j++)
            {

                sum += nums[j] * (int)bit.test(50000 - j - 1);
            }
            max = sum > max ? sum : max;
            sum = 0;
        }
    }
    return max;
};
int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries)
{
    int n = nums.size();            // 记录数组长度
    int n_queries = queries.size(); // 记录查询次数
    int sum = 0;                    // 记录初始和，当每次查询最大值不小于0时，才相加

    for (auto& query : queries)
    {
        // 每次查询要将对应位置的值进行替换
        nums[query[0]] = query[1];

        // 每次需要找到最大值和第二最大值，且两个数不能相邻
        sum += maxSum(nums);
    }
    return sum;
}
int main()
{
    vector<int> nums = { 3,5,9 };
    vector<vector<int>> que;
    que.push_back({ 1,-2 });
    que.push_back({ 0,-3 });
    maximumSumSubsequence(nums, que);



    std::cin.get();
}