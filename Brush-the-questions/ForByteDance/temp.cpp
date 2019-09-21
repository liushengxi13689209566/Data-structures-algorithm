#include "head.h"
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a;
    a.push_back(1);

    for (int i = 2; i <= n; i++)
    {
        int carry = 0;
        for (int j = 0; j < a.size(); j++)
        {
            a[j] = a[j] * i + carry;
            carry = a[j] / 1000000;
            a[j] = a[j] % 1000000;
        }
        if (carry != 0)
            a.push_back(carry);
    }
    cout << a.back();
    for (int k = a.size() - 2; k >= 0; k--)
        cout << setw(6) << setfill('0') << a[k];
}

