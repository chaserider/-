#include <iostream>
#include<vector>
#include<unordered_map>
//#include <pair>
using namespace std;
void setZeroes(vector<vector<int>>& matrix)
{

	int row = matrix.size();
	int col = matrix[0].size();
	vector<int> z_row(row), z_col(col);
	for (int r = 0; r < row; r++)
		for (int c = 0; c < col; c++)
		{
			if (matrix[r][c] == 0)
			{
				z_row[r] = 1;
				z_col[c] = 1;
			}
		}
	for (int idx = 0; idx < row; idx++)
		if (z_row[idx] == 1)
			for (int i = 0; i < col; i++)
				matrix[idx][i] = 0;
	for (int idx = 0; idx < col; idx++)
		if (z_col[idx] == 1)
			for (int i = 0; i < row; i++)
				matrix[i][idx] = 0;
}
int main()
{

	vector<vector<int>> nums = { {1, 1, 1},{1, 0, 1},{1, 1, 1} };
	setZeroes(nums);

	std::cin.get();
}