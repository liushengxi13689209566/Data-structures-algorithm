/*************************************************************************
	> File Name: 1.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2019年01月13日 星期日 22时16分24秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;
int hash_fun(string key)
{
    string LastTwoChars = key.substr(key.length() - 2, 2);
    int index = stoi(LastTwoChars);
    return index;
}
int main(void)
{
    string str1 = "04161173";
    cout << hash_fun(str1) << endl;
}
