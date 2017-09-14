/*************************************************************************
	> File Name: 1.c
	> Author: 
    > goal:求负数的最大值与次大值 
	> Created Time: 2017年06月07日 星期三 19时53分00秒
 ************************************************************************/

#include<stdio.h>
int main(void)
{
    int a[8]={3,-2,-5,8,-4,7,2,-1} ;
    int count=0,max1 ,max2 ;
    int i,temp[8] ;
    for(i= 0 ;i< 8 ;i++)
    {
        if(a[i] < 0) temp[count++]=a[i] ;
    }   //count出来之后就是所存负数的个数
    max1=temp[0] ;
    max2=temp[1] ;
    for(i= 1 ;i<count ;i++)
    {
        if(temp[i]>max1) 
        {
            max2=max1 ;
            max1=temp[i] ;
        }
        else if(temp[i]>max2)  max2=temp[i] ;
    }
    printf("最大值为%d ,次大值为%d \n",max1,max2) ;
    return 0;
}
