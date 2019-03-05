/*************************************************************************
	> File Name: dfs.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2019年03月05日 星期二 16时11分01秒
 ************************************************************************/

#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <cmath>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;
class Solution
{
  public:
    int numIslands(vector<vector<char>> &grid)
    {
        auto row = grid.size();
        if (row <= 0)
            return 0;
        auto col = grid[0].size();

        vector<vector<bool>> temp_visted(row, vector<bool>(col, false));
        visted = temp_visted;

        int result = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (visted[i][j] == false && grid[i][j] == '1')
                {
                    visted[i][j] = true;
                    dfs(grid, i, j);
                    result++;
                }
            }
        }
        return result;
    }

  private:
    int dir[4][2] = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}};

    vector<vector<bool>> visted;

    bool check(vector<vector<char>> &grid, int i, int j)
    {
        //i 行　  j 列
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return false;
        if (visted[i][j] == true)
            return false;
        if (grid[i][j] == '0') //注意是字符，我就坑在了这里
            return false;
        return true;
    }
    void dfs(vector<vector<char>> &grid, int x, int y)
    {
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            if (check(grid, xx, yy))
            {
                visted[xx][yy] = true;
                dfs(grid, xx, yy);
            }
        }
    }
};
int main(void)
{
    vector<vector<char>> grid({{1, 1, 0, 0, 0}, {1, 1, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 1, 1}});
    Solution s1;
    cout << s1.numIslands(grid) << endl;
}