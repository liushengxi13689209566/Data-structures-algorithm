/* 题目描述
小Q十分富有，拥有非常多的硬币，小Q拥有的硬币是有规律的，对于所有的非负整数K，
小Q恰好各有两个面值为2^K的硬币，所以小Q拥有的硬币就是1,1,2,2,4,4,8,8,…。
小Q有一天去商店购买东西需要支付n元钱，小Q想知道有多少种方案从他拥有的硬币中选取一些拼凑起来恰好是n元
（如果两种方案某个面值的硬币选取的个数不一样就考虑为不一样的方案）。

输入描述:
输入包括一个整数n(1≤n≤10^18)，表示小Q需要支付多少钱。注意n的范围。
输出描述:
输出一个整数，表示小Q可以拼凑出n元钱放的方案数。
示例1
输入
复制
6
输出
复制
3
说明
 */
//贪心吧，应该是
//伙伴算法，所有的数都能够用 2^k 的数字拼起来
//10^18
#include <bits/stdc++.h>
/*
using namespace std;
int main(void)
{
    int n;
    cin >> n;
    //贪心吧，应该是
    //伙伴算法，所有的数都能够用 2^k 的数字拼起来
    //10^18
    int order = 0;
    while (n / 2)
    {
        order++;
        n /= 2;
    }
    cout << order << endl;
} 
*/

/*

n如果是奇数，说明必须只用一个1块钱,剩下只能用 2 4 8,那么问题转移成了状态转移f(n) = f(n>>1),
此时2,4,8可以看做1,2,4,两者问题等价
如果n是偶数，那么可以分为两种情况，使用两个1块钱，或者不使用1块钱；两个一块钱的话,右移一位，需要减1
如果不使用的话还是右移一位。后面的问题也与1块钱无关，递归。再用一个map存储中间结果，解决重复性问题。
f(n) = f(n>>1) + f((n>>1) -1) 

*/
using namespace std;
unordered_map<long long, long long> ans;
long long f(long long n)
{
    if (ans.find(n) != ans.end())
        return ans[n];
    if (n == 0 || n == 1)
        return 1;
    if (n & 1)                     //判断是不是　==　1为奇数
        return ans[n] = f(n >> 1); // /2
    else
        return ans[n] = f(n >> 1) + f((n >> 1) - 1); //  除以 2
}
int main()
{
    long long n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}