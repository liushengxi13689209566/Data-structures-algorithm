/* 题目描述

其中系数aj都是整数满足0≤aj≤1000且至少有两个系数严格大于0，分别将n=1,n=2,n=3n...代入以上函数可以得到一个无穷长度的整数序列，即用8个系数a7,a6...a0可以唯一确定一个无穷长度的整数序列，现在给出k个通过以上方法定义的无穷序列，你需要求出将这些序列所有数字放在一起后，第n小的数字是多少？

输入描述:
第一行包含一个整数k,1≤k≤104

接下来k行，每行包含8个整数a7,a6,.....a0,表示一个函数的系数，0≤aj≤1000

最后一行包含一个整数n,1≤n≤105

输出描述:
输出对应的答案，保证最后的答案不超过1017

示例1
输入
复制
3
0 0 0 0 1 2 0 0
0 0 0 0 0 0 10 6
0 0 0 0 0 0 25 1
9
输出
复制
51
说明
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    cin >> k;
    vector<vector<int>> vv;
    int temp;
    while (k--)
    {
        vv.push_back(vector<int>());
        for (int i = 0; i < 8; i++)
        {
            cin >> temp;
            cin >> vv[i].push_back(temp);
        }
    }
    int n;
    cin >> n;
}