/*************************************************************************
	> File Name: 兑换硬币.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2018年08月06日 星期一 08时09分48秒
 ************************************************************************/
/*在一个国家仅有1分，2分，3分硬币，将钱N兑换成硬币有很多种兑法。请你编程序计算出共有多少种兑法。
Input
每行只有一个正整数N，N小于32768。
Output
对应每个输入，输出兑换方法数。
Sample Input
2934
12553
Sample Output
718831
13137761*/
#include <iostream>
#include <vector>
using namespace std;
int DP(int amount)
{
	vector<int> F(amount + 1, 1);
	for (int i = 2; i <= 3; ++i)
	{
		for (int j = i; j <= amount; ++j)
		{
			F[j] += F[j - i];  //F[k]表示的兑换方法数
		}
	}
	return F[amount];
}
int main(void)
{
	int N = 0;
	for (int j = 1; j < 32768; ++j)
	{
		N = j;
		cout << DP(N) << endl;
	}
	return 0;
}
