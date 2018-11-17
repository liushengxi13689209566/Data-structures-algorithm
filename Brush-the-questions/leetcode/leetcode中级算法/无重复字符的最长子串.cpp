
/* 给定一个字符串，找出不含有重复字符的最长子串的长度。

示例：

给定 "abcabcbb" ，没有重复字符的最长子串是 "abc" ，那么长度就是3。

给定 "bbbbb" ，最长的子串就是 "b" ，长度是1。

给定 "pwwkew" ，最长子串是 "wke" ，长度是3。请注意答案必须是一个子串，"pwke" 是 子序列  而不是子串。 */

#include <string>
#include <iostream>
using namespace std;
class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        string result;
        int max = 0, SS;
        auto tmp = s.size();
        for (int i = 0; SS = result.size(), i < tmp; i++) //s=" "
        {
            if (SS > max)
                max = SS;
            if (result.find(s[i]) == string::npos)
                result += s[i];
            else
            {
                auto pos = result.rfind(s[i]);
                string temp = result.substr(pos + 1);
                result = temp;
                result += s[i];
            }
        }
        return max > SS ? max : SS;
    }
};
int main(void)
{
    Solution s1;
    cout << s1.lengthOfLongestSubstring("aabaab!bb") << endl;
    return 0;
}
