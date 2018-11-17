/*************************************************************************
	> File Name: 合并区间.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2018年08月21日 星期二 16时18分44秒
 ************************************************************************/
/*给出一个区间的集合，请合并所有重叠的区间。

示例 1:

输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2:

输入: [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。*/
#include <iostream>
using namespace std;
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution
{
  public:
	vector<Interval> merge(vector<Interval> &intervals)
	{
		auto len = internals.size();
		for (int i = 0; i < len; i++) 
		{
			for (int j = 0; j < i; j++)
			{
				if (internals[i].end < internals[i + 1].begin())
				{
					//就应该合并
					
				}
			}
		}
	}
};
