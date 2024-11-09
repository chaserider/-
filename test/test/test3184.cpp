#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int countCompleteDayPairs(vector<int>& hours)
{
    // ¹þÏ£·½·¨
    int n = hours.size();
    int ans = 0;
    unordered_map<int, int> lookup;
    for (auto& hour : hours)
    {
        int temp = hour % 24;
        ans += lookup[(24 - temp) % 24];
        lookup[temp]++;
    }
    return ans;
}

int main() { 
    vector<int> hours = { 72,48,24,3 };
    countCompleteDayPairs(hours);
    
    std::cin.get(); }