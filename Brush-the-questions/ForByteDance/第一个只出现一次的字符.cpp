/*************************************************************************
	> File Name: 第一个只出现一次的字符.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  7/28 14:58:44 2019
 ************************************************************************/

/*
题目描述
在一个字符串(0<=字符串长度<=10000，全部由字母组成)
中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.
*/
#include<iostream>
using namespace std;

struct TT
{
    int  pos=  -1 ;
    int count = 0 ;
};
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        unordered_map<char,TT>  un_map;
        for(int i= 0; i < str.size();i++)
        {
            un_map[str[i]].count += 1;
            un_map[str[i]].pos  = i;
        }
        for(auto it:str)
        {
            if(un_map[it].count == 1 )
                return un_map[it].pos;
        }
        return -1;
    }
};