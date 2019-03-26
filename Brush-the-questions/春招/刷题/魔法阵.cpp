/* 题目描述
小Q搜寻了整个魔法世界找到了四块魔法石所在地，当4块魔法石正好能构成一个正方形的时候将启动魔法阵，
小Q就可以借此实现一个愿望。

现在给出四块魔法石所在的坐标，小Q想知道他是否能启动魔法阵

输入描述:
输入的第一行包括一个整数（1≤T≤5）表示一共有T组数据

每组数据的第一行包括四个整数x[i](0≤x[i]≤10000)，即每块魔法石所在的横坐标

每组数据的第二行包括四个整数y[i](0≤y[i]≤10000),即每块魔法石所在的纵坐标
输出描述:
对于每组数据，如果能启动魔法阵输出“Yes”否则输出“No”。
示例1
输入
复制
3
0022
0202
0156
1605
0077
0303
输出
复制
Yes
Yes
No
说明
判断　对角线是否相等
 */
#include <bits/stdc++.h>
using namespace std;

int fun(int x1, int y1, int x2, int y2)
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
int main(void)
{
    int t;
    cin >> t;
    int row[4] = {0};
    int col[4] = {0};
    while (t--)
    {
        for (int i = 0; i < 4; i++)
        {
            cin >> row[i];
        }
        for (int i = 0; i < 4; i++)
        {
            cin >> col[i];
        }
        if (fun(row[1], col[1], row[3], col[3]) == fun(row[0], col[0], row[2], col[2]))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}
