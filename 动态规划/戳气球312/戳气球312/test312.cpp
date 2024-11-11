#include <iostream>
#include <vector>
#include <functional>
using namespace std;

#if 0

int maxCoins(vector<int>& nums)
{
    // 首先写最基本的递归加记忆化搜索
    //  子问题就当前段上的最大数量
    //  每次递归选择当前气球和他两边的最大值
    vector<int> val;
    int n = nums.size();
    val.resize(n + 2);
    for (int i = 1; i <= n; i++)
    {
        val[i] = nums[i - 1];
    }
    val[0] = val[n + 1] = 1;
    vector<vector<int>> memo(n + 2, vector<int>(n + 2));

    function<int(int, int)> dfs = [&](int left, int right) -> int
        {
            if (left >= right - 1)
                return 0;
            // 剩余多个气球时需要计算
            // 依次判断戳哪个气球会最大
            if (memo[left][right])
                return memo[left][right];
            int res = 0; // 记录最大的值
            for (int i = left + 1; i < right; i++)
            {
                int l_val = val[left];  // 记录左值以防为边界
                int r_val = val[right]; // 记录右值以防为边界
                res = max(res, val[i] * l_val * r_val + dfs(left, i) + dfs(i, right));
            }
            memo[left][right] = res;
            return res;
        };
    return dfs(0, n + 1);
}
#endif // 0

int maxCoins(vector<int>& nums)
{
    // 用动态规划的思路进行求解
    //  子问题就当前段上的最大数量
    //  每次递归选择当前气球和他两边的最大值

    // 最小的子问题是在相近两个值中间插入一个气球
    int n = nums.size(); // 这里只需要计算n个不用管边界插入的1
    vector<int> val;
    val.resize(n + 2);
    for (int i = 1; i <= n; i++)
    {
        val[i] = nums[i - 1];
    }
    val[0] = val[n + 1] = 1;
    vector<vector<int>> dp(n + 2, vector<int>(n + 2));

    for (int i = 2; i < n + 2; i++) // 范围
    {
        for (int j = 0; j + i < n + 2; j++) // 左值
        {
            for (int k = j + 1; k < j + i; k++) // 中间值
            {
                int sum = val[j] * val[k] * val[j + i]; // 戳这个气球的值
                dp[j][j + i] = max(dp[j][j + i], sum + dp[j][k] + dp[k][j + i]);
            }
        }
    }
    return dp[0][n + 1];
}




int main()
{
    vector<int> nums = {3,1,5};
    int ans=maxCoins(nums);

    std::cin.get();
}