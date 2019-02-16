/*************************************************************************
	> File Name: 三数之和.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2019年02月16日 星期六 10时53分25秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

/*class Solution
{
  public:
	vector<vector<int>> threeSum(vector<int> &nums)
	{
		vector<vector<int>> result;
		int len = nums.len();
		if (len <= 0)
			return result;

		for (int i = 0; i < len; i++)
		{
			for (int j = i + 1; j < len; j++)
			{
				for (int k = j + 1; k < len; k++)
				{
					if (nums[i] + nums[j] + nums[k] == 0)
					{
						vector<int> temp{nums[i], nums[j], nums[k]};
						sort(temp.begin(), temp.end());

						auto it = std::find(result.begin(), result.end(), temp);

						if (it == result.end())

							result.push_back(temp);
					}
				}
			}
		}
		return result;
	}
};*/

class Solution
{
  public:
	vector<vector<int>> threeSum(vector<int> &nums)
	{
		vector<vector<int>> result;
		int len = nums.size();
		if (len < 3)
			return result;
		sort(nums.begin(), nums.end()); //先转换成有序向量
		for (int i = 0; i < len - 2; ++i)
		{
			int j = i + 1;
            int k = len - 1;
			while (j < k)
			{
				int sum = nums[i] + nums[j] + nums[k]; //转换成两数之和的问题
				if (sum == 0)
				{
					result.push_back({nums[i], nums[j++], nums[k--]});
					while (j < k && nums[j] == nums[j - 1])
						j++; 
					while (j < k && nums[k] == nums[k + 1])
						k--; //与上一个重复
				}
				else if (sum > 0)
					k--; //sum(两数和)较大时，k左移
				else
					j++; //sum较小时，j右移
			}
			while (i < len - 2 && nums[i] == nums[i + 1])
				i++; //i跳过重复元素
		}
		return result;
	}
};