class Solution
{
public:
    int countKConstraintSubstrings(string s, int k)
    {
        // 滑动窗口
        // 每次判断以i为右边界的字串数量
        int sum[2]{}; // 记录两种数量
        int left = 0; // 记录可行子串的左边界
        int res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            sum[s[i] - '0']++;
            while (sum[0] > k && sum[1] > k) // 如果不满足，右移左边界
            {
                sum[s[left] - '0']--;
                left++;
            }
            res += i - left + 1;
        }
        return res;
    }
};