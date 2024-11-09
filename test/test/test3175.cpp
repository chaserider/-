#include <iostream>
#include <vector>
#include <deque>
#include <functional>
#include <unordered_map>
#include <utility>
using namespace std;
int findWinningPlayer(vector<int>& skills, int k)
{
    k = k > skills.size() ? skills.size()-1 : k;

    using T = pair<int, int>;
    deque<T> que;
    for (int i = 0; i < skills.size(); i++)
    {
        que.push_back(make_pair(i,0));
    }
    while ((que.front()).second < k)
    {
        pair<int, int> player1 = que.front();
        que.pop_front();
        pair<int, int> player2 = que.front();
        que.pop_front();
        if (skills[player1.first] > skills[player2.first])
        {
            player1.second++;
            player2.second = 0;
            que.push_front(player1);
            que.push_back(player2);
        }
        else
        {
            player2.second++;
            player1.second = 0;
            que.push_front(player2);
            que.push_back(player1);
        }
    }
    return (que.front()).first;
}

int main()
{
    vector<int> skills = { 7,5,16,3,13,2,8,18 };
    findWinningPlayer(skills, 826156069);
	std::cin.get();
}