#include <iostream>
#include <vector>
using namespace std;


int dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& needs)
{
    // 直接递归没有记忆化搜索
    int n = price.size();
    // 记录当前需要最小价值
    int minprice = 0;
    for (int i = 0; i < n; i++)
        minprice += needs[i] * price[i];
    // 判断选择礼包是否会便宜
    vector<int> nextneed(n); // 记录剩余的数量
    bool chose;
    for (auto& bag : special)
    {
        // 判断是否会超出数量
        for (int i = 0; i < n; i++)
        {
            if (bag[i] > needs[i])
            {
                chose = false;
                break; // 会超出不考虑
            }
            else // 计算剩余需要的数量
            {
                nextneed[i] = needs[i] - bag[i];
                chose = true;
            }
           
        }
        if (chose) // 如果选择该礼包
        {
            minprice = min(minprice, bag[n]+dfs(price, special, nextneed));
        }
    }
    return minprice;
};
int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs)
{
    // 为达到要求可以选择的种类有选单个商品，选大礼包，单个商品好判断
    // 如果选择大礼包，剩余需要的数量就是个子问题，同时不能超出需要数量

    int n = price.size();

    // 过滤不需要计算的大礼包，只保留需要计算的大礼包
    vector<vector<int>> filterSpecial;
    for (auto& sp : special)
    {
        int totalCount = 0, totalPrice = 0;
        for (int i = 0; i < n; ++i)
        {
            totalCount += sp[i];
            totalPrice += sp[i] * price[i];
        }
        if (totalCount > 0 && totalPrice > sp[n])
        {
            filterSpecial.emplace_back(sp);
        }
    }

    return dfs(price, filterSpecial, needs);
}


int main()
{
    vector<int> price{2,5};
    vector<vector<int>> special = { {3,0,5},{1,2,10} };
    vector<int> needs = { 3,2 };
    shoppingOffers(price, special, needs);

    std::cin.get();
}