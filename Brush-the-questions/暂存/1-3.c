/*************************************************************************
	> File Name: 1-1.c
	> Author: Linuxer_liu
	> Mail: 
	> Created Time: 2017年07月17日 星期一 13时40分59秒
 ************************************************************************/

#include<stdio.h>
int main(void)
{
    int i ,j;
    while(scanf("%d %d",&i,&j)!=EOF)
    {
        if( i == 0 && j == 0 ) return 0;
        else  printf("%d\n",i+j);
    }
}
