#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
long long countCompleteDayPairs(vector<int>& hours)
{
    int n = hours.size();
    long long ans=0;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
        {
            if ((hours[i] + hours[j]) % 24 == 0)
                ans++;
        }
    return ans;
}
int main() {
    vector<int> hours = { 72,48,24,3 };
    countCompleteDayPairs(hours);

    std::cin.get();
}