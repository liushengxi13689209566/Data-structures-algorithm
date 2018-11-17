/*************************************************************************
	> File Name: 最长回文子串.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2018年08月22日 星期三 23时04分10秒
 ************************************************************************/
/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba"也是一个有效答案。

示例 2：
输入: "cbbd"
输出: "bb"
*/
#include <iostream>
using namespace std;
/*穷举法：时间820ms */
class Solution
{
  public:
	string longestPalindrome(string s)
	{
		int len = s.size();
		string result;
		bool tag = true;
		int max = 0;
		int re_i = len - 1, re_j = len - 1;
		for (int i = 0; i < len; i++)
		{
			for (int j = len - 1; j > i; j--)
			{
				tag = true;
				if (s[i] == s[j])
				{
					int dup_i, dup_j;
					for (dup_i = i + 1, dup_j = j - 1; dup_i <= dup_j; dup_i++, dup_j--)
					{
						if (s[dup_i] != s[dup_j])
						{
							tag = false;
							break;
						}
					}
					if (tag) //回文
					{
						if (max < (j - i))
						{
							max = j - i;
							re_i = i;
							re_j = j;
						}
					}
				}
			}
		}
		for (int tmp = re_i; tmp <= re_j; tmp++)
			result += s[tmp];
		return result;
	}
};
/*DP 时间：80 ms */
/* class Solution
{
  public:
	string longestPalindrome(string s)
	{
		int dp[1001][1001] = {0};
		auto len = s.size();
		for (int i = 0; i < len; i++)
		{
			dp[i][i] = 1;
			if (i < len - 1 && s[i] == s[i + 1])
			{
				dp[i][i + 1] = 1;
				dp[i + 1][i] = 1;
			}
		}
		int i, j, L;
		int dup_i = len - 1, dup_j = len - 1;
		for (L = 2; L <= len; L++)
		{
			for (i = 0; i + L - 1 < len; i++)
			{
				j = i + L - 1;
				if (s[i] == s[j] && dp[i + 1][j - 1])
				{
					dp[i][j] = 1;
					dup_i = i;
					dup_j = j;
				}
			}
		}
		string result;
		for (int t = dup_i; t <= dup_j; t++)
			result += s[t];
		return result;
	}
}; */

/*4 ms*/
class Solution
{
  public:
	string longestPalindrome(string s)
	{
		int len = s.size();
		if (!len)
			return "";
		if (len == 1)
			return s;
		int min_start = 0, max_len = 1;
		for (int i = 0; i < len;)
		{
			if (len - i <= max_len / 2)
				break;
			int j = i, k = i;
			while (k < len - 1 && s[k + 1] == s[k])
				++k; // Skip duplicate characters.
			i = k + 1;
			while (k < len - 1 && j > 0 && s[k + 1] == s[j - 1])
			{
				++k;
				--j;
			} // Expand.
			int new_len = k - j + 1;
			if (new_len > max_len)
			{
				min_start = j;
				max_len = new_len;
			}
		}
		return s.substr(min_start, max_len);
	}
};

int main(void)
{
	Solution s1;
	s1.longestPalindrome("cbbd");
}
