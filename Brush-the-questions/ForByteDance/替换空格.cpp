/*************************************************************************
	> File Name: 替换空格.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  7/28 14:33:16 2019
 ************************************************************************/

/*
 * 
 题目描述
请实现一个函数，将一个字符串中的每个空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。*/
#include<iostream>
using namespace std;
class Solution {
public:
	void replaceSpace(char *str,int length) {
        for(int i= 0 ;i< length ;)
        {
            if(str[i] == ' ')
            {
                for(int j = length-1 ;j >= i ;j--)
                {
                    str[j+2] = str[j];    
                }
                str[i++]= '%';
                str[i++] ='2';
                str[i++] ='0';
                continue;
            }
            i++;
	    }
    }
};
