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
#include<stdlib.h>
#include<stack>
class Solution{
    public:
    Solution(char *argv); //构造函数
    ~Solution(); //析构函数
    bool IsValidParentheses(); //判断是否合法的功能函数
    void print(int flag); //输出”合法”或者”不合法“的函数
    bool readFile(); //读取数据文件的函数
    private:
    FILE *fp ;  //文件指针
    char str[MAXSIZE];// 临时缓存字符数组
    int LineCount ; //行数
    int tag ;      // 标志
    int leftCount ; //左括号数量
    int rightCount ; //右号数量
};
#endif
