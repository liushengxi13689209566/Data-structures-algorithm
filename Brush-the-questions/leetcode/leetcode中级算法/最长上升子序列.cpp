/*************************************************************************
	> File Name: 最长上升子序列.cpp
	> Author: Liu Shengxi
	> Mail: 13689209566@163.com
	> Created Time: 2018年07月20日 星期五 09时44分47秒
 ************************************************************************/
/*给定一个无序的整数数组，找到其中最长上升子序列的长度。

示例:

输入: [10,9,2,5,3,7,101,18]
输出: 4
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
说明:

可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
你算法的时间复杂度应该为 O(n2) 。
进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?*/


/*求LIS的三种方法，分别是O(n^2)的DP，O(nlogn)的二分+贪心法，以及O(nlogn)的树状数组优化的DP */

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std ;
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int TT = nums.size()  ;
		if ( TT == 0)
			return 0 ;
		vector<int> F(TT, 1);
		for (int i = 0; i < TT ; ++i)
		{
			for (int j = 0; j < i ; ++j )  // How to delete it ??  
			{
				if (nums[j] < nums[i]  ) {
					F[i] = max(F[j] + 1 , F[i]);
				}
			}
			for (auto k : F )
				cout << k << "  ";
			cout << endl ;
		}
		int max =  F[0] ;
		for (auto i : F ) {
			if (i > max )
				max =  i ;
		}
		return max  ;
	}
};

int main(void) {
	Solution s1 ;
	// int tt = s1.lengthOfLIS(vector<int>(10,9,2,5,3,7,101,18));
	// cout << " tt == " << tt << endl ;

	vector<int> v{1, 3, 6, 7, 9, 4, 10, 5, 6};
	int tt = s1.lengthOfLIS(v);
	cout << " tt == " << tt << endl ;

	return 0 ;
}


