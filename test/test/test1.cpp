#include<iostream>
#include<vector>
using namespace std;
int firstMissingPositive(vector<int>& nums)
{
    // 将原数组构造成哈希表
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] <= 0)
            nums[i] = n + 1;
    }

    for (int i = 0; i < n; i++)
    {
        if (abs(nums[i]) <= n)
            nums[nums[i] - 1] = -abs(nums[nums[i] - 1]);
    }
    int i = 0;
    for (; i < n; i++)
        if (nums[i] > 0)
            return i + 1;

    return n + 1;
}
int main()
{

    vector<int> nums = { 3,4,-1,1 };
    firstMissingPositive(nums);
	std::cin.get();
}