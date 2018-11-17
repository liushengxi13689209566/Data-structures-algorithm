/*问题描述：
有一个长度为n(n<=100)的数列，该数列定义为从2开始的递增有序偶数，现在要求你按照顺序每m个数求出一个平均值，如果最后不足m个，则以实际数量求平均值。编程输出该平均值序列。
Input
输入数据有多组，每组占一行，包含两个正整数n和m，n和m的含义如上所述。 
Output
对于每组输入数据，输出一个平均值序列，每组输出占一行。 */

## 一但想到先用数组把数据存起来，那你就OUT了！！！！！！

#include<stdio.h>
int calculation(int *p ,int m )     //从0加到m ,求出平均数
{
    int result = 0;
    int i;
    for(i= 0 ;i< m ;i++ ,*p+= 2)
        result += *p;
     printf("%.0f",(float)result/m ) ;
}
int main(void)
{
    int a;
    int n ,m;
    while(scanf("%d%d",&n,&m) != EOF)
    {
        a= 2;
        while(n>= m)
        {
            calculation(&a,m);
            n-=m ;
            putchar(n?' ':'\n');
        }
        if(n)
        {
            calculation(&a,n);
            printf("\n");
        }
    }
}
