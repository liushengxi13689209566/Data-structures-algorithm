

#include <iostream>
#include <sstream>
using namespace std;

class Solution
{
public:
    int StrToInt(string str)
    {
        if (str.size() <= 0)
            return 0;
        int tag = 1;
        int index = 0;
        if (str[index] == '+')
        {
            tag = 1;
            index++;
        }
        if (str[0] == '-')
        {
            tag = -1;
            index++;
        }
        int res = 0;
        cout << "index == " << index << endl;
        for (int i = index; i < str.size(); i++)
        {
            if (str[i] <= '9' && str[i] >= '0')
                res = res * 10 + str[i] - '0';
            else
                return 0;
        }
        return tag * res;
    }
};
int main(void)
{
    Solution s1;
    string ss("123");
    cout << s1.StrToInt(ss) << endl;
}