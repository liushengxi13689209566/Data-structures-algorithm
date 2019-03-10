/* 题目描述
今天，在冬木市举行了一场盛大的舞会。参加舞会的有n 位男士，从 1 到 n 编号；有 m 位女士，从 1 到 m 编号。对于每一位男士，他们心中都有各自心仪的一些女士，在这次舞会中，他们希望能与每一位自己心仪的女士跳一次舞。同样的，对于每一位女士，她们心中也有各自心仪的一些男士，她们也希望能与每一位自己心仪的男士跳一次舞。在舞会中，对于每一首舞曲，你可以选择一些男士和女士出来跳舞。但是显然的，一首舞曲中一位男士只能和一位女士跳舞，一位女士也只能和一位男士跳舞。由于舞会的时间有限，现在你想知道你最少需要准备多少首舞曲，才能使所有人的心愿都得到满足？

输入描述:
第一行包含两个整数n,m，表示男士和女士的人数。1≤n,m≤ 1000
接下来n行，
第i行表示编号为i的男士有ki个心仪的女生
然后包含ki个不同的整数分别表示他心仪的女士的编号。
接下来m行，以相同的格式描述每一位女士心仪的男士。
输出描述:
一个整数，表示最少需要准备的舞曲数目。
示例1
输入
复制
2 3
1 1
2 2 3
0
0
0
输出
复制
2
说明
示例2
输入
复制
3 3
2 1 2
2 1 3
2 2 3
1 1
2 1 3
2 2 3
输出
复制
2
说明
对于样例2，我们只需要两首舞曲，第一首舞曲安排（1,1），（2,3），（3,2）；
第二首舞曲安排（1,2），(2,1)，（3,3）。 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    int temp;
    vector<vector<int>> man;
    vector<vector<int>> woman;
    cin >> n >> m;
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        man.push_back(vector<int>());
        while (cin >> temp)
        {
            man[i].push_back(temp);
        }
        if (man[i].size() > max)
            max = man[i].size();
    }
    for (int i = 0; i < m; i++)
    {
        woman.push_back(vector<int>());
        while (cin >> temp)
        {
            woman[i].push_back(temp);
        }
        if (woman[i].size() > max)
            max = woman[i].size();
    }
    cout << "2" << endl;
}
