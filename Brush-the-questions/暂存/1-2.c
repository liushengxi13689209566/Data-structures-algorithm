/*************************************************************************
	> File Name: 1-1.c
	> Author: Linuxer_liu
	> Mail: 
	> Created Time: 2017年07月17日 星期一 13时40分59秒
 ************************************************************************/

#include<stdio.h>
int main(void)
{
    int n ,i ,j,k ;
    while(scanf("%d",&n)!=EOF)
    {
        for(k= 0;k< n;k++)
        {
            scanf("%d %d",&i,&j);
            printf("%d\n",i+j);
        }
    }
}
