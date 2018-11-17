/*************************************************************************
	> File Name: 进制数的相加.c
	> Author: Linuxer_liu
	> Mail: 
	> Created Time: 2017年07月27日 星期四 17时09分23秒
 ************************************************************************/


#include<stdio.h>
#include<math.h>
#include<stdlib.h>
double array[10000]={0};
double fun(double a,double  b)
{
    int i;
    double sum = array[0];
    for(i= 1;i< a;i++)
    {
        sum= array[i]*pow(b,i)+ sum  ;
    }
    return sum ;
}
int main(void)
{
    double n,x,m,y;
    double t1,t2 ;
    int i;
    scanf("%lf%lf",&n,&x);
    for(i= n-1 ;i>= 0 ;i--)
       scanf("%lf",&array[i]);
    t1=fun(n,x);
    scanf("%lf%lf",&m,&y);
    for(i= m-1 ;i>= 0 ;i--)
       scanf("%lf",&array[i]);
    t2=fun(m,y);
    if(t1== t2)
       printf("=\n");
    if(t1< t2)
       printf("<\n");
    if(t1> t2)
       printf(">\n");
}
