

#include <bits/stdc++.h>
using namespace std;

/* class Solution
{
  public:
    bool stoneGame(vector<int> &p)
    {
        int len = p.size();
        vector<int> dp(len, 0);

        for (int i = 0; i < len; i++)
        {

        }
    }
}; */
class Solution
{
  public:
    bool stoneGame(vector<int> &p)
    {
        int kesi = 0;
        int lili = 0;
        int start = 0;
        int end = p.size() - 1;

        while (start != end)
        {
            if (p[start] >= p[end])
            {
                kesi += p[start];
                start++;
            }
            else
            {
                kesi += p[end];
                end--;
            }
            if (p[start] >= p[end])
            {
                lili += p[start];
                start++;
            }
            else
            {
                lili += p[end];
                end--;
            }
        }
        if (kesi > lili)
            return true;
        else
            return false;
    }
};
int main(void)
{
    Solution s1;
    vector<int> vv = {5, 3, 4, 5};
    cout << s1.stoneGame(vv) << endl;
}