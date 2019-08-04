/*************************************************************************
	> File Name: 左旋转字符串.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  8/ 2 09:13:13 2019
 ************************************************************************/

#include <iostream>
using namespace std;
/*
汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，
即“XYZdefabc”。是不是很简单？OK，搞定它！
*/
class Solution
{
public:
	string LeftRotateString(string str, int n)
	{
		if(str.size()<= 0)
			return string();
		if(n ==  0)
			return str;
		string tt = str.substr(0, n );
		string rr = str.substr(n, str.size());
		return rr + tt;
	}
};