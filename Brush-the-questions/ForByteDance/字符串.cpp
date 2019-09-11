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

/*请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'
表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 
在本题中，匹配是指字符串的所有字符匹配整个模式。
例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，
但是与"aa.a"和"ab*a"均不匹配
 */
class Solution
{
public:
	bool match(char *str, char *pattern)
	{
	}
};

/*
    解这题需要把题意仔细研究清楚，反正我试了好多次才明白的。
    首先，考虑特殊情况：
         1>两个字符串都为空，返回true
         2>当第一个字符串不空，而第二个字符串空了，返回false（因为这样，就无法
            匹配成功了,而如果第一个字符串空了，第二个字符串非空，还是可能匹配成
            功的，比如第二个字符串是“a*a*a*a*”,由于‘*’之前的元素可以出现0次，
            所以有可能匹配成功）
    之后就开始匹配第一个字符，这里有两种可能：匹配成功或匹配失败。但考虑到pattern
    下一个字符可能是‘*’， 这里我们分两种情况讨论：pattern下一个字符为‘*’或
    不为‘*’：
          1>pattern下一个字符不为‘*’：这种情况比较简单，直接匹配当前字符。如果
            匹配成功，继续匹配下一个；如果匹配失败，直接返回false。注意这里的
            “匹配成功”，除了两个字符相同的情况外，还有一种情况，就是pattern的
            当前字符为‘.’,同时str的当前字符不为‘\0’。
          2>pattern下一个字符为‘*’时，稍微复杂一些，因为‘*’可以代表0个或多个。
            这里把这些情况都考虑到：
               a>当‘*’匹配0个字符时，str当前字符不变，pattern当前字符后移两位，
                跳过这个‘*’符号；
               b>当‘*’匹配1个或多个时，str当前字符移向下一个，pattern当前字符
                不变。（这里匹配1个或多个可以看成一种情况，因为：当匹配一个时，
                由于str移到了下一个字符，而pattern字符不变，就回到了上边的情况a；
                当匹配多于一个字符时，相当于从str的下一个字符继续开始匹配）
    之后再写代码就很简单了。
*/
class Solution
{
public:
	bool match(char *str, char *pattern)
	{
		if (*str == '\0' && *pattern == '\0')
			return true;
		if (*str != '\0' && *pattern == '\0')
			return false;
		//if the next character in pattern is not '*'
		if (*(pattern + 1) != '*')
		{
			if (*str == *pattern || (*str != '\0' && *pattern == '.'))
				return match(str + 1, pattern + 1);
			else
				return false;
		}
		//if the next character is '*'
		else
		{
			if (*str == *pattern || (*str != '\0' && *pattern == '.'))
				return match(str, pattern + 2) || match(str + 1, pattern);
			else
				return match(str, pattern + 2);
		}
	}
};
