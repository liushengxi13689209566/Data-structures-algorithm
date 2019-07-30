/*************************************************************************
	> File Name: 矩阵中的路径.cpp
	> Author: 
	> Mail: 
	> Created Time: 一  7/29 09:30:03 2019
 ************************************************************************/

/*
矩阵中的路径
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。 
例如 a b c e s f c s a d e e 这样的3 X 4 矩阵中包含一条字符串"bcced"的路径，
但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，
路径不能再次进入该格子。
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
private:
	int dir[4][2] = {
		{1, 0},
		{0, 1},
		{-1, 0},
		{0, -1}};
	int row = 0;
	int col = 0;
	char *p;
	bool check(char *matrix, int r, int c)
	{
		if (r < 0 || r > row - 1)
			return false;
		if (r < 0 || r > col - 1)
			return false;
		if (matrix[r][c] != *(++p))
			return false;
		return true;
	}
	bool dfs(char *matrx,int r,int c,vector<vector<int>& visted>)
    {
		for (int i = 0; i < 4; i++)
		{
			int rr = r + dir[i][0];
			int cc = c + dir[i][1];
			if (check(rr, cc) && visted[rr][cc] ! = 1)
			{
				visted[rr][cc] = 1;
				if (dfs(matrix, rr, cc))
					return true;
			}
		}
		return false;
    }
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
		if (!str)
			return false;
		row = rows;
		col = cols;
		p = str;
		vector<vector<int>> visted(rows, <vector<int>>(cols, 0));
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (matrix[i][j] == str[0])
				{
					visted[i][j] = 1;
					if (dfs(matrix, i, j, visted))
						return true;
				}
			}
		}
		return false;
    }
};
