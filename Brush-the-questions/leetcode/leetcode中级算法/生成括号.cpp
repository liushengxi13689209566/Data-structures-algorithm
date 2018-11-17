/*************************************************************************
	> File Name: 生成括号.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2018年08月21日 星期二 14时29分57秒
 ************************************************************************/
/*给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

例如，给出 n = 3，生成结果为：

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
	int leftnum;
	int rightnum;
	vector<string> result;
	string path;

  public:
	void DFS(int leftnum, int rightnum, string path)
	{
		if (leftnum == 0 && rightnum == 0)
		{
			result.push_back(path);
			return;
		}
		if (leftnum > 0)
		{
			DFS(leftnum - 1, rightnum, path + "(");
		}
		if (rightnum > 0 && leftnum < rightnum)
		{
			DFS(leftnum, rightnum - 1, path + ")");
		}
	}
	vector<string> generateParenthesis(int n)
	{
		leftnum = n;
		rightnum = n;
		if (n == 0)
		{
			result.push_back(path);
			return result;
		}
		DFS(leftnum - 1, rightnum, path + "(");
		return result;
	}
};
