/*************************************************************************
	> File Name: 最长递增子序列.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2019年03月17日 星期日 19时34分59秒
 ************************************************************************/

#include <iostream>
using namespace std;
/*
题目描述
给定一个序列 An = a1 ,a2 ,  ... , an ，找出最长的子序列使得对所有 i < j ，ai < aj 。求出这个子序列的长度
输入描述:
输入的序列
输出描述:
最长递增子序列的长度
示例1
输入
复制
1 -1 2 -2 3 -3 4
输出
复制
4
说明
*/
#include <bits/stdc++.h>
using namespace std;
//不连续的
int main()
{
    vector<int> vv;
    int temp;
    while (cin >> temp)
        vv.push_back(temp);
    vector<int> dp(vv.size(), 0);
    //表示以 i 结尾的最长递增子序列的长度
    dp[0] = 1;
    for (int i = 1; i < vv.size(); i++)
    {
        if (vv[i] > vv[i - 1])
            dp[i] = dp[i - 1] + 1;
        else
            dp[i] = dp[i - 1];
    }
    cout << dp[vv.size() - 1] << endl;
}