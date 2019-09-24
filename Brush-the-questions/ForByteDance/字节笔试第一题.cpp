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
//过 95%
int n = 0;
int fun(string str, int index)
{
    int i = index;
    int j = i;
    int ret = 999999;
    int ret2 = 999999;
    if (str[index] == 'O')
        return 0;
    for (; i < n; i++)
    {
        if (str[i] == 'O')
        {
            ret = i - index;
            break;
        }
    }
    for (; j >= 0; j--)
    {
        if (str[j] == 'O')
        {
            ret2 = index - j;
            break;
        }
    }
    //    cout << ret << " " << ret2 << endl;
    return ret < ret2 ? ret : ret2;
}
int main()
{
    cin >> n;
    string str;
    cin >> str;
    for (int i = 0; i < n; i++)
    {
        cout << fun(str, i) << " ";
    }
    cout << endl;
    return 0;
}

//过 100%
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

int n = 0;
int fun(string str, int index)
{
    int i = index;
    int j = i;
    int ret = 999999;
    int ret2 = 999999;
    if (str[index] == 'O')
        return 0;
    for (; i < n; i++)
    {
        if (str[i] == 'O')
        {
            ret = i - index;
            break;
        }
    }
    for (; j >= 0; j--)
    {
        if (str[j] == 'O')
        {
            ret2 = index - j;
            break;
        }
    }
    //    cout << ret << " " << ret2 << endl;
    return ret < ret2 ? ret : ret2;
}
int main()
{
    cin >> n;
    vector<char> vv(n);
    vector<int> tt;

    for (int i = 0; i < n; i++)
    {
        cin >> vv[i];
        if (vv[i] == 'O')
            tt.push_back(i);
    }

    for (int i = 0; i < n; i++)
    {
        auto ret1 = std::lower_bound(tt.begin(), tt.end(),i);
        auto ret1 = std::upper_bound(tt.begin(), tt.end(), i);
        if(*ret1-i < *ret2-i)
            cout << *ret1 - i << endl;
            


    }
    cout << endl;
    return 0;
}
