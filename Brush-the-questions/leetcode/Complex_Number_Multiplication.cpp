/*************************************************************************
	> File Name: Complex_Number_Multiplication.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月11日 星期一 20时41分48秒
 ************************************************************************/
/*题目描述：
* 给定两个代表两个复数的字符串。

你需要返回一个代表它们乘法的字符串。根据定义，注意i 2 = -1。

例1：
输入： “1 + 1i”，“1 + 1i”
 输出： “0 + 2i”
 说明：（1 + i）*（1 + i）= 1 + i 2 + 2 * i = 2i，到0 + 2i的形式。
例2：
输入： “1 + -1i”，“1 + -1i”
 输出： “0 + -2i”
 说明：（1-i）*（1-i）= 1 + i 2 -2 * i = -2i你需要把它转换成0 + -2i的形式。
注意：

输入的字符串不会有多余的空白。
输入字符串将以+ bi的形式给出，其中整数a和b都将属于[-100，100]的范围。和输出也应该是这种形式。
*/

/*
* 题目大意与思路：处理a，b 找出A,B,C,D 然后组合string 
* */
#include<iostream>
#include<string.h>
using namespace std;
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int A,B,C,D;
        int i = 0  ;
        A=B=C=D = 0 ;

        for(i= 0 ;a[i] != '+'; ++i )     //   1 +  1i
        {
            if(a[i]  != '-' ) 
                A = A*10 + a[i]-'0';  //计算A
        }
        if(  a[0]  == '-')    A*=(-1) ; 

        for(int j = i+1 ; a[j] != 'i' ; ++j )    //1+-1  1+2
        {
            if(a[j] !=  '-') 
                B = B*10 + a[j] -'0';  //计算B 
        }
        if(a[i+1] == '-')   B*=(-1);

        for( i= 0 ;b[i] != '+'; ++i )    
        {
            if(b[i] != '-')
                C = C*10 + b[i]-'0';  //计算C
        }
        if(  b[0] == '-')    C*=(-1) ; 

        for(int j = i+1 ; b[j] != 'i' ; ++j )
        {
            if(b[j] != '-')
                D = D*10 + b[j]-'0';  //计算D
        }
        if(b[i+1] == '-')   D*=(-1);

        string str ;
        str =to_string(A*C-B*D) + '+' + to_string(A*D+B*C) + 'i';

        return str ;
    }
};

