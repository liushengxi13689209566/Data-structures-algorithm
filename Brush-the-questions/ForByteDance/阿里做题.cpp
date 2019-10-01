#include <string>
#include <iostream>
#include <stack>
using namespace std;
// 请在15分钟内完成以下题目
// 字符串为单位的反转，空格和逗号为分隔符，
//  多余一个的空格要合并为一个，注意字符串前后也有可能有空格
// 输入" hello,  i am    a  coder "
// 任意选择下方一个实现
// 1：首先至少完成输出"coder a am i,hello"

string ReverseSentence(string str)
{
    string res = "", tmp = "";

    for (unsigned int i = 0; i < str.size(); ++i)
    {
        if (i > 1 && str[i - 1] == ' ' && str[i] == ' ')
            continue;
        if (str[i] == ' ' || str[i] == ',')
            res = str[i] + tmp + res, tmp = "";
        else
            tmp += str[i];
    }
    if (tmp.size())
        res = tmp + res;
    return res;
}
int main()
{
    string s1 = " hello,  i am    a  coder ";
    cout << ReverseSentence(s1) << endl;
    return 0;
}