/* 
32. 最长有效括号




题目描述
评论 (69)
题解
提交记录
给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

示例 1:

输入: "(()"
输出: 2
解释: 最长有效括号子串为 "()"
示例 2:

输入: ")()())"
输出: 4
解释: 最长有效括号子串为 "()()"
在真实的面试中遇到过这道题？

是

否 
DP

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int longestValidParentheses(string s)
    {
        int len = s.length();
        if (len <= 1)
            return 0;

        vector<int> dp(len, 0);
        int curMax = 0;

        for (int i = 1; i < len; i++)
        {
            if (s[i] == ')')
            {
                if (s[i - 1] == '(')
                {
                    dp[i] =
                }
            }
            dp[i] = dp[i - 1] + 2;
            else dp[i] = dp[i - 1] + 1;
        }
        int max = 0;
        for (auto i : dp)
            if (i > max)
                max = i;
        return max;
    }
};