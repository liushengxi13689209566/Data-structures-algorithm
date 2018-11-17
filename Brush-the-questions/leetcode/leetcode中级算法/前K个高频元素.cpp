/*************************************************************************
	> File Name: 前K个高频元素.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2018年08月13日 星期一 14时58分43秒
 ************************************************************************/

#include <iostream>
using namespace std;
/*给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

示例 1:

输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
示例 2:

输入: nums = [1], k = 1
输出: [1]
说明：

你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。*/
#include <queue>
#include <queue>
#include <unordered_map>
#include <utility>
class Solution
{
  public:
	vector<int> topKFrequent(vector<int> &nums, int k)
	{
		/* frist 是次数，而second 是数值 */
		priority_queue<pair<int, int>> pri_que;
		vector<int> result;
		unordered_map<int, int> un_map;//underorder_map 不对元素进行排序，而map会进行排序
		for (auto i : nums)
			un_map[i]++;
		for (auto i : un_map)
			pri_que.push({i.second, i.first});
		for (auto i = 0; i < k; i++)
		{
			result.push_back(pri_que.top().second);
			pri_que.pop();
		}
		return result;
	}
};
