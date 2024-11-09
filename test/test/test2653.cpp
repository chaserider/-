#include <iostream>
#include <vector>
using namespace std;
vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x)
{

    // �������ķ�ΧС�������������ü�������˼��
    int n = nums.size();

    // ����һ������������-50-50
    int lookup[101] = { 0 }; // ��ʼ��Ϊ0

    // �ȴ���k��ֵ
    for (int i = 0; i < k - 1; i++)
    {
        lookup[nums[i] + 50]++;
    }
    vector<int> ans(n - k + 1, 0);
    for (int i = k - 1; i < n; i++)
    {
        lookup[nums[i] + 50]++;
        int j = x; // �ҵ�xС
        int ind = 0;
        while (j)
        {
            if (lookup[ind] > 0)
            {
                j-= lookup[ind];
                
            }
            else
                ind++;
        }
        if (ind < 50)
            ans[i - k + 1] = ind - 50;
        lookup[nums[i - k + 1] + 50]--;
    }
    return ans;
}


int main()
{
    vector<int> nums = { 1,-1,-3,-2,3 };
    getSubarrayBeauty(nums, 3, 2);
    std::cin.get();
}