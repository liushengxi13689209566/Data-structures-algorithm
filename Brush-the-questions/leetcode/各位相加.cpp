/*************************************************************************
	> File Name: 各位相加.cpp
	> Author: Liu Shengxi
	> Mail: 13689209566@163.com
	> Created Time: 2018年07月05日 星期四 22时20分26秒
 ************************************************************************/
/*给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。

示例:

输入: 38
输出: 2
解释: 各位相加的过程为：3 + 8 = 11, 1 + 1 = 2。 由于 2 是一位数，所以返回 2。
进阶:
你可以不使用循环或者递归，且在 O(1) 时间复杂度内解决这个问题吗？*/
#include<iostream>
using namespace std;
/*class Solution {
public:
	int addDigits(int num) {
		if(num < 10 )
			return num ;
		int sum = 0 ;
		int temp = num ;
		while (temp) {
			sum += temp % 10 ;
			temp /= 10 ;
		}
		addDigits(sum);
	}
};*/
class Solution {
public:
	int addDigits(int num) {
		while (num >= 10 ) {
			int sum = 0 ;
			int temp = num ;
			while (temp) {
				sum += temp % 10 ;
				temp /= 10 ;
			}
			num = sum  ;
		}
		return num ;
	}
};
int main(void) {
	Solution s1 ;
	cout << s1.addDigits(38) << endl ;
	cout << s1.addDigits(10) << endl ;
	return 0;
}

