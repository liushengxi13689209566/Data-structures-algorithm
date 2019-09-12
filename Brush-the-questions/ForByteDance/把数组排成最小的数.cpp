#include "head.h"

/*输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
 */
bool compare(const string &a, const string &b)
{
    if (a + b < b + a)
        return true;
    else
        return false;
}
class Solution
{
public:
    string PrintMinNumber(vector<int> numbers)
    {
        string res;
        if (numbers.size() <= 0)
            return res;
        vector<string> vv;
        for (auto i : numbers)
            vv.push_back(to_string(i));

        std::sort(vv.begin(), vv.end(), compare); //左右比较即可

        for (auto i : vv)
            res += i;
        return res;
    }
};
int main()
{
    vector<int> vv({3, 32, 321});
    Solution s1;
    cout << s1.PrintMinNumber(vv) << endl;
    return 0;
}