/*************************************************************************
	> File Name: 小明A+B.c
	> Author: Linuxer_liu
	> Mail: 
	> Created Time: 2017年07月22日 星期六 15时38分29秒
 ************************************************************************/

#include<stdio.h>
int main(void)
{
    int n ;
    int a,b,sum ;
    while(scanf("%d",&n) != EOF)
    {
        while(n--)
        {
            scanf("%d%d",&a,&b);
            a=a%100 ;
            b=b%100;
            sum =a+b;
            printf("%d\n",sum%100);

        }
    }
}
