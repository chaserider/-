#include <iostream>
#include <unordered_map>
#include <functional>
using namespace std;


class Solution {
public:
    string minWindow(string s, string t) {

        int ns = s.size();
        int nt = t.size();
        unordered_map<char, int> map, cach;
        for (char& c : t)
        {
            map[c]++;
        }
        auto check = [&map, &cach]() -> bool
            {
                for (auto& it : map)
                {
                    if (cach[it.first] < it.second)
                        return false;
                }
                return true;
            };
        int minleft = -1;
        int minright = ns;
        int left = 0;
        int right = -1;
        while (right < ns)
        {
            if (map.find(s[++right]) != map.end())
            {
                cach[s[right]]++;
            }
            while (check() && left <= right)
            {
                if ((right - left + 1) < (minright - minleft))
                {
                    minright = right;
                    minleft = left;
                }
            }
            if (map.find(s[left]) != map.end())
            {
                cach[s[left]]--;
            }
            left++;
        }
        return minleft == -1 ? string() : s.substr(minleft, minright - minleft);



    }
};

string minWindow(string s, string t)
{
    int ns = s.size();
    int nt = t.size();
    if (ns < nt)
        return "";

    unordered_map<char, int> map, cnt;

    auto check = [&map, &cnt]() -> bool
        {
            for (auto& it : map)
            {
                if (cnt[it.first] < it.second)
                    return false;
            }
            return true;
        };
    for (auto& c : t)
    {
        map[c]++;
    }
    int left = 0;
    int right = 0;
    int minright = ns;
    int minleft = 0;
    string ans = "";
    while (right < ns)
    {
        if (map.find(s[right++]) != map.end())
            cnt[s[right]]++;

        while (check() && (right >= left))
        {
            if ((right - left) < (minright - minleft))
            {
                minright = right;
                minleft = left;
            }
            if (map.find(s[left]) != map.end())
                cnt[s[left]]--;
            left++;
        }
    }
    for (int i = minleft; i < minright; i++)
        ans += s[i];
    return ans;
}

int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";

    Solution ans;
    string resultans = ans.minWindow(s, t);
	std::cin.get();
}