/*************************************************************************
	> File Name: 分数到小数.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2018年08月14日 星期二 23时45分25秒
 ************************************************************************/
/*给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以字符串形式返回小数。

如果小数部分为循环小数，则将循环的部分括在括号内。

示例 1:

输入: numerator = 1, denominator = 2
输出: "0.5"
示例 2:

输入: numerator = 2, denominator = 1
输出: "2"
示例 3:

输入: numerator = 2, denominator = 3
输出: "0.(6)"*/
/*测试数据 ：
1
2
6
5
2
3
1
3
2
1
4
333
-1
-2147483648
1
6

*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <stdlib.h>
using namespace std;
class Solution
{
  public:
	string fractionToDecimal(int numerator, int denominator)
	{

		bool tag = true; //判断符号,在最后再进行判断
		if ((numerator > 0 && denominator > 0) || (numerator < 0 && denominator < 0))
			tag = false;

		//修正符号
		long long num = abs((long long)numerator);
		long long den = abs((long long)denominator);

		string result;
		if (num == 0)
			return "0";
		if (den == 0)
			return result;

		if (num % den == 0)
			result = to_string(num / den);
		else
			result = to_string(num / den) + '.';

		unordered_map<int, int> mmp;
		int index = result.size();
		auto overage = num % den;
		int shang = 0;
		while (overage && mmp.find(overage) == mmp.end())
		{
			mmp[overage] = index++;
			overage *= 10;
			shang = overage / den;
			result += to_string(shang);
			overage -= shang * den;
		}
		if (overage != 0)
		{
			result.insert(mmp[overage], "(");
			result.insert(index + 1, ")");
		}
		if (tag)
			return "-" + result;
		return result;
	}
};
int main(void)
{
	Solution s1;
	cout << s1.fractionToDecimal(1, 333) << endl; // 0.(003 )
	return 0;
}
