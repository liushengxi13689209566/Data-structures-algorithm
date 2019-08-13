/*************************************************************************
	> File Name: 网易_最优分割.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  8/11 20:29:12 2019
 ************************************************************************/

#include <iostream>
using namespace std;
/*
题目描述
依次给出n个正整数A1，A2，… ，An，将这n个数分割成m段，每一段内的所有数的和记为这一段的权重， m段权重的最大值记为本次分割的权重。问所有分割方案中分割权重的最小值是多少？
输入描述:
第一行依次给出正整数n，m，单空格切分；(n <= 10000, m <= 10000, m <= n)
第二行依次给出n个正整数单空格切分A1，A2，… ，An  (Ai <= 10000)
输出描述:
分割权重的最小值
示例1
输入
复制
5 3
1 4 2 3 5
输出
复制
5
说明
分割成 1  4 |   2   3  |   5  的时候，3段的权重都是5，得到分割权重的最小值。
笔记
收藏
纠错 */
#include <bits/stdc++.h>
using namespace std;
bool check(vector<int> &vv, int n, int m, int data)
{
	int count = 0;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (sum + vv[i] > data)
		{
			count++;
			sum = vv[i];
			if (count > m - 1)
			{
				return false;
			}
		}
		else
		{
			sum += vv[i];
		}
	}
	return true;
}
int bin_search(vector<int> &vv, int left, int right, int n, int m)
{
	int mid = 0;

	while (left < right)
	{
		mid = left + ((right - left) >> 1);
		if (check(vv, n, m, mid)) //满足划分，继续向左寻找
		{
			right = mid; //不减是因为无法确保减一之后的数是否满足划分
		}
		else //不满足划分，继续向右寻找,这里为啥直接就往后找了啊？难道前面的就能够确定不会了吗？
		{
			left = mid + 1;
		}
	}
	return left;
}
int main()
{
	int n, m, max_sum = 0, sum = 0;
	cin >> n >> m;
	vector<int> vv(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> vv[i];
		if (vv[i] > max_sum)
			max_sum = vv[i];
		sum += vv[i];
	}
	cout << bin_search(vv, max_sum, sum, n, m) << endl;
	return 0;
}
