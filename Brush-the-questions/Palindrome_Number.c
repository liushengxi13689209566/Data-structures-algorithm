/*************************************************************************
	> File Name: Palindrome_Number.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月11日 星期三 13时19分28秒
 ************************************************************************/
/* 判断一个数是否是回文数，不额外使用空间*/
#include<stdio.h>
bool isPalindrome(int x) { 
    int n ,t= 0;

    for(n=x ;n > 0;n/=10)  //就这样判断即可
        t=t*10+n%10;

    if(t == x)    return true;
    else return false;
}
