/*************************************************************************
	> File Name: 11.c
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2018年12月03日 星期一 10时55分16秒
 ************************************************************************/

#include <stdio.h>
int fun(int n) //简单递归
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    else
        return fun(n - 1) + fun(n - 2);
}
int diedai(int n) //迭代
{
    int a, b;
    a = b = 1;
    for (int i = 2; i < n; i++)
    {
        a = a + b;
        b = a - b;
    }
    return a;
}

//DP
int dp[800];
int ff(int n)
{
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n - 1];
}
// 不使用数组的ＤＰ
int fibonac(int a, int b, int n)
{
    if (n > 2)
    {
        //printf("a=%d,b=%d,n=%d\n",a,b,n);
        return fibonac(a + b, a, n - 1);
    }
    return a;
}
int main(void)
{
    printf("fun(40)==%d\n", fun(40));

    printf("fibonac(40)==%d\n", fibonac(1, 1, 40));

    for (int i = 0; i < 800; i++)
    {
        dp[i] = -1;
    }
    printf("ff(40)==%d\n", ff(40));

    printf("diedai(40)==%d\n", diedai(40));
}
