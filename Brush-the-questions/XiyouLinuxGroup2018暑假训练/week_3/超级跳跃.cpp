/*************************************************************************
	> File Name: 超级跳跃.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2018年08月06日 星期一 22时44分53秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*最长上升子序列问题*/
int DP(vector<int> &nums)
{
	int TT = nums.size();
	if (TT == 0)
		return 0;
	vector<int> F(TT, 1);
	int result =  F[0];
	for (int i = 0; i < TT; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (nums[j] < nums[i])
			{
				F[i] = max(F[j] + 1, F[i]);
			}
		}
		if(F[i] > result )
			result = F[i] ;
	}
	return result ;
}
int main(void)
{
	int n;
	vector<int> nums;
	int temp;
	while (cin >> n && n)
	{
		nums.clear();
		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			nums.push_back(temp); // 1 2 3 4
		}
		cout << DP(nums) << endl;
	}
}
