/*************************************************************************
	> File Name: 1_顺序查找.c
	> Author: 
	> gola:找到返回下标，找不到返回-1
	> Created Time: 2017年06月07日 星期三 20时59分34秒
 ************************************************************************/

#include<stdio.h>
#define n 9
int main(void)
{
    int a[n]={1,2,3,4,5,6,7,8,9} ;
    int i,key;
    printf("请输入key : ") ;
    scanf("%d",&key) ;
    for(i=0 ;i< n;i++)
    {
        if(a[i] == key )
        break ;
    }
    if(i>=n)  i= -1;
    return  i ;

}
