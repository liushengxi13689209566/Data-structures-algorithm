/*************************************************************************
	> File Name: 反转字符串.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2019年02月17日 星期日 11时05分55秒
 ************************************************************************/

#include <iostream>
using namespace std;
/*编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。

不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。

你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。

示例 1：

输入：["h","e","l","l","o"]
输出：["o","l","l","e","h"]
示例 2：

输入：["H","a","n","n","a","h"]
输出：["h","a","n","n","a","H"]
*/
class Solution
{
  public:
    void reverseString(vector<char> &s)
    {
        int len = s.size();
        if (len <= 0)
            return;
        for (int i = 0, j = len - 1; i < j; i++, j--)
        {
            swap(s[i], s[j]);
        }
    }
};

/*给定一个字符串，逐个翻转字符串中的每个单词。

示例:  

输入: "the sky is blue",
输出: "blue is sky the".
说明:

无空格字符构成一个单词。
输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
进阶: 请选用C语言的用户尝试使用 O(1) 空间复杂度的原地解法。

在真实的面试中遇到过这道题？*/
//　未通过
class Solution
{
  public:
    void reverseWords(string &s)
    {
        string result;
        int tag = s.size() - 1;

        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == ' ' || i == 0)
            {
                int j;
                if (i == 0)
                {
                    j = i;
                    tag--;
                }
                else
                    j = i + 1;
                for (; j <= tag; j++)
                    result += s[j];

                if (tag == s.size() - 1)
                    result += ' ';

                tag = i;
            }
        }
        s = result;
    }
};
/*请你来实现一个 atoi 函数，使其能将字符串转换成整数。

首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。

当我们寻找到的第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字组合起来，作为该整数的正负号；假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。

该字符串除了有效的整数部分之后也可能会存在多余的字符，这些字符可以被忽略，它们对于函数不应该造成影响。

注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换。

在任何情况下，若函数不能进行有效的转换时，请返回 0。

说明：

假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−231,  231 − 1]。如果数值超过这个范围，qing返回  INT_MAX (231 − 1) 或 INT_MIN (−231) 。

示例 1:

输入: "42"
输出: 42
示例 2:

输入: "   -42"
输出: -42
解释: 第一个非空白字符为 '-', 它是一个负号。
     我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。
示例 3:

输入: "4193 with words"
输出: 4193
解释: 转换截止于数字 '3' ，因为它的下一个字符不为数字。
示例 4:

输入: "words and 987"
输出: 0
解释: 第一个非空字符是 'w', 但它不是数字或正、负号。
     因此无法执行有效的转换。
示例 5:

输入: "-91283472332"
输出: -2147483648
解释: 数字 "-91283472332" 超过 32 位有符号整数范围。 
     因此返回 INT_MIN (−231) 。
"42"
"   -42"
"4193 with words"
"words and 987"
"-91283472332"
*/
class Solution
{
  public:
    int myAtoi(string str)
    {
        double result = 0;
        int tag = 1;
        int frist = 0;
        while (str[frist] == ' ')
            frist++;

        switch (str[frist])
        {
        case '-':
            frist++;
            tag = -1;
            break;
        case '+':
            frist++;
            break;
        }

        for (int i = frist; i < str.size(); i++)
        {

            if (str[i] <= '9' && str[i] >= '0')
                result = result * 10 + (str[i] - '0');
            else
                break;
        }
        result *= tag;
        if (result > INT_MAX)
            return INT_MAX;
        else if (result < INT_MIN)
            return INT_MIN;
        else
            return result;
    }
};
/*
给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

示例 1:

输入: "Let's take LeetCode contest"
输出: "s'teL ekat edoCteeL tsetnoc" 
注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。
*/
class Solution
{
  public:
    string reverseWords(string s)
    {
        int start = 0, k = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ' || i == s.size() - 1)
            {
                // reserve(start,i);
                if (i == s.size() - 1)
                    k = i;
                else
                    k = i - 1;
                for (int j = start; j < k; j++, k--)
                {
                    swap(s[j], s[k]);
                }
                start = i + 1;
            }
        }
        return s;
    }
};