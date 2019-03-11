/* 题目描述
小Q在学习许多排序算法之后灵机一动决定自己发明一种排序算法，小Q希望能将n个不同的数排序为升序。小Q发明的排序算法在每轮允许两种操作：

1、 将当前序列中前n-1个数排为升序

2、 将当前序列中后n-1个数排为升序

小Q可以任意次使用上述两种操作，小Q现在想考考你最少需要几次上述操作可以让序列变为升序。

输入描述:
输入包括两行，第一行包括一个正整数n(3≤n≤10^5)，表示数字的个数

第二行包括n个正整数a[i](1≤a[i]≤10^9)，即需要排序的数字，保证数字各不相同。
输出描述:
输出一个正整数，表示最少需要的操作次数
示例1
输入
复制
6
4 3 1 6 2 5
输出
复制
2
说明 
这题绝壁在逗我
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int temp, bef;
    cin >> n;
    int min, max;
    vector<int> vv;
    bool tag = false;
    cin >> temp;
    min = max = bef = temp;
    vv.push_back(temp);
    n--;
    while (n--)
    {
        bef = temp;
        cin >> temp;
        if (temp < bef)
            tag = true;
        vv.push_back(temp);
        if (temp > max)
            max = temp;
        if (temp < min)
            min = temp;
    }
    // cout << tag << ": " << min << ":" << max << endl;
    if (!tag) //已经升序了
        cout << "0" << endl;
    else if (vv[0] == min && vv[vv.size() - 1] == max) //两个都在正确位置
        cout << "1" << endl;
    else if (vv[0] == min || vv[vv.size() - 1] == max) //只有一个在正确位置
        cout << "1" << endl;
    else //两个都不在正确位置
        cout << "2" << endl;
}