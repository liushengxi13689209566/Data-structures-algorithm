/*************************************************************************
	> File Name: 5-1.c
	> Author: Linuxer_liu
	> Mail: 
	> Created Time: 2017年07月21日 星期五 12时14分05秒
 ************************************************************************/

#include<stdio.h>
int main(void)
{
    double sum= 0,x;
    int i;
    for(i= 0 ;i< 12 ;i++)
    {
        scanf("%lf",&x) ;
        sum += x;
    }
    printf("$%.2lf\n",sum/12);
    return 0;
}
