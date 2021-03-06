#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
给定一个未排序的整数数组，找到最长递增子序列的个数。

示例 1:

输入: [1,3,5,4,7]
输出: 2
解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
示例 2:

输入: [2,2,2,2,2]
输出: 5
解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。
注意: 给定的数组长度不超过 2000 并且结果一定是32位有符号整数。
*/
class Solution
{
  public:
    int findNumberOfLIS(vector<int> &n)
    {
        int len = n.size();
        vector<int> dp(len, 0);  //以第ｉ个数结尾的最长序列的长度
        vector<int> cnt(len, 0); //以第ｉ个数结尾的最长序列的个数
        dp[0] = 1;
        cnt[0] = 1;
        for (int i = 1; i < len; i++)
        {
            dp[] = dp[] + 1;
        }
        return;
    }
};
