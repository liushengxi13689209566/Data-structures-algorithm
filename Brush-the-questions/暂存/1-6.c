/*************************************************************************
	> File Name: 1-1.c
	> Author: Linuxer_liu
	> Mail: 
	> Created Time: 2017年07月17日 星期一 13时40分59秒
 ************************************************************************/

#include<stdio.h>
int main(void)
{
    int  sum ,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        sum=0 ;
        while(n--)
        {
            scanf("%d",&j);
            sum+=j;
        }
        printf("%d\n",sum);
    }
}
