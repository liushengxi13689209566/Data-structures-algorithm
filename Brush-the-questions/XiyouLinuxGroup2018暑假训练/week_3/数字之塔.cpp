/*************************************************************************
	> File Name: 数字之塔.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2018年08月06日 星期一 14时05分40秒
 ************************************************************************/

#include <iostream>
#include <string.h>
#include<algorithm>
using namespace std;
#define TT 200 //整数N(1 <= N <= 100)，表示数塔的高度
int F[TT][TT];
int DP(int row)
{
	for (int i = row - 2; i >= 0; i--)
	{
		for (int j = 0; j <= i; j++)
			F[i][j] = max(F[i][j] + F[i + 1][j], F[i][j] + F[i + 1][j + 1]);
	}
	return F[0][0];
}
int main(void)
{
	int C, N;
	while (cin >> C) // 1
	{
		for (int i = 0; i < C; i++)
		{
			memset(F, -1, sizeof(F));
			cin >> N;					 //5
			for (int j = 1; j <= N; j++) // 1--5
			{
				for (int k = 0; k < j; k++) //0 -- 1  ,0 --2, 0--3, 0--4
					cin >> F[j - 1][k];
			}
			cout << DP(N) << endl;
		}
	}
}
