#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
int maxSum(vector<int>& nums) // �����ڵ�����
{
    int sum = 0;
    int max = 0;
    long n = nums.size();
    // ��λ�����ѡ�����
    // ��֤�������������ڵ�1���ܽ���ѡ��
    bitset<50000> bit;
    for (int i = 0; i < (1 << n); i++)
    {
        if (!(i >> 1 & i)) // ���������ڵ�1����Խ���ѡ��
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
    int n = nums.size();            // ��¼���鳤��
    int n_queries = queries.size(); // ��¼��ѯ����
    int sum = 0;                    // ��¼��ʼ�ͣ���ÿ�β�ѯ���ֵ��С��0ʱ�������

    for (auto& query : queries)
    {
        // ÿ�β�ѯҪ����Ӧλ�õ�ֵ�����滻
        nums[query[0]] = query[1];

        // ÿ����Ҫ�ҵ����ֵ�͵ڶ����ֵ������������������
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