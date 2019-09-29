#include <bits/stdc++.h>
using namespace std;
struct node
{
    int work, time, sum;
    bool operator<(const node &a)
    {
        return time < a.time;
    }
};
int main()
{
    int k;
    cin >> k;
    while (k--)
    {
        int n;
        cin >> n;
        vector<node> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i].work >> v[i].time;
        }
        sort(v.begin(), v.end());
        int t = v[0].work;
        if (v[0].time < t)
        {
            cout << "No" << endl;
            continue;
        }
        bool flag = true;
        for (int i = 1; i < n; i++)
        {
            t += v[i].time;
            v[i].sum = v[i].work;
            if (v[i].sum > v[i].time)
            {
                flag = false;
                break;
            }
        }
        printf("%s\n", flag ? "Yes" : "No");
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n, m, k;
    cin >> n >> m >> k;
    //long long ret =(double)sqrt(k*1.0);
    long long Min = min(n, m);
    long long Max = max(n, m);
    long long count = 0;
    while (Min * Max > k)
    {
        Min--;
        count++;
    }
    cout << count << endl;
    return 0;
}

//后台开发
1.
2. 

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <bitset>
#include <algorithm>
#include <utility>
#include <queue>
#include <bitset>
using namespace std;
int main(void)
{
    const int MAX = 10e5 + 10;
    int t;
    int a[MAX];
    cin >> t;
    while (t--)
    {
        int n, temp;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        int two = 0;
        int three = 0;
        for (int i = 0; i < n - 2; ++i)
        {
            if (a[i] == a[i + 1] && a[i + 1] == a[i + 2])
            {
                three = 1;
                break;
            }
        }
        if (three == 1)
        {
            cout << "woman\n";
            continue;
        }
        for (int i = 0; i < n - 1; ++i)
        {
            if (a[i] == a[i + 1])
            {
                two++;
            }
        }
        if (two > 1)
        {
            cout << "woman\n";
            continue;
        }
        long long sum = 0;
        long long sum2 = 0;
        for (int i = 0; i < n; i++)
            sum += a[i];
        for (int i = 0; i < n; ++i)
            sum2 += i;
        sum = sum - sum2;
        if (sum % 2 == 0)
            cout << "woman\n";
        else
            cout << "man\n";
    }
    return 0;
}