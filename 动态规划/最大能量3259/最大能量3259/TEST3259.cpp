#include <iostream>
#include <vector>
#include<functional>
using namespace std;

long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB)
{
    // ���ü��仯�������в���,�ᳬʱ
    int n = energyDrinkA.size();
    vector<array<long long, 2>> memo(n); // ��¼ÿ��ѡ��ɻ�����ֵ
    function<long long(int, int)> dfs = [&](int ind, int chose) -> long long
        {
            if (ind >= n)
                return 0;
            else
            {
                if (memo[ind][chose])
                    return memo[ind][chose];

                // �����ڻ���
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


//��̬�滮��
long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB)
{
    // ���ü��仯�������в���
    int n = energyDrinkA.size();
    vector<array<long long, 2>> memo(n + 1); // ��¼ÿ��ѡ��ɻ�����ֵ
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