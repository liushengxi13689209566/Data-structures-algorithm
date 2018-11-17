/*************************************************************************
	> File Name: 膜拜代码.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月12日 星期二 23时19分57秒
 ************************************************************************/

#include<iostream>
using namespace std;
C ++解决方案O（n）时间和O（1）空间，简单的说明和简单的解释
vector<int> singleNumber(vector<int>& nums) {
    int aXorb = 0;  // the result of a xor b;
    for (auto item : nums) aXorb ^= item;
    int lastBit = (aXorb & (aXorb - 1)) ^ aXorb;  // the last bit that a diffs b
    int intA = 0, intB = 0;
    for (auto item : nums) {
        // based on the last bit, group the items into groupA(include a) and groupB
        if (item & lastBit) intA = intA ^ item;
        else intB = intB ^ item;
    }
    return vector<int>{intA, intB};   
}
