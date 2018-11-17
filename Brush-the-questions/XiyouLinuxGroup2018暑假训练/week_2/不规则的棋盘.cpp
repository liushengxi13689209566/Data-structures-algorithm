/*************************************************************************
	> File Name: 不规则的棋盘.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2018年08月01日 星期三 19时20分35秒
 ************************************************************************/
/*在一个给定形状的棋盘（形状可能是不规则的）上面摆放棋子，棋子没有区别。要求摆放时任意的两个棋子不能放在棋盘中的同一行或者同一列，请编程求解对于给定形状和大小的棋盘，摆放k个棋子的所有可行的摆放方案C。
Input
输入含有多组测试数据。 
每组数据的第一行是两个正整数，n k，用一个空格隔开，表示了将在一个n*n的矩阵内描述棋盘，以及摆放棋子的数目。 n <= 8 , k <= n 
当为-1 -1时表示输入结束。 
随后的n行描述了棋盘的形状：每行有n个字符，其中 # 表示棋盘区域， . 表示空白区域（数据保证不出现多余的空白行或者空白列）。 
Output
对于每一组数据，给出一行输出，输出摆放的方案数目C （数据保证C<2^31）。
Sample Input
2 1
#.
.#
4 4
...#
..#.
.#..
#...
-1 -1
Sample Output
2
1*/
//思路： DFS + 不同行不同列
#include <iostream>
using namespace std;
char map[10][10] = {0};
int n = 0, k = 0; // n*n 的棋盘，k个棋子
int count = 0;	// 记录方案数目
int temp = 0;
bool col[10] = {false}; //对列进行标记，然后按行进行搜索
int DFS(int x)
{
	if (temp == k)
	{
		count++;
		return 0;
	}
	if ( x >= n ) //超出界限
		return 0;
	for (int i = 0; i < n; i++) //控制列
	{
		if (map[x][i] == '#' && col[i] == false)
		{
			col[i] = true;
			temp++;
			DFS(x + 1);
			col[i] = false;
			temp--;
		}
	}
	DFS(x + 1);
	/*为了避免：
	n= 2,k=1

	.#  
	#.
	的情况
	*/
	return 0;
}
int main(void)
{
	while (cin >> n >> k)  
	{
		if (n == -1 && k == -1)
			return 0;
		for (int i = 0; i < n; i++)
			scanf("%s", map[i]);
		count = 0;
		DFS(0); //从第0行开始
		cout << count << endl;
	}
	return 0;
}
