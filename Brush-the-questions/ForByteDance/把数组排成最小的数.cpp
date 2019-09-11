#include "head.h"

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