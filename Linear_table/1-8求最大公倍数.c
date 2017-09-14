/*************************************************************************
	> File Name: 1-8求最大公倍数.c
	> Author: Linuxer_liu
	> Mail: 
	> Created Time: 2017年07月13日 星期四 17时05分01秒
 ************************************************************************/

#include<stdio.h>
int main(void)
{
    int x,y,k;
    printf("please input the x and y : ");
    scanf("%d",&x);
    scanf("%d",&y);
    for(k=x< y?x:y ;k> 1;k--)
    {
        if(x%k == 0 && y%k == 0)
            break;
    }
    printf("the result is %d \n",k);
    return 0;
}
