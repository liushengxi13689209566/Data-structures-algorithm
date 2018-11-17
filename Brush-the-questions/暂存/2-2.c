/*************************************************************************
	> File Name: 2-2.c
	> Author: Linuxer_liu
	> Mail: 
	> Created Time: 2017年07月18日 星期二 12时38分13秒
 ************************************************************************/
#include<stdio.h>
int main(void)
{
    int  j,n,i,n_temp ;
    int max,min ;
    int  a[100]={0} ;
    float sum ;
    while(scanf("%d",&n) != EOF)
    {
        i= 0;
        sum = 0;
        n_temp=n ;
        while(n_temp--)
        {
            scanf("%d",&a[i]);
            i++ ;
        }
        max=min=a[0];
        for(i= 0 ;i< n;i++)
        {
            if(a[i]> max )  max=a[i];
            if(a[i] < min)  min=a[i] ;
        }
        for(i= 0 ;i< n;i++)
        {
            if(a[i] == max || a[i] == min)
                continue ;
            else sum+=a[i];
        }
        printf("%.2f\n",sum/(n-2));
    }
    }
