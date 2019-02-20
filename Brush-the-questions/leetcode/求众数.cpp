/*************************************************************************
	> File Name: 求众数.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2019年02月20日 星期三 17时11分12秒
 ************************************************************************/

#include <iostream>
/*
定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在众数。

示例 1:

输入: [3,2,3]
输出: 3
示例 2:

输入: [2,2,1,1,1,2,2]
输出: 2*/
#include <unordered_map>
#include <vector>
using namespace std;
/*
class Solution
{
  public:
	int majorityElement(vector<int> &nums)
	{
		int len = nums.size();
		if (len == 1)
			return nums[0];
		unordered_map<int, int> mmp;
		unordered_map<int, int>::iterator iter;
		int result = 0;
		for (int t : nums)
		{
			iter = mmp.find(t);
			if (iter != mmp.end())
			{
				mmp[t]++;
				if (mmp[t] > len / 2)
				{
					result = t;
					break;
				}
			}
			else
			{
				mmp.insert({t, 1});
			}
		}
		return result;
	}
};*/
class Solution
{
  public:
	int majorityElement(vector<int> &nums)
	{
		int count = 1, result = nums[0];

		for (int i = 1; i < nums.size(); i++)
		{
			if (count == 0)
				result = nums[i];

			if (nums[i] == result)
				count++;
			else
				count--;
			// if (count > nums.size() / 2)
			// 	return nums[i];
		}
		return result;
	}
};
int main(void)
{
	vector<int> vv({2, 2, 1, 1, 1, 2, 2});
	Solution s1;
	std::cout << s1.majorityElement(vv) << std::endl;
}