#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#ifdef 0

int numFriendRequests(vector<int>& ages) {
    // ��������Ҫ��Ӵ�С��������ָ���ʾ��ǰ���ڷ���������û���������ָ���ʾ���һ������Ҫ����û�������ָ��֮ǰ���û�������Ҫ��

    int n = ages.size();
    sort(ages.begin(), ages.end(), [](int& a, int& b) -> bool
        { return a > b; });
    int left = 0, right = 1;
    int mid = 0;
    int sum = 0;
    while (left < n)
    {
        if (right == left)
            right++;
        while (right < n && ages[right] > 0.5 * ages[left] + 7)
        {
            right++;
        }
        mid = left;
        while (mid - 1 >= 0 && ages[mid - 1] > 0.5 * ages[left] + 7 && ages[mid - 1] == ages[left])
        {
            mid--;
        }

        sum += right - left - 1 + left - mid;
        left++;
    }
    return sum;
}#endif


int n = ages.size();
int cnt[121]{};
for (auto& age : ages)
{
    cnt[age]++;
}
int pre[121]{};
for (int i = 1; i < 121; i++)
{
    pre[i] = pre[i - 1] + cnt[i];
}
int ans = 0;
for (auto& age : ages)
{
    if (age < 15)
        continue;
    int bound = age * 0.5 + 7;        // �½�
    ans += pre[age] - pre[bound] - 1; // ��Ҫ��ȥ�Լ�
}
return ans;

int main()
{
    vector<int> nums = { 108,115,5,24,82};
    numFriendRequests(nums);
    std::cin.get();
}