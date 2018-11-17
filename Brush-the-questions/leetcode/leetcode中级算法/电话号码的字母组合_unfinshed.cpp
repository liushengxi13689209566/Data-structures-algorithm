/*************************************************************************
	> File Name: 电话号码的字母组合.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2018年08月27日 星期一 19时35分05秒
 ************************************************************************/
/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母 。
示例 :
输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
说明:
尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。*/
#include <iostream>
using namespace std;
class Solution
{
  private:
	int visted[][];
	vector<string> result;

  private:
	void dfs()
	{
		if ()
		{
			result.push_back();
			return ;
		}
		for (int)
		{
			if (check())
			{
				visted = 1;
				dfs();
				visted = 0;
			}
		}
	}

  public:
	vector<string> letterCombinations(string digits)
	{
		for()
		dfs();
	}
};
