/*************************************************************************
	> File Name: 字符串.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  8/ 7 22:25:53 2019
 ************************************************************************/

#include <iostream>
using namespace std;
/*
过了一点样例。没有全过，但是感觉思路很巧妙。

#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n,t;
    cin >> n >> t ;
    string str ;
    cin >> str ;
    int type,x,new_head = 0 ; 
    while(t--)
    {
        cin >> type >> x; 
        if(type == 1)
        {
             new_head =  str.size()-x;       
        }
        else
        {
            cout << str[(new_head+x)%str.size()] << endl;
        }
    }
} 
题目描述
小明同学需要对一个长度为 N 的字符串进行处理，他需要按照要求执行若干步骤，每个步骤都均为下面 2 种操作中的一种，2 种操作如下：
TYPE 1. 从字符串结尾开始算起，将第 X 个字符之前的字符移动到字符串末尾
TYPE 2. 输出字符串索引为 X 的字符
小明尝试了很久没能完成，你可以帮他解决这个问题吗？
输入描述:
第一行，包含两个整数，字符串的长度 N 和操作次数T；
第二行为要操作的原始字符串；

之后每行都是要执行的操作类型 TYPE 和操作中 X 的值，均为整数。

输入范围：
字符串长度 N：1 <= N <= 10000
操作次数 T：1 <= T <= 10000
操作类型 TYPE：1 <= TYPE<= 2
变量 X：0 <= X < N
输出描述:
操作的执行结果
示例1
输入
复制
6 2
xiaomi
1 2
2 0
输出
复制
m
说明
*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n, t;
	cin >> n >> t;
	string str;
	cin >> str;
	int type, x, new_head = 0;
	int len = str.size();
	while (t--)
	{
		cin >> type >> x;
		if (type == 1)
		{
			str = str.substr(len - x, len) + str.substr(0, len - x);
		}
		else
		{
			cout << str[x] << endl;
		}
	}
}

