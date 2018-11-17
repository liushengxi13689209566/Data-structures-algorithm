/*************************************************************************
	> File Name: Find_the_Duplicate_Number.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月30日 星期二 20时12分55秒
 ************************************************************************/
/* 题目描述 ：
给定一个包含 n+1个整数（其中每个整数介于1和n（含）之间）的数组numn，证明至少存在一个重复数。
假设只有一个重复号码，找到重复号码。

注意：
您不得修改数组（假定该数组是只读的）。
您必须只使用恒定的O（1）额外空间 。
你的运行时复杂度应该小于 O(n^2)。
数组中只有一个重复数字，但可以重复多次 。 */
/*题目解析：肯定与“ 其中每个整数介于1和 n（含）之间 ”此条件息息相关 
*/
/*测试样例：
[1,1]
[1,2,2]*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
		vector<int>::iterator it ;
		for( auto  iter = nums.begin() ;iter != nums.end() ; ++iter){   // O(n^2) 时间复杂度
			for(auto next = iter+1 ;next != nums.end() ;++next ){
				if( *iter == *next )
					return *iter ;
			}
		}
    }
};
/*大神代码：
The main idea is the same with problem Linked List Cycle II,
https://leetcode.com/problems/linked-list-cycle-ii/. 
Use two pointers the fast and the slow. 
The fast one goes forward two steps each time, while the slow one goes only step each time. 
They must meet the same item when slow==fast. In fact, they meet in a circle, 
the duplicate number must be the entry point of the circle when visiting the array from nums[0]. 
Next we just need to find the entry point. 
We use a point(we can use the fast one before) to visit form begining with one step each time, 
do the same job to slow. When fast==slow, they meet at the entry point of the circle. 
The easy understood code is as follows.

int findDuplicate3(vector<int>& nums)
{
	if (nums.size() > 1)
	{
		int slow = nums[0];
		int fast = nums[nums[0]];
		while (slow != fast)
		{
			slow = nums[slow];
			fast = nums[nums[fast]];
		}

		fast = 0;
		while (fast != slow)
		{
			fast = nums[fast];
			slow = nums[slow];
		}
		return slow;
	}
	return -1;
}
*/
/*
template<class InputIterator, class T>
InputIterator find (InputIterator first, InputIterator last, const T& val)
{
  while (first!=last) 
  {
     if (*first==val) return first;
     ++first;
   }
    return last;
}
*/
