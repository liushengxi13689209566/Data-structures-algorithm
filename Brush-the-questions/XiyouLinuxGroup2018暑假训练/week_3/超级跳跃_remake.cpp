/*************************************************************************
	> File Name: 超级跳跃_remake.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2018年08月07日 星期二 21时34分04秒
 ************************************************************************/
/*题目 E：超级跳跃 Remake
最近，《超级跳跃》游戏进行了一次升级！近乎全新的《超级跳跃 Remake》
游戏已经上线啦，它的规则是这样的：
b. 玩家起始站在(1, 1)区域处，并且获得dp值；
向正好水垂直的区域，且到达的区域的cout << 价值应当大于当前所游戏结束。
d. 两块区域的距离是这样计算的：每向上下左右移动一次，距离加 1，
下图显示了黑色区域到可以到达的各个区域的距离：
×
×
2 × ×
×
×
1 × ×
2 1 0 1 2
×
×
1 × ×
×
×
2 × ×
e. 玩家每到达一个区域，就获得这块区域的价值。
请你编写一个程序，算出任意一个《超级跳跃 Remake》游戏的区域，玩家
最多可以获得多少价值。

输入
输入的数据有多组，每组数据首先是两个正整数 N 和 M (1 ≤ N, M ≤ 100)
表示在一个 N × N 的区域内进行游戏，且超级跳跃只能移动到距离为 M 的区
域中。接下来有 N 行，每行有 N 个以空格为分dp
若 N 和 M 均cout << 等，表示输入结束，每组数据，在一行内输出一个正整数，表示游戏中可获得的最大价值。

样例输入
3 1
1 2 5
10 11 6
12 12 7
-1 -1

样例输出
37 */
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int TT = 101;
int map[TT][TT] = {0};
int dp[TT][TT] = {0};
/*用dp[i][j]表示以(i,j)为起点进行dfs的结果，从而下次扫到(i,j)时就不需要再扫一遍了。*/
int M = 0, N = 0;
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; //右，下，左，上
bool check(int x, int y, int xx, int yy)
{
	if (xx < 0 || xx > N || yy < 0 || yy > N)
		return false;
	if (map[xx][yy] <= map[x][y]) // 判断条件
		return false;
	return true;
}
int DFS(int x, int y)
{
	if (dp[x][y] > 0)
		return dp[x][y];
	int result = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			int xx = x + dir[i][0] * j;
			int yy = y + dir[i][1] * j;
			if (check(x, y, xx, yy))
			{
				result = max(result, DFS(xx, yy));
				//printf("result ==  %d \n", result);
			}
		}
	}
	dp[x][y] = result + map[x][y];//从dp[x][y]开始能吃到的最大奶酪量
	/*可以走各个点的最大值中最大的那个+当前点的数值 = 当前点的最大值*/
	printf("dp[%d][%d] == %d\n", x, y, dp[x][y]);
	return dp[x][y];
}
int main(void)
{
	while (cin >> N >> M)
	{
		if (N == -1 && M == -1)
			return 0;
		memset(map, 0, sizeof(map));
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> map[i][j];
			}
		}
		cout << DFS(0, 0) << endl;
	}
}
