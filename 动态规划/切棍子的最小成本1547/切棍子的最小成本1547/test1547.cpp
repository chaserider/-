#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#ifdef 0
int minCost(int n, vector<int>& cuts)
{
    // 先用递归进行判断
    cuts.push_back(0);
    cuts.push_back(n);
    // 判断每一段如果选择的最小值
    int m = cuts.size();
    sort(cuts.begin(), cuts.end());
    // 传参的左右两边表示cuts下标
    function<int(int, int)> dfs = [&](int left, int right) -> int
        {
            if (left + 1 == right)
            {
                // 表示是cuts中的相邻段，不用切割
                return 0;
            }
            int res = n;
            // 依次在范围里进行切找最优的
            for (int i = left + 1; i < right; i++)
            {
                res = min(res, dfs(left, i) + dfs(i, right));
            }
            res += cuts[right] - cuts[left];
            return res;
        };
    return dfs(0, m - 1);
}
#endif // 0
int minCost(int n, vector<int>& cuts)
{
    // 用DP
    cuts.push_back(0);
    cuts.push_back(n);
    // 判断每一段如果选择的最小值
    int m = cuts.size();
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(m, vector<int>(m));
    // 这里每次处理都是选择比这个范围小的字段的最小值，dp的边界是只存在一段，而一段就不用切了
    for (int i = 2; i < m; i++) // 段的长度
    {
        for (int j = 0; i < m && (j + i) < m; j++) // 每段起点
        {
            int res = INT_MAX;
            for (int k = j + 1; k < j + i; k++)
            {
                // 计算每段长度
                res = min(res, dp[j][k] + dp[k][j + i]);
            }
            dp[j][j + i] = res + cuts[j + i] - cuts[j];
        }
    }
    return dp[0][m - 1];
}


int main()
{
    vector<int> cuts = { 1,3,4,5 };
    minCost(7, cuts);
    std::cin.get();
}