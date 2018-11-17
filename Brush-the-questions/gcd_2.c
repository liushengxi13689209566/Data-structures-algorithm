/*有三个正整数a,b,c(0<a,b,c<10^6)，其中c不等于b。若a和c的最大公约数为b，现已知a和b，求满足条件的最小的c。 
Input
第一行输入一个n，表示有n组测试数据，接下来的n行，每行输入两个正整数a,b。 
Output
输出对应的c，每组测试数据占一行。 
Sample Input
2
6 2
12 4
Sample Output
4
8*/
#include<stdio.h>
int gcd(int a,int b) 
{
    return a%b ?gcd(b,a%b):b;
}
int main(void)
{
    int n  ,i ,a,b;
    while(scanf("%d",&n) != EOF)
    {
        getchar();
        while(n--)
        {
            scanf("%d%d",&a,&b);
            i = b ;
            while(1)
            {
                i++ ;
                if(gcd(a,i) == b)
                break ;
            }
            printf("%d\n",i);
        }
    }
}
//这没什么说的吧！！！
