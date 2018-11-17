
/*##问题描述：
有一头母牛，它每年年初生一头小母牛。每头小母牛从第四个年头开始，每年年初也生一头小母牛。请编程实现在第n年的时候，共有多少头母牛？
Input
输入数据由多个测试实例组成，每个测试实例占一行，包括一个整数n(0<n<55)，n的含义如题目中描述。 
n=0表示输入数据的结束，不做处理。
Output
对于每个测试实例，输出在第n年的时候母牛的数量。 
每个输出占一行。*/


#include<stdio.h>
int fun(int n);
int  main(void)
{
    int n,i,c;
    while(scanf("%d",&n) != EOF)
    {
        if(n == 0)
            break;
        printf("%d\n",fun(n));
    }
}

int fun(int n)
{
    long int f ; //从小的出口,递归退出
    if(n== 1)  
        f= 1;
    if(n == 2)
        f= 2;
    if(n ==  3)
        f= 3;
   if(n> 3)
    f = fun(n-1) + fun(n-3);
    return f;
}
