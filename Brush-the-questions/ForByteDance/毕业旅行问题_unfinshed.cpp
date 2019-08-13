/*************************************************************************
	> File Name: 毕业旅行问题.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  8/ 6 09:07:40 2019
 ************************************************************************/

#include <iostream>
using namespace std;
/*
题目描述
小明目前在做一份毕业旅行的规划。打算从北京出发，分别去若干个城市，然后再回到北京，
每个城市之间均乘坐高铁，且每个城市只去一次。由于经费有限，
希望能够通过合理的路线安排尽可能的省一些路上的花销。给定一组城市和每对城市之间的火车票的价钱，
找到每个城市只访问一次并返回起点的最小车费花销。
输入描述:
城市个数n（1<n≤20，包括北京）

城市间的车票价钱 n行n列的矩阵 m[n][n]
输出描述:
最小车费花销 s
示例1
输入
复制
4
0 2 6 5
2 0 4 4
6 4 0 2
5 4 2 0
输出
复制
13
说明
共 4 个城市，城市 1 和城市 1 的车费为0，
城市 1 和城市 2 之间的车费为 2，城市 1 和城市 3 之间的车费为 6，
城市 1 和城市 4 之间的车费为 5，依次类推。假设任意两个城市之间均有单程票可购买，
且票价在1000元以内，无需考虑极端情况。
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int dir[4] = {};

int DFS(int x, int y, vector<vector<int>> &visted, vector<vector<int>> &m, int money)
{
	for (int i = 0; i < 3; i++)
	{
		int xx = ;
		int yy = ;
		if (visted[xx][yy] == 0)
		{
			visted[xx][yy] == 1;
			DFS(xx, yy, );
			visted[xx][yy] == 0;
		}
	}
}
int main(void)
{
	int n;
	cin >> n;
	vector<vector<int>> m(n, vector<int>(n, 0));
	vector<vector<int>> visted(n, vector<int>(n, 0));

	visted[0][0] = 1;
	int money = 0;

	cout << DFS(0, 0, visted, m, money) << endl;
}
