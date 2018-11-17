/*************************************************************************
	> File Name: 在排序数组中查找元素的第一个和最后一个位置.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2018年08月13日 星期一 22时51分45秒
 ************************************************************************/
/*给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1] */
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
  public:
	vector<int> searchRange(vector<int> &nums, int target)
	{
		vector<int> result;
		auto tmp = nums.size();
		auto j = tmp - 1;
		bool tag = true;
		for (int i = 0; i < tmp && j >= 0; i++)
		{
			if (tag && nums[i] == target)
			{
				tag = false;
				result.push_back(i);
			}
			if (nums[j] == target)
			{
				if (result.size() == 0)
					continue;
				result.push_back(j);
				return result;
			}
			else
				j--;
		}
		result.push_back(-1);
		result.push_back(-1);
		return result;
	}
};
