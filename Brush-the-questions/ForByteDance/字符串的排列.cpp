
#include <iostream>
#include <string>
#include <map>

#include <vector>
#include <bitset>
#include <algorithm>
#include <utility>
using namespace std;
/*题目描述
输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c
所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
输入描述:
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。 */

using Iter = string::iterator;
class Solution
{
public:
    vector<string> res;

    int resove(string &str, Iter beg, Iter end)
    {
        std::map<char, bool> mmp;
        if (beg == end)
        {
            res.push_back(str);
            return 0;
        }
        for (auto it = beg; it != end; it++)
        {
            if (mmp.find(*it) != mmp.end())
                continue;
            else
                mmp[*it] = true;

            std::swap(*it, *beg);
            resove(str, beg + 1, end);
            std::swap(*it, *beg);
        }
        return 0;
    }
    vector<string> Permutation(string str)
    {

        if (str.size() <= 0)
            return res;

        resove(str, str.begin(), str.end());
        sort(res.begin(), res.end());

        return res;
    }
};


int main(void)
{
    Solution s1;
    string str("abc");

    auto ret = s1.Permutation(str);
    for (auto i : ret)
    {
        cout << i << "  ";
    }
    cout << endl;
    return 0;
}