/*************************************************************************
	> File Name: 完美数.cpp
	> Author: Liu Shengxi
	> Mail: 13689209566@163.com
	> Created Time: 2018年07月05日 星期四 23时23分49秒
 ************************************************************************/

#include<iostream>
#include<math.h>
using namespace std;
/*对于一个 正整数，如果它和除了它自身以外的所有正因子之和相等，我们称它为“完美数”。

给定一个 正整数 n， 如果他是完美数，返回 True，否则返回 False



示例：

输入: 28
输出: True
解释: 28 = 1 + 2 + 4 + 7 + 14


注意:

输入的数字 n 不会超过 100,000,000. (1e8)
*/
class Solution {
public:
	bool checkPerfectNumber(int num) {
		if(num == 1 || num == 0  )
			return false ;
		int tag = sqrt(num);
		//cout << tag << endl  ;
		int sum  = 0 ;
		for (int  i =  2 ; i <= tag; ++i) {
			if ( num % i == 0  )
				sum += (i + num / i ) ;
		}
		//cout << sum  << " : " << num << endl ;
		if ( (sum+1) == num )
			return true;
		else
			return false ;
	}
};
int main(void) {
	Solution s1 ;
	if ( s1.checkPerfectNumber(28) )
		cout << "lll " << endl ;
	else
		cout << "xxx" << endl ;



	if ( s1.checkPerfectNumber(1) )
		cout << "lll " << endl ;
	else
		cout << "xxx" << endl ;



	if ( s1.checkPerfectNumber(0) )
		cout << "lll " << endl ;
	else
		cout << "xxx" << endl ;
	return 0;
}

