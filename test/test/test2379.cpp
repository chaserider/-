#include <iostream>
#include <vector>
using namespace std;

int minimumRecolors(string blocks, int k)
{
    int n = blocks.size();
    int left = 0, right = 0;
    int time = 0;
    int min_time;
    for (; right < k; right++)
    {
        if (blocks[right] == 'W')
            time++;
    }
    min_time = time;
    while (right < n)
    {
        if (blocks[left] == 'W')
            time--;
        if (blocks[right] == 'W')
            time++;
        min_time = time < min_time ? time : min_time;
        right++;
        left++;
    }
    return min_time;
}


int main()
{
    string s = "WBWBBBW";

    minimumRecolors(s,2);
    std::cin.get();
}