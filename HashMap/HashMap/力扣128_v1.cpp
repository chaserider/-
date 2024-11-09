//利用有序hash表进行存储，每次按顺序查表，如果存在前一个键值则加1，依次遍历数组
//246ms 34.18%
// 75.05 7.8%主要是因为有序表的原因

#include <iostream>
#include <vector>
#include <set>
using namespace std;
int longestConsecutive(vector<int>& nums) {
    set<int> mp;
    int count = 1;
    int max = 1;
    for (auto& it : nums)
    {
        mp.insert(it);
    }
    if (mp.empty())
        count = 0;
    for (auto& it : mp)
    {
        if (mp.find(it- 1) != mp.end())
            count++;
        else 
        {
            if (count > max)
            {
                max = count;
               
            }
            count = 1;
        }
    }
    if (count > max)
    {
        max = count;
    }
    return max;
};

int main()
{
    vector<int> nums = { 9,1,-3,2,4,8,3,-1,6,-2,-4,7 };
    int max = longestConsecutive(nums);

    std::cin.get();
};