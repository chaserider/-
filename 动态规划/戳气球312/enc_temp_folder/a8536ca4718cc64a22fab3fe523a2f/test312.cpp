#include <iostream>
#include <vector>
#include <functional>
using namespace std;


int maxCoins(vector<int>& nums)
{
    // ����д������ĵݹ�Ӽ��仯����
    //  ������͵�ǰ���ϵ��������
    //  ÿ�εݹ�ѡ��ǰ����������ߵ����ֵ
    vector<int> val;
    int n = nums.size();
    val.resize(n + 2);
    for (int i = 1; i <=n; i++)
    {
        val[i] = nums[i - 1];
    }
    val[0] = val[n + 1] = 1;
    vector<vector<int>> memo(n+2, vector<int>(n+2));

    function<int(int, int)> dfs = [&](int left, int right) -> int
        {
            if (left >= right - 1)
                return 0;
            // ʣ��������ʱ��Ҫ����
            // �����жϴ��ĸ���������
            if (memo[left][right])
                return memo[left][right];
            int res = 0; // ��¼����ֵ
            for (int i = left+1; i <right; i++)
            {
                int l_val =val[left];  // ��¼��ֵ�Է�Ϊ�߽�
                int r_val =val[right]; // ��¼��ֵ�Է�Ϊ�߽�
                res = max(res, val[i] * l_val * r_val + dfs(left, i) + dfs(i, right));
            }
            memo[left][right] = res;
            return res;
        };
    return dfs(0, n+1);
}


int main()
{
    vector<int> nums = {3,1,5};
    int ans=maxCoins(nums);

    std::cin.get();
}