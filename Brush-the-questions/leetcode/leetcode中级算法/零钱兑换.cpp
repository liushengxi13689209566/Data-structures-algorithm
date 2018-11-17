/*给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

示例 1:

输入: coins = [1, 2, 5], amount = 11
输出: 3 
解释: 11 = 5 + 5 + 1
示例 2:

输入: coins = [2], amount = 3
输出: -1
说明:
你可以认为每种硬币的数量是无限的。*/
#include<iostream>
#include<vector>
#include<limits.h>
#include <iomanip>
using namespace std ;
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {

		vector<int> MinCoinCount(amount + 1, 9999 ) ;
		MinCoinCount[0] = 0 ;
		//sum[k]，(k为零钱数) sum[k] 为所需的最小硬币数量
		for (int i = 1 ; i <= amount   ; ++i)
		{
			for (int j = 0; j < coins.size() ; ++j )
			{
				if ( i - coins[j] >= 0 && MinCoinCount[i - coins[j]] + 1  < MinCoinCount[i])
					MinCoinCount[i] = MinCoinCount[i - coins[j]] + 1 ;
			}
			for (auto i : MinCoinCount)
				cout << setw(5)  << i << "  " ;
			cout << endl ; 
		}

		if (MinCoinCount[amount] == 9999  )
			return -1 ;
		else
			return MinCoinCount[amount];
	}
};
int	main(int argc, char const *argv[])
{
	Solution s1 ;
	std::vector<int> v({1,2,5});

	int tt = s1.coinChange(v, 11)  ;
	cout << "result is  : " <<  tt <<  endl ;
	return 0;
}


