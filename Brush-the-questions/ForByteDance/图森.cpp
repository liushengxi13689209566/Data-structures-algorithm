//题目0.一个数组a.求a[0]- a[k], a[1]- a[k+1], a[2]-a[k+21].所有区间的中位数。
#include <iostream>
#include <vector>
using namespace std;

//int a[] = {2, 4, 5, -2, 0, -8, 11, 2, -5, 4}
int main()
{

    vector<int> vv({2, 4, 5, -2, 0, -88, 11, 2, -5, 4});
    // int bef = 0;

    // for(int i= 0;i < vv.size();i++)
    // {
    //   if(vv[i] < 0 )
    //     bef = vv[i];
    //   if(vv[i] >= 0)
    //     bef+= vv[i];
    //   if(bef > res )
    //     res = bef;
    // }
    vector<int> dp(vv.size());
    dp[0] = vv[0];
    int resL = -9999;
    int resR = -9999;
    for (int i = 1; i < vv.size(); i++)
    {
        dp[i] = max(vv[i], vv[i] + dp[i - 1]);
        cout << dp[i] << endl;

        if (dp[i] > resR)
            resR = dp[i];
    }
    cout << "resR == " << resR << endl;

    vector<int> dpL(vv.size());
    dpL[vv.size() - 1] = vv[vv.size() - 1];

    for (int i = vv.size() - 2; i >= 0; i--)
    {
        dpL[i] = max(vv[i], vv[i] + dpL[i + 1]);

        cout << dpL[i] << endl;

        if (dp[i] > resL)
            resL = dpL[i];
    }
    cout << "resL == " << resL << endl;
    cout << endl
         << endl
         << endl;
    cout << resL + resR << endl;
    return 0;
}
