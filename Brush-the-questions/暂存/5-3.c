/*************************************************************************
	> File Name: 5-3.c
	> Author: Linuxer_liu
	> Mail: 
	> Created Time: 2017年07月21日 星期五 12时56分19秒
 ************************************************************************/

#include<stdio.h>
int main(void)
{
    int n ,i ,x,count;
    while(scanf("%d",&n) != EOF)
    {
        while(n-- )
        {
            count = 3;
            scanf("%d",&x);
            for(i= 0 ;i< x ;i++ )
                count=(count- 1)* 2;
            printf("%d\n",count);
        }
    }
}
