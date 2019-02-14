/*************************************************************************
	> File Name: 最小路径和.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2019年02月14日 星期四 15时12分01秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
	int minPathSum(vector<vector<int>> &grid)
	{
		int gridRowSize = grid.size();
		int gridColSize = grid[0].size();

		if (gridRowSize <= 0)
			return 0;

		vector<vector<int>> minPath(gridRowSize, vector<int>(gridColSize, 0));
		minPath[0][0] = grid[0][0];

		//第一行第二列
		for (int k = 1; k < gridColSize; k++)
			minPath[0][k] = grid[0][k] + minPath[0][k - 1];
		//第二行第一列
		for (int k = 1; k < gridRowSize; k++)
			minPath[k][0] = grid[k][0] + minPath[k - 1][0];

		for (int i = 1; i < gridRowSize; i++)
		{
			for (int j = 1; j < gridColSize; j++)
			{
				minPath[i][j] = min(minPath[i][j - 1], minPath[i - 1][j]) + grid[i][j];
			}
		}
		return minPath[gridRowSize - 1][gridColSize - 1];
	}
};
//C 提交　
int minPathSum(int **grid, int gridRowSize, int gridColSize)
{
	if (gridRowSize <= 0 || gridColSize <= 0)
		return 0;

	int minPath[gridRowSize][gridColSize];

	for (int row = 0; row < gridRowSize; row++)
	{
		for (int col = 0; col < gridColSize; col++)
		{
			minPath[row][col] = 0;
		}
	}
	int i, j;
	minPath[0][0] = grid[0][0];
	//第一行第二列
	for (int k = 1; k < gridColSize; k++)
		minPath[0][k] = grid[0][k] + minPath[0][k - 1];
	//第二行第一列
	for (int k = 1; k < gridRowSize; k++)
		minPath[k][0] = grid[k][0] + minPath[k - 1][0];

	for (i = 1; i < gridRowSize; i++)
	{
		for (j = 1; j < gridColSize; j++)
		{
			if ((minPath[i][j - 1] < minPath[i - 1][j]))

				minPath[i][j] = minPath[i][j - 1] + grid[i][j];
			else
				minPath[i][j] = minPath[i - 1][j] + grid[i][j];
		}
	}
	return minPath[gridRowSize - 1][gridColSize - 1];
}