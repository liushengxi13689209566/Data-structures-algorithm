
#include <iostream>
#include <sstream>
using namespace std;
class Solution
{
public:
    string ReverseSentence(string str)
    {
        string res;
        if (str.size() <= 0)
            return res;
        string world;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == ' ')
            {
                res = " " + world + res;
                world.clear();
                //注意耗时
            }
            else
            {
                world += str[i];
            }
            cout << "world == " << world << endl;
        }
        return world + res;
    }
};
int main()
{
    Solution s1;
    string ss("I am a student.");
    cout << s1.ReverseSentence(ss) << endl;
    return 0;
}