/*************************************************************************
	> File Name: myhead.h
	> Author: 
	> Mail: 
	> Created Time: 2017年12月14日 星期四 22时57分27秒
 ************************************************************************/

#ifndef _MYHEAD_H
#define _MYHEAD_H
#define MAXSIZE  10000 
#include<iostream>
#include<string.h>
#include<stack>
class Solution{
    public:
    Solution(char *argv); //构造函数
    ~Solution(); //析构函数
    bool IsValidParentheses(); //功能函数
    void print(const char *temp); //输出函数
    bool readFile(); //读取字符串的函数
    private:
    FILE *fp ;  //文件指针
    char str[MAXSIZE];// 临时缓存字符数组
    int LineCount ;

};
#endif
