/*************************************************************************
	> File Name: graph.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2019年03月15日 星期五 20时30分40秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int DP()
{
}
int result = INT_MAX;
int huisu(const vector<vector<int>> &vv, int n, int i, int j, int dist)
{
    //到达最终地点
    if (i == n - 1 && j == n - 1)
    {
        if (dist < result) //更新 result
            result = dist;
        return 0;
    }
    if (i < n - 1) //向下走
        huisu(vv, n, i + 1, j, dist + vv[i][j]);
    if (j < n - 1) //向右走
        huisu(vv, n, i, j + 1, dist + vv[i][j]);
}

int DP1(const vector<vector<int>> &vv, int n, int i, int j)
{
    vector<vector<int>> result(n, vector<int>(n, 0));
    result[0][0] = vv[0][0];
    //填充行
    for (int i = 1; i < n; i++)
    {
        result[0][i] = result[0][i - 1] + vv[0][i];
    }
    //填充列
    for (int i = 1; i < n; i++)
    {
        result[i][0] = result[i - 1][0] + vv[i][0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            result[i][j] = std::min(result[i][j - 1], result[i - 1][j]) + vv[i][j];
        }
    }
    return result[n - 1][n - 1];
}

int main(void)
{
    vector<vector<int>> vv{{1, 3, 5, 9}, {2, 1, 3, 4}, {5, 2, 6, 7}, {6, 8, 4, 3}};
    // huisu(vv, vv.size(), 0, 0, 0);
    cout << DP1(vv, 4, 0, 0) << endl;
    // cout << result + vv[3][3] << endl;
}
