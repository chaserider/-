#include <iostream>
#include <vector>
using namespace std;


int dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& needs)
{
    // ֱ�ӵݹ�û�м��仯����
    int n = price.size();
    // ��¼��ǰ��Ҫ��С��ֵ
    int minprice = 0;
    for (int i = 0; i < n; i++)
        minprice += needs[i] * price[i];
    // �ж�ѡ������Ƿ�����
    vector<int> nextneed(n); // ��¼ʣ�������
    bool chose;
    for (auto& bag : special)
    {
        // �ж��Ƿ�ᳬ������
        for (int i = 0; i < n; i++)
        {
            if (bag[i] > needs[i])
            {
                chose = false;
                break; // �ᳬ��������
            }
            else // ����ʣ����Ҫ������
            {
                nextneed[i] = needs[i] - bag[i];
                chose = true;
            }
           
        }
        if (chose) // ���ѡ������
        {
            minprice = min(minprice, bag[n]+dfs(price, special, nextneed));
        }
    }
    return minprice;
};
int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs)
{
    // Ϊ�ﵽҪ�����ѡ���������ѡ������Ʒ��ѡ�������������Ʒ���ж�
    // ���ѡ��������ʣ����Ҫ���������Ǹ������⣬ͬʱ���ܳ�����Ҫ����

    int n = price.size();

    // ���˲���Ҫ����Ĵ������ֻ������Ҫ����Ĵ����
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