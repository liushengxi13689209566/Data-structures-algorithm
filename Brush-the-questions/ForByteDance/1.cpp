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
