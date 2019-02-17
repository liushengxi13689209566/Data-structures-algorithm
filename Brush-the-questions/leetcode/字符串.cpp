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