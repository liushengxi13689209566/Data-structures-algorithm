/*************************************************************************
	> File Name: 最大公约数为b.c
	> Author: Linuxer_liu
	> Mail: 
	> Created Time: 2017年07月25日 星期二 10时53分23秒
 ************************************************************************/

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
