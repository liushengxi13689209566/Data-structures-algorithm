
/*定义一个二维数组： 

int maze[5][5] = {

	0, 1, 0, 0, 0,

	0, 1, 0, 1, 0,

	0, 0, 0, 0, 0,

	0, 1, 1, 1, 0,

	0, 0, 0, 1, 0,

};

它表示一个迷宫，其中的1表示墙壁，0表示可以走的路，只能横着走或竖着走，不能斜着走，要求编程序找出从左上角到右下角的最短路线。
Input
一个5 × 5的二维数组，表示一个迷宫。数据保证有唯一解。
Output
左上角到右下角的最短路径，格式如样例所示。
Sample Input
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
Sample Output
(0, 0)
(1, 0)
(2, 0)
(2, 1)
(2, 2)
(2, 3)
(2, 4)
(3, 4)
(4, 4)*/
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <stdio.h>
/*根据广度优先搜索的话，搜索到终点时，该路径一定是最短的*/
using namespace std;
struct Node
{
	int x, y, before;
	Node() = default;
	Node(int _x, int _y, int _index) : x(_x), y(_y), before(_index) {}
	bool check()
	{
		if (x < 0 || x > 4 || y < 0 || y > 4)
			return false;
		else
			return true;
	}
} result[20];		  //记录路径
int maze[5][5] = {0}; //迷宫
int index = 0;
bool bfs(Node &start, Node &end)
{
	bool visted[5][5] = {false}; //标记数组
	int dir[4][2] = {
		{0, 1},
		{1, 0},
		{0, -1},
		{-1, 0}};
	queue<Node> QQ;
	QQ.push(start);
	visted[start.x][start.y] = true;
	Node Vnow, Vnext;
	while (!QQ.empty())
	{
		Vnow = QQ.front();
		QQ.pop();
		result[index].x = Vnow.x;
		result[index].y = Vnow.y;
		result[index].before = Vnow.before;
		index++;

		for (int i = 0; i < 4; ++i)
		{
			Node Vnext(Vnow.x + dir[i][0], Vnow.y + dir[i][1], index - 1);// 注意这里

			if (Vnext.x == end.x && Vnext.y == end.y)
			{
				result[index].x = end.x;
				result[index].y = end.y;
				result[index].before = index - 1;
				return true;
			}
			if (Vnext.check() && !visted[Vnext.x][Vnext.y] && !maze[Vnext.x][Vnext.y])
			{
				QQ.push(Vnext);
				visted[Vnext.x][Vnext.y] = true;
			}
		}
	}
	//数据保证有唯一解
}
void output(Node tmp)
{
	if (tmp.before == 0 && tmp.x == 0 && tmp.y == 0)
	{
		printf("(%d, %d)\n", tmp.x, tmp.y);
	}
	else
	{
		output(result[tmp.before]);
		printf("(%d, %d)\n", tmp.x, tmp.y);
	}
}
int main(void)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> maze[i][j];
		}
	}
	Node start(0, 0, 0);
	Node end(4, 4, 0);
	bfs(start, end);
	output(result[index]);
}
