
#include <iostream>
#include <vector>

using namespace std;

vector<int> getAverages(vector<int>& nums, int k)
{
    int n = nums.size();
    if (2 * k + 1 > n)
        return { -1 };
    int left = -k;
    int right = 0;
    int sum = 0; // ÇóºÍ
    for (; right <= k; right++)
    {
        sum += nums[right];
    }
    vector<int> ans;
    while (left < n - k)
    {
        if (left < 0 || right > n)
            ans.push_back(-1);
        else
            ans.push_back(sum / (right - left));
        if (left >= 0)
            sum -= nums[left];
        if (right < n)
            sum += nums[right];
        left++;
        right++;
    }
    return ans;
}
int main()
{
    vector<int> nums = { 10000 };
    getAverages(nums, 0);
    std::cin.get();
}