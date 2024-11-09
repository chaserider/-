//��������hash����д洢��ÿ�ΰ�˳�����������ǰһ����ֵ���1�����α�������
//246ms 34.18%
// 75.05 7.8%��Ҫ����Ϊ������ԭ��

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