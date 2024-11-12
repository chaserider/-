#include <iostream>
#include <vector>
#include<functional>
using namespace std;

long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB)
{
    // 利用记忆化搜索进行操作,会超时
    int n = energyDrinkA.size();
    vector<array<long long, 2>> memo(n); // 记录每次选择可获的最大值
    function<long long(int, int)> dfs = [&](int ind, int chose) -> long long
        {
            if (ind >= n)
                return 0;
            else
            {
                if (memo[ind][chose])
                    return memo[ind][chose];

                // 不存在缓存
                long long res = 0;
                {
                    if (chose == 0)
                    {
                        res = max(energyDrinkA[ind] + dfs(ind + 1, 0), dfs(ind + 1, 1));
                    }
                    else
                    {
                        res = max(energyDrinkB[ind] + dfs(ind + 1, 1), dfs(ind + 1, 0));
                    }
                }
                memo[ind][chose] = res;
            }
            return memo[ind][chose];
        };
    return max(dfs(0, 0), dfs(0, 1));
}


//动态规划版
long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB)
{
    // 利用记忆化搜索进行操作
    int n = energyDrinkA.size();
    vector<array<long long, 2>> memo(n + 1); // 记录每次选择可获的最大值
    memo[1][0] = energyDrinkA[0];
    memo[1][1] = energyDrinkB[0];
    for (int i = 2; i <= n; i++)
    {
        memo[i][0] = max(memo[i - 1][0], memo[i - 2][1]) + energyDrinkA[i - 1];
        memo[i][1] = max(memo[i - 1][1], memo[i - 2][0]) + energyDrinkB[i - 1];
    }
    return max(memo[n][0], memo[n][1]);
}
int main()
{
    vector<int> A = { 1,3,1 };
    vector<int> D = { 3,1,3 };
    maxEnergyBoost(A, D);


    std::cin.get();
}