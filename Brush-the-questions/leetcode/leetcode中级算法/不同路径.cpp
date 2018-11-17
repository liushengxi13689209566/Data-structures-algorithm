/*************************************************************************
	> File Name: 不同路径.cpp
	> Author: Liu Shengxi
	> Mail: 13689209566@163.com
	> Created Time: 2018年07月19日 星期四 09时19分21秒
 ************************************************************************/
/*一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

问总共有多少条不同的路径？



例如，上图是一个7 x 3 的网格。有多少可能的路径？

说明：m 和 n 的值均不超过 100。

示例 1:

输入: m = 3, n = 2
输出: 3
解释:
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向右 -> 向下
2. 向右 -> 向下 -> 向右
3. 向下 -> 向右 -> 向右
示例 2:

输入: m = 7, n = 3
输出: 28*/
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int> >  path(m, vector<int>(n, 0));

		path[0][0] = 1 ;
		if ( n > 1 )
			path[0][1] = 1 ;
		if ( m > 1 )
			path[1][0] = 1 ;

		for (int i =  0 ; i < m ; ++i)
		{
			for (int j = 0 ; j < n; ++j)
			{
				if ( i - 1 < 0  && j - 1 > 0 )
					path[i][j] =  path[i][j - 1];

				if ( j - 1 < 0  && i - 1 > 0)
					path[i][j] =  path[i - 1][j];

				if ((i - 1) >= 0 && (j - 1) >= 0 )
					path[i][j] = path[i - 1][j] + path[i][j - 1];
			}
		}
		return path[m - 1][n - 1];
	}
};
int main(void) {
	Solution s1 ;
	int tt = s1.uniquePaths(7, 3);
	cout << " tt == " << tt << endl ;


	tt = s1.uniquePaths(3, 2);
	cout << " tt == " << tt << endl ;






	tt = s1.uniquePaths(1, 2);
	cout << " tt == " << tt << endl ;
	return 0 ;
}

