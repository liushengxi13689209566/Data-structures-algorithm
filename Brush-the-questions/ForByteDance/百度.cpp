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