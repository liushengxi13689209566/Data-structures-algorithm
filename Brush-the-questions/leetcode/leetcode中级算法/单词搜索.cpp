/*************************************************************************
	> File Name: 单词搜索.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2018年08月10日 星期五 22时55分21秒
 ************************************************************************/
/*给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，
其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
同一个单元格内的字母不允许被重复使用。

示例:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "ABCCED", 返回 true.
给定 word = "SEE", 返回 true.
给定 word = "ABCB", 返回 false.*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution
{
  public:
	string str;
	vector<vector<char>> map;
	vector<vector<bool>> visted;
	int index = 1;
	int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	
	bool DFS(int x, int y, int deep)
	{
		auto row = map.size();
		auto col = map[0].size();
		auto len = str.size();
		
		if (deep == len && map[x][y] == str[len - 1])
		{
			return true;
		}
		for (int i = 0; i < 4; i++)
		{
			auto xx = x + dir[i][0];
			auto yy = y + dir[i][1];
			if (xx < 0 || xx >= row || yy < 0 || yy >= col || visted[xx][yy] || map[xx][yy] != str[index])
				continue;
			else
			{
				index++;
				visted[xx][yy] = true;
				if (DFS(xx, yy, deep + 1))
					return true;
				visted[xx][yy] = false ;
				index--;
			}
		}
		return false;
	}
	bool exist(vector<vector<char>> &board, string word)
	{
		auto row = board.size();
		auto col = board[0].size();

		vector<bool> temp(col, false);
		vector<vector<bool>> temp_visted(row, temp);

		str = word;
		map = board;
		visted = temp_visted;

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (visted[i][j] == false && board[i][j] == word[0])
				{
					visted[i][j] = true;
					if (DFS(i, j, 1))
						return true;
					visted[i][j] = false;
				}
			}
		}
		return false;
	}
};
int main(void)
{
	vector<vector<char>> board = {{'C', 'A', 'A'}, {'A', 'A', 'A'}, {'B', 'C', 'D'}};
	string word = "AAB";
	Solution s1;
	if (s1.exist(board, word))
		cout << "66666" << endl;
	else
		cout << "false " << endl;
	return 0;
}
