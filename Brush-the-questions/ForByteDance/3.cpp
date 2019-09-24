#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <bitset>
#include <algorithm>
#include <utility>
#include <math.h>
#include <queue>
#include <bitset>

using namespace std;
string s;
int n;
int getAns(int i)
{
    int ans1 = 0, ans2 = 0;
    int t1 = i, t2 = i;
    int flag1 = 0,
        flag2 = 0;
    while (t1 >= 0)
    {
        if (s[t1] == 'O')
        {
            flag1 = 1;
            break;
        }
        else
        {
            t1--;
            ans1++;
        }
    }
    if (!flag1)
        ans1 = INT32_MAX;
    while (t2 < n)
    {
        if (s[t2] == 'O')
        {
            flag2 = 1;
            break;
        }
        else
        {
            t2++;
            ans2++;
        }
    }
    if (!flag2)
        ans2 = INT32_MAX;
    return std::min(ans1, ans2);
}
int main()
{
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; ++i)
    {
        if (i != 0)
            cout << " ";
        cout << getAns(i);
    }
    cout << endl;
    return 0;
}
