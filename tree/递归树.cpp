/*************************************************************************
	> File Name: 递归树.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2019年03月10日 星期日 10时50分23秒
 ************************************************************************/

#include <iostream>
using namespace std;
static int count = 0;
int f(int n)
{
    count++;
    if (n == 1 || n == 2)
        return 1;
    else
        return f(n - 1) + f(n - 2);
}
int main(void)
{
    f(5);
    cout << count << endl;
}
