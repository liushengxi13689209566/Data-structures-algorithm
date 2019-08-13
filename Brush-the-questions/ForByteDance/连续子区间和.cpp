/*************************************************************************
	> File Name: 连续子区间和.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  8/ 9 09:33:43 2019
 ************************************************************************/

/*题目描述
小M给你一串含有c个正整数的数组, 想让你帮忙求出有多少个下标的连续区间, 它们的和大于等于x。

输入描述:
第一行两个整数c x（0 < c <= 1000000, 0 <= x <= 100000000)

第二行有c个正整数（每个正整数小于等于100)。
输出描述:
输出一个整数，表示所求的个数。
示例1
输入
复制
3 6
2 4 7
输出
复制
4
说明
对于有3个整数构成的数组而言，总共有6个下标连续的区间，他们的和分别为：

2 = 2

4 = 4

7 = 7

2 + 4 = 6

4 + 7 = 11

2 + 4 + 7 = 13

其中有4个和大于等于6，所以答案等于4。 */

#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int c, x;
	cin >> c >> x;
	vector<int> vv(c, 0);
	for (int i = 0; i < c; i++)
		cin >> vv[i];

	for (int i = 0; i < c; i++)
	{
		for (int j = i; j >= 0; j--)
		{
			sum += vv[]
		}
	}
}

#include <bits/stdc++.h>
using namespace std;

struct P
{
	int l, r;
	bool flag;
};
int main()
{
	string s;
	cin >> s;
	map<char, P> M;
	int n = s.length();
	for (int i = 0; i < n; i++)
	{
		if (M.find(s[i]) == M.end())
		{
			M[s[i]].l = i;
			M[s[i]].flag = false;
		}
		M[s[i]].r = i;
	}
	if (n == 0)
		cout << 0 << endl;
	else
	{
		int l = M[s[0]].l;
		int r = M[s[0]].r;
		M[s[0]].flag = true;
		for (int i = 1; i < n; i++)
		{
			if (M[s[i]].flag)
				continue;
			M[s[i]].flag = true;
			int pl = M[s[i]].l;
			int pr = M[s[i]].r;
			if (pl > r)
			{
				cout << r - l + 1 << " ";
				l = pl;
				r = pr;
			}
			else if (pr > r)
				r = pr;
		}
		cout << r - l + 1 << endl;
	}
	return 0;
}
