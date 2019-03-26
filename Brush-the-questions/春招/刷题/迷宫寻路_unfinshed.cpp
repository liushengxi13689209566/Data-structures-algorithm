/* 题目描述
假设一个探险家被困在了地底的迷宫之中，要从当前位置开始找到一条通往迷宫出口的路径。迷宫可以用一个二维矩阵组成，有的部分是墙，有的部分是路。迷宫之中有的路上还有门，每扇门都在迷宫的某个地方有与之匹配的钥匙，只有先拿到钥匙才能打开门。请设计一个算法，帮助探险家找到脱困的最短路径。如前所述，迷宫是通过一个二维矩阵表示的，每个元素的值的含义如下 0-墙，1-路，2-探险家的起始位置，3-迷宫的出口，大写字母-门，小写字母-对应大写字母所代表的门的钥匙
输入描述:
迷宫的地图，用二维矩阵表示。第一行是表示矩阵的行数和列数M和N
后面的M行是矩阵的数据，每一行对应与矩阵的一行（中间没有空格）。M和N都不超过100, 门不超过10扇。
输出描述:
路径的长度，是一个整数
示例1
输入
复制
5 5
02111
01a0A
01003
01001
01111
输出
复制
7 */


//做出来不对，有点理解不了visted[][][]的做法

#include <bits/stdc++.h>
using namespace std;
//找到一条路径，DFS ,.最短路径　BFS

struct Node
{
    Node() = default;
    Node(int x_, int y_, int step_) : x(x_), y(y_), step(step_) {}
    int x, y, step;
    bool yaoshi[26] = {false}; //用数组下标作为有没有钥匙的标记
};
char marze[100][100];
bool visted[100][100] = {false};

int ret = 0;
queue<Node> qq;
int m, n;

int dir[4][2] = {
    {1, 0},
    {0, 1},
    {0, -1},
    {-1, 0}};

// bool check(int i, int j)
// {
//     if (i < 0 || i >= m || j < 0 || j >= n)
//         return false;
//     if (visted[i][j]) //已经访问过了
//         return false;
//     if (marze[i][j] == '0') //表示墙
//         return false;
//     return true;
// }

void BFS(int x, int y)
{

    Node next;
    Node now(x, y, 0);

    qq.push(now);

    while (!qq.empty())
    {
        now = qq.front();
        qq.pop();

        //到达出口
        if ('3' == marze[now.x][now.y])
        {
            ret = now.step;
            return;
        }
        for (int k = 0; k < 4; k++)
        {
            next.x = now.x + dir[k][0];
            next.y = now.y + dir[k][1];

            if (next.x < 0 || next.x >= m || next.y < 0 || next.y >= n || '0' == marze[next.x][next.y])
                continue;

            //走到了有钥匙的地方
            if (marze[next.x][next.y] >= 'a' && marze[next.x][next.y] <= 'z')
                next.yaoshi[marze[next.x][next.y] - 'a'] = true;

            if (marze[next.x][next.y] >= 'A' && marze[next.x][next.y] <= 'Z') //门，去找钥匙
            {
                if (next.yaoshi[marze[next.x][next.y] - 'A'] == false) //没有对应的钥匙
                    continue;
            }
            if (visted[next.x][next.y] == false)
            {
                next.step = now.step + 1;
                visted[next.x][next.y] = true;
                cout << next.x << " : " << next.y << " : " << next.step << endl;
                qq.push(next);
            }
        }
    }
}
int main()
{
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> marze[i][j];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (marze[i][j] == '2')
            {
                visted[i][j] = true;
                BFS(i, j);
                cout << ret << endl;
                return 0;
            }
        }
    }
}