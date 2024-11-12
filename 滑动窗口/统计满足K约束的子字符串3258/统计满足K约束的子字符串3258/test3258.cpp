class Solution
{
public:
    int countKConstraintSubstrings(string s, int k)
    {
        // ��������
        // ÿ���ж���iΪ�ұ߽���ִ�����
        int sum[2]{}; // ��¼��������
        int left = 0; // ��¼�����Ӵ�����߽�
        int res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            sum[s[i] - '0']++;
            while (sum[0] > k && sum[1] > k) // ��������㣬������߽�
            {
                sum[s[left] - '0']--;
                left++;
            }
            res += i - left + 1;
        }
        return res;
    }
};