/*************************************************************************
	> File Name: 超级跳跃_Remake.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2018年08月07日 星期二 09时44分29秒
 ************************************************************************/
/*题目 F：超级跳跃 2
广受好评的《超级跳跃》游戏终于出了新作品，你作为它的粉丝已经迫不及
待的想要购买了。当你到达电玩店时，发现店前已经排起了长队，加上你一
共有 N 个人之多！每个人单独购买自己所需要的产品所需 Ki 秒，也可以选择
和排在自己前面的那个人合作，这样的话则需要 Si 秒。现在是早上 8 点，若
这 N 个人采用了最快的方式买完了自己所需的产品，那么买完的时候是什么
时间呢？

输入
输入的数据首先是一个整数 C，表示有 C 组输入数据。每组数据首先是一个
正整数 N(1 ≤ N ≤ 10)，然后在下一行内有 N 个整数 K1，K2 … KN，表示 N
个人单独购买需要的时间，接下来有 N – 1 个整数 S1，S2 … SN-1，表示每个
人和前面那个人一起购买需要的时间。

输出
对于每组数据，在一行内输出 N 个人最快在何时全部完成购买。
输出格式为 HH:MM:SS am/pm，如开始时间就表示为 08:00:00 am，下午 2
时则表示为 14:00:00 pm。

样例输入
2
2
20 25
40
1
8

样例输出
08:00:40 am
08:00:08 am
*/
//F题中C的取值范围为1~10，N的取值范围为1~2000
#include <iostream>
#include <string.h>
#include <algorithm>
#include <climits>
using namespace std;
const int TT = 2000;
int F[2][TT] = {0}; // 2 行 ，最大是 N 列
int dp[TT] = {0};
int DP(int n)
{
	dp[0] = F[1][0];
	dp[1] = min(F[0][0], dp[0] + F[1][1]);

	for (int i = 2; i < n; i++)
		dp[i] = min(dp[i - 1] + F[1][i], dp[i - 2] + F[0][i - 1]);
		
	/*状态转移方程叙述：第n个人所用的时间就是 
	Min(前一个人所用的时间+第n个人单独用的时间，前n-2个人所用的时间+第n-1个人和第n个人时间和)*/
	return dp[n - 1];
}
int main(void)
{
	int C, N;
	while (cin >> C)
	{
		for (int k = 0; k < C; k++)
		{
			cin >> N;
			memset(F, 0, sizeof(F));
			for (int i = 0; i < N; i++)
				cin >> F[1][i];
			for (int j = 0; j < N - 1; j++)
				cin >> F[0][j];

			int temp = DP(N);

			int second = temp % 60;
			int hour = temp / 60 / 60 + 8;
			temp = temp / 60;
			int minutes = temp % 60;
			if (hour >= 12)
				printf("%02d:%02d:%02d pm\n", hour, minutes, second);
			else
				printf("%02d:%02d:%02d am\n", hour, minutes, second);
		}
	}
}
