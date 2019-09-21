
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, hour, minute;
    cin >> n;
    vector<int> vv(n);
    for (int i = 0; i < n; i++)
    {
        cin >> hour >> minute;
        vv[i] = hour * 60 + minute;
    }
    sort(vv.begin(), vv.end());
    int x, a, b;
    cin >> x;
    cin >> a >> b;
    int deadTime = a * 60 + b;
    for (int i = n - 1; i >= 0; i--)
    {
        if (vv[i] + x <= deadTime)
        {
            cout << vv[i] / 60 << " " << vv[i] % 60 << endl;
            return 0;
        }
    }
    return 0;
}