

#include "head.h"
/*题目描述
给定一个字符串，请找出其中长度最长且不含有重复字符的子串，计算该子串长度。
输入描述:
输入类型为字符串，例如”abcde“
输出描述:
输出类型为整型， 例如 5
示例1
输入
复制
pwwkew
输出
复制
3
说明
无重复字符的最长子串是"abc"，其长度为 3 */
int SameFun(const char ch, const string &str, int index)
{
    int count = 1;
    for (int i = index - 1; i >= 0; i--)
    {
        if (str[i] == ch)
            break;
        count++;
    }
    return count;
}
int main(void)
{
    //DP
    string str;
    cin >> str;
    if (str.size() <= 0)
    {
        cout << str << endl;
        return 0;
    }
    vector<int> dp(str.size(), 1);
    int max = 1;
    std::map<char, bool> mmp{{str[0], true}};

    for (int i = 1; i < str.size(); i++)
    {
        if (mmp.find(str[i]) == mmp.end())
        {
            mmp[str[i]] = true;
            dp[i] = dp[i - 1] + 1;
        }
        else
        {
            cout << "Samecount == " << SameFun(str[i], str, i) << endl;
            dp[i] = dp[i - 1] - SameFun(str[i], str, i);
            if (dp[i] < 1)
                dp[i] = 1;
        }
        cout << "dp[i] == " << dp[i] << endl;
        if (dp[i] > max)
            max = dp[i];
    }
    for (auto i : dp)
        cout << i << " ";
    cout << endl
         << endl;
    cout << max << endl;
    return 0;
}
