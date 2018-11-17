/*************************************************************************
	> File Name: 1-1.c
	> Author: Linuxer_liu
	> Mail: 
	> Created Time: 2017年07月17日 星期一 13时40分59秒
 ************************************************************************/

#include<stdio.h>
int main(void)
{
    int  sum ,j,n ,m;
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            scanf("%d",&m);
            sum = 0;
            while(m--)
            {
                scanf("%d",&j);
                sum+=j;
            }
            if(n == 0)
                 printf("%d\n",sum);
            else
                 printf("%d\n\n",sum);
        }
    }
}
