/*************************************************************************
	> File Name: 汉明距离总和.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2018年11月07日 星期三 23时23分26秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
  public:
	int totalHammingDistance(vector<int> &nums)
	{
		int result = 0;
		auto count = nums.size();
		for (int i = 0; i < count; i++)
		{
			for (int j = i + 1; j < count; j++)
			{
				// cout << "nums[i] =="<< nums[i] ;
				// cout << "nums[j] =="<< nums[j] << endl;
				if (nums[i] != nums[j])
				{
					for (int k = 32; k >= 0; k--)
					{
						if ((nums[i] & (1 << k)) != (nums[j] & (1 << k)))
							++result;
					}
				}
				//cout << "result ==" << result << endl;
			}
		}
		return result;
	}
};
