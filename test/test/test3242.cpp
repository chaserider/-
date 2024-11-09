#include <iostream>
#include <vector>
using namespace std;

#ifdef 0

class NeighborSum
{
private:
    vector<vector<int>> matrix;
    int n; // ������
private:
    pair<int, int> Find(int value) const
    {
        int col; // ��¼��
        // �����������
        int i = 0;
        for (; i < n; i++) // ÿһ��ִ��find
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
        if (index.first != 0) // ����Ԫ��
        {
            sum += matrix[index.first - 1][index.second];
        }
        if (index.first != n - 1) // ����Ԫ��
        {
            sum += matrix[index.first + 1][index.second];
        }
        if (index.second != 0) // ����Ԫ��
        {
            sum += matrix[index.first][index.second - 1];
        }
        if (index.second != n - 1) // ����Ԫ��
        {
            sum += matrix[index.first][index.second + 1];
        }
        return sum;
    }

    int diagonalSum(int value)
    {
        auto index = Find(value);
        int sum = 0;
        if (index.first > 0 && index.second > 0) // ������Ԫ��
        {
            sum += matrix[index.first - 1][index.second - 1];
        }
        if (index.first > 0 && index.second < n - 1) // ������Ԫ��
        {
            sum += matrix[index.first - 1][index.second + 1];
        }
        if (index.first < n - 1 && index.second > 0) // ������Ԫ��
        {
            sum += matrix[index.first + 1][index.second - 1];
        }
        if (index.first < n - 1 && index.second < n - 1) // ������Ԫ��
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
    unordered_map<int, pair<int, int>> map; // �����洢ÿ��ֵ��λ��
    vector<vector<int>> matrix;
    int n; // ������
    static constexpr int dir[2][4][2] = { {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}, {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}} };

private:
    int GetSum(int value, int idx)
    {
        int sum = 0;
        auto [x, y] = map[value]; // ��ȡֵ��λ��
        for (int i = 0; i < 4; i++)
        {
            // ��ȡ�ĸ�λ��
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





