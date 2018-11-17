/*************************************************************************
	> File Name: 递增的三元子序列.cpp
	> Author: Liu Shengxi
	> Mail: 13689209566@163.com
	> Created Time: 2018年07月18日 星期三 12时12分32秒
 ************************************************************************/
/*给定一个未排序的数组，请判断这个数组中是否存在长度为3的递增的子序列。

正式的数学表达如下:

如果存在这样的 i, j, k,  且满足 0 ≤ i < j < k ≤ n-1，
使得 arr[i] < arr[j] < arr[k] ，返回 true ; 否则返回 false 。
要求算法时间复杂度为O(n)，空间复杂度为O(1) 。

示例:
输入 [1, 2, 3, 4, 5],
输出 true.

输入 [5, 4, 3, 2, 1],
输出 false.

*/
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
// class Solution {
// public:
// 	//[2,4,-2,-3]
//     bool increasingTriplet(vector<int>& nums) {
//     	for (int i = 0; i < nums.size() ; i++ )
//     	{
//     		if(nums[i+1] > nums[i] && nums[i+2] > nums[i+1] )
//     			return true  ;
//     	}
//      	return false ;
//     }
// };
class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		int c1 = INT_MAX, c2 = INT_MAX;
		for (int x : nums) {
			if (x <= c1) {
				c1 = x;           // c1 is min seen so far (it's a candidate for 1st element)
			} else if (x <= c2) { // here when x > c1, i.e. x might be either c2 or c3
				c2 = x;           // x is better than the current c2, store it
			} else {              // here when we have/had c1 < c2 already and x > c2
				return true;      // the increasing subsequence of 3 elements exists
			}
		}
		return false;
	}
};
int main(void) {
	Solution s1;
	vector<int> v({2, 4, -2, 5, 6});
	if ( s1.increasingTriplet(v) )
		cout << "TTTTTTTTT" << endl ;
	else
		cout << "FFFFFFFFFF " << endl ;




	vector<int> v2({2,4,-2,-3});
	if ( s1.increasingTriplet(v2) )
		cout << "TTTTTTTTT" << endl ;
	else
		cout << "FFFFFFFFFF " << endl ;
}

