#include<iostream>
#include<vector>
using namespace std;
vector<int> output(vector<vector<int>>& matrix, int index)
{
    int n = matrix.size();

    vector<int> ans;
    if (index == (n + 1) / 2 - 1 && n % 2 == 1)
    {
        ans.push_back(matrix[index][index]);
    }
    for (int i = index; i < n - index - 1; i++)
    {
        ans.push_back(matrix[index][i]);
    }
    for (int i = index; i < n - index - 1; i++)
    {
        ans.push_back(matrix[i][n - index - 1]);
    }
    for (int i = index; i < n - index - 1; i++)
    {
        ans.push_back(matrix[n - index - 1][n - i - 1]);
    }
    for (int i = index; i < n - index - 1; i++)
    {
        ans.push_back(matrix[n - i - 1][index]);
    }
    return ans;
}
vector<int> spiralOrder(vector<vector<int>>& matrix)
{
    int n = matrix.size();
    vector<int> ans;
    for (int i = 0; i < (n + 1) / 2; i++)
    {

        vector<int> temp = output(matrix, i);
        for (int& num : temp)
            ans.push_back(num);
    }
    return ans;
}


int main()
{
    vector<vector<int>>  matrix = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
    spiralOrder(matrix);
}