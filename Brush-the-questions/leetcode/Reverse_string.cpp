/*************************************************************************
	> File Name: Reverse_string.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年04月03日 星期二 17时20分40秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*题目描述：
Write a function that takes a string as input and returns the string reversed .

Example:
Given s = "hello", return "olleh". */

class Solution {
public:
    string reverseString(string s) {
		string test ;
		for(int i = s.size()-1 ;i >= 0 ; i-- ){
			test += s[i] ;
		}
		return test; 
        
    }
};

