#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#ifdef 0
int minCost(int n, vector<int>& cuts)
{
    // ���õݹ�����ж�
    cuts.push_back(0);
    cuts.push_back(n);
    // �ж�ÿһ�����ѡ�����Сֵ
    int m = cuts.size();
    sort(cuts.begin(), cuts.end());
    // ���ε��������߱�ʾcuts�±�
    function<int(int, int)> dfs = [&](int left, int right) -> int
        {
            if (left + 1 == right)
            {
                // ��ʾ��cuts�е����ڶΣ������и�
                return 0;
            }
            int res = n;
            // �����ڷ�Χ������������ŵ�
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
    // ��DP
    cuts.push_back(0);
    cuts.push_back(n);
    // �ж�ÿһ�����ѡ�����Сֵ
    int m = cuts.size();
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(m, vector<int>(m));
    // ����ÿ�δ�����ѡ��������ΧС���ֶε���Сֵ��dp�ı߽���ֻ����һ�Σ���һ�ξͲ�������
    for (int i = 2; i < m; i++) // �εĳ���
    {
        for (int j = 0; i < m && (j + i) < m; j++) // ÿ�����
        {
            int res = INT_MAX;
            for (int k = j + 1; k < j + i; k++)
            {
                // ����ÿ�γ���
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