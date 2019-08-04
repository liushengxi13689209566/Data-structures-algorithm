/*************************************************************************
	> File Name: 跳台阶.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  8/ 2 08:59:16 2019
 ************************************************************************/

#include <iostream>
using namespace std;
/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级。
求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
*/
class Solution
{
public:
	int jumpFloor(int number)
	{
		vector<int> res(number + 1, 0);
		res[1] = 1;
		res[2] = 2;
		for (int i = 3; i <= number; i++)
		{
			res[i] = res[i - 1] + res[i - 2];
		}
		return res[number];
	}
};
/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/
class Solution
{
public:
	int jumpFloorII(int number)
	{
		vector<int> res(number + 1, 0);
		res[1] = 1;
		res[2] = 2;
		for (int i = 3; i <= number; i++)
		{
			for (int j = 1; j < i; j++) //1 ----- n
			{
				res[i] += res[j];
			}
			res[i] += 1;
		}
		return res[number];
	}
};