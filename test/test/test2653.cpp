#include <iostream>
#include <vector>
using namespace std;
vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x)
{

    // 由于数的范围小，数据量大，利用计数排序思想
    int n = nums.size();

    // 定义一个数组来计数-50-50
    int lookup[101] = { 0 }; // 初始都为0

    // 先传入k个值
    for (int i = 0; i < k - 1; i++)
    {
        lookup[nums[i] + 50]++;
    }
    vector<int> ans(n - k + 1, 0);
    for (int i = k - 1; i < n; i++)
    {
        lookup[nums[i] + 50]++;
        int j = x; // 找第x小
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