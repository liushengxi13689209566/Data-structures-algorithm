/*************************************************************************
	> File Name: test.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2019年03月07日 星期四 18时57分04秒
 ************************************************************************/

#include <iostream>

//贪心
/*座位安排
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
假设班主任需要为N名学生安排座位，现在有M张桌子，每张桌子可以供一名学生单独使用，也可以供两名学生共同使用，共用一张桌子的两名学生便称为同桌。班主任为所有学生评估出淘气值，第i名学生的淘气值为Ai，如果同桌两人淘气值之和过高，便容易产生矛盾。那么班主任该如何安排座位，使得淘气值之和最大的两名同桌，其淘气值之和尽可能小？

输入
第一行包含两个整数N和M，1≤M＜N≤105且N≤M×2。

第二行包含N个整数A1到AN，0≤Ai≤109。

（数字间均以空格隔开）

输出
输出淘气值之和最大的两名同桌，其淘气值之和可能的最小值。


样例输入
5 3
4 1 8 2 6
样例输出
7

Hint
安排第1名与第4名学生共用一张桌子，两人淘气值之和为6；第2名与第5名学生共用一张桌子，
两人淘气值之和为7；第3名学生单独用一张桌子。
*/
#include <algorithm>
#include <vector>
using namespace std;
#include <iostream>
int main(void)
{
    int n, m, i;
    cin >> n >> m;
    vector<int> nums;
    while (n--)
    {
        cin >> i;
        nums.push_back(i);
    }
    sort(nums.begin(), nums.end());
    for (int i = nums.size() - 2; i < nums.size(); i++)
    {
        if (nums[0] + nums[i] < nums[nums.size() - 1])
            return nums[0] + nums[i];
    }
}
/*
给出一个m*n的只由01组成的矩阵，我们称包含：

     1

   111

     1

这样的形状为星星（矩阵的四角为0、1均可），现在要从这个矩阵中选出一个矩形区域，要求这个矩形区域中至少有k个星星，问有多少个这样的矩形区域。（矩形区域即选取连续的若干行和连续的若干列所构成的交集区域）

输入
输入第一行包含三个整数n,m,k(1<=n,m<=500,1<=k<=m*n), n和m分别表示矩阵的行数和列数。

接下来有n行，每行包含一个长度为m的仅含01的字符串，描述这个矩阵。

输出
输出仅包含一个正整数，表示符合要求的矩形区域的数量。


样例输入
3 5 2
11100
11110
01100
样例输出
2

Hint
有选择1到4列和1到5列两种矩形区域的选择方式。*/

#include <algorithm>
#include <vector>
using namespace std;
#include <iostream>
int main(void)
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> strs;
    string str;
    while (n--)
    {
        cin >> str;
        strs.push_back(str);
    }
}
/*
【本题为选答题】猜数游戏
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
桌子上有N张写有数字0或1的卡片，初始时玩家并不知道每张卡片上的数字是多少。将卡片从1到N编号，玩家每次可以选择一个区间[L，R]（1≤L≤R≤N）并询问裁判编号为L到R的卡片上的数字之和是奇数还是偶数（所需费用为AL,R）。那么玩家至少要花费多少费用才能确定每张卡片上的数字？

输入
第一行包含一个整数N，1≤N≤1000。

接下来N行，第i行包含N-i+1个整数Ai,i到Ai,N，1≤Ai,j≤1000。

输出
输出确定每张卡片上的数字所需的最小费用。


样例输入
3
1 2 3
2 1
3
样例输出
4
*/
#include <algorithm>
#include <vector>
using namespace std;
#include <iostream>
int main(void)
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> strs;
    string str;
    while (n--)
    {
        cin >> str;
        strs.push_back(str);
    }
}