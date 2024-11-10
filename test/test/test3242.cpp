#include <iostream>
#include <vector>
using namespace std;

#ifdef 0

class NeighborSum
{
private:
    vector<vector<int>> matrix;
    int n; // 行列数
private:
    pair<int, int> Find(int value) const
    {
        int col; // 记录列
        // 首先无序查找
        int i = 0;
        for (; i < n; i++) // 每一行执行find
        {
            auto c_temp = find(matrix[i].begin(), matrix[i].end(), value);
            if (c_temp != matrix[i].end())
            {
                col = c_temp - matrix[i].begin();
                break;
            }
        }
        return { i, col };
    }

public:
    NeighborSum(vector<vector<int>>& grid)
    {
        for (auto& row : grid)
        {
            vector<int> temp;
            for (auto& col : row)
            {
                temp.push_back(col);
            }
            matrix.push_back(temp);
        }
        n = grid.size();
    }

    int adjacentSum(int value)
    {
        auto index = this->Find(value);
        int sum = 0;
        if (index.first != 0) // 有上元素
        {
            sum += matrix[index.first - 1][index.second];
        }
        if (index.first != n - 1) // 有下元素
        {
            sum += matrix[index.first + 1][index.second];
        }
        if (index.second != 0) // 有左元素
        {
            sum += matrix[index.first][index.second - 1];
        }
        if (index.second != n - 1) // 有下元素
        {
            sum += matrix[index.first][index.second + 1];
        }
        return sum;
    }

    int diagonalSum(int value)
    {
        auto index = Find(value);
        int sum = 0;
        if (index.first > 0 && index.second > 0) // 有左上元素
        {
            sum += matrix[index.first - 1][index.second - 1];
        }
        if (index.first > 0 && index.second < n - 1) // 有右上元素
        {
            sum += matrix[index.first - 1][index.second + 1];
        }
        if (index.first < n - 1 && index.second > 0) // 有左下元素
        {
            sum += matrix[index.first + 1][index.second - 1];
        }
        if (index.first < n - 1 && index.second < n - 1) // 有右上元素
        {
            sum += matrix[index.first + 1][index.second + 1];
        }
        return sum;
    }
};

#endif // 0
class NeighborSum
{
private:
    unordered_map<int, pair<int, int>> map; // 用来存储每个值的位置
    vector<vector<int>> matrix;
    int n; // 行列数
    static constexpr int dir[2][4][2] = { {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}, {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}} };

private:
    int GetSum(int value, int idx)
    {
        int sum = 0;
        auto [x, y] = map[value]; // 获取值的位置
        for (int i = 0; i < 4; i++)
        {
            // 获取四个位置
            int nx = x + dir[idx][i][0];
            int ny = y + dir[idx][i][1];
            if (0 <= nx && nx < n && 0 <= ny && ny < n)
                sum += matrix[nx][ny];
        }
        return sum;
    }

public:
    NeighborSum(vector<vector<int>>& grid)
    {
        n = grid.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                map[grid[i][j]] = { i, j };
        matrix = move(grid);
    }

    int adjacentSum(int value)
    {
        return GetSum(value, 0);
    }

    int diagonalSum(int value)
    {
        return GetSum(value, 1);
    }
};
int main()
{
    vector<vector<int>> grid = { {0,1,2},{3,4,5},{6,7,8} };
    NeighborSum matrix(grid);
    matrix.adjacentSum(1);

    std::cin.get();
}





