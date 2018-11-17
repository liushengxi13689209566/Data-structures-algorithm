/*************************************************************************
	> File Name: 闪现.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2018年08月02日 星期四 22时08分26秒
 ************************************************************************/
/*Farmer John has been informed of the location of a fugitive cow 
and wants to catch her immediately. 
He starts at a point N (0 ≤ N ≤ 100,000) on a number line 
and the cow is at a point K (0 ≤ K ≤ 100,000) on the same number line. 
Farmer John has two modes of transportation: walking and teleporting.

* Walking: FJ can move from any point X to the points X - 1 or X + 1 in a single minute
* Teleporting: FJ can move from any point X to the point 2 × X in a single minute.

If the cow, unaware of its pursuit, 
does not move at all, 
how long does it take for Farmer John to retrieve it?

Input
Line 1: Two space-separated integers: N and K
Output
Line 1: The least amount of time, in minutes,
 it takes for Farmer John to catch the fugitive cow.
Sample Input
5 17
Sample Output
4
Hint
The fastest way for Farmer John to reach the fugitive cow is to move along
 the following path: 5-10-9-18-17, which takes 4 minutes.*/
//思路： 因为是找最值，所以策略是 BFS
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
#define MAX  100001 //草，原来那么多的RuntimeError,全是因为我数组开得太大了造成的，草草草草
int n = 0, k = 0;
int result = 0; //存放最终结果
bool visted[MAX] = {false};
int BFS(int start) // 1
{
	queue<int> QQ;
	QQ.push(start);
	visted[start] = true;
	int Vnow, Vnext;
	while (!QQ.empty())
	{
		int loop_size = QQ.size();
		for (int j = 0; j < loop_size; j++) //有多少出多少，分层处理
		{
			Vnow = QQ.front();
			QQ.pop();
			for (int i = 0; i < 3; i++)
			{
				if (i == 0)
					Vnext = Vnow + 1;
				if (i == 1)
					Vnext = Vnow - 1;
				if (i == 2)
					Vnext = Vnow * 2;
				if (Vnext == k)
					return 0;
				if ( Vnext >= 0 && Vnext < MAX && visted[Vnext] == false )
				{
					QQ.push(Vnext);
					visted[Vnext] = true;
				}
			}
		}
		result++;
	}
}
int main(void)
{
	while (cin >> n >> k)
	{
		result = 0;
		memset(visted, 0, sizeof(visted));
		if (n >= k)
		{
			cout << n - k << endl;
			continue;
		}
		BFS(n);
		cout << result + 1 << endl;
	}
	return 0;
}
