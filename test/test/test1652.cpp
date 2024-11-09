#include <iostream>
#include <vector>
using namespace std;


vector<int> decrypt(vector<int>& code, int k)
{

    if (k == 0)
    {
        vector<int> ans(code.size(), 0);
        return ans;
    }
    else
    { // k不为0时统一处理，无非是向前向后循环而已

        int n = code.size();
        vector<int> ans(n);

        int pos = k > 0 ? 1 : -1; // 判断是向前还是向后找
        int num = abs(k);
        int sum = 0;
        int cur = (n + 0 + pos) % n; // 当前指针
        while (num > 0)
        {
            sum += code[cur];
            cur = (n + cur + pos) % n;
            num--;
        }
        ans[0] = sum;
        for (int i = 1; i < n; i++)
        {
            
            sum -= code[(n + cur - k) % n];
            sum += code[cur];
            ans[i] = sum;
            cur = (n + cur + pos) % n;
        }
        return ans;
    }
}


int main()
{

    vector<int> code = { 5,7,1,4 };
    decrypt(code, 3);
    std::cin.get();
}