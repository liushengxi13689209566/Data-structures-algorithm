/*************************************************************************
	> File Name: 1-7删除带重复值的key.c
	> Author: 
	> Mail: 
	> Created Time: 2017年07月12日 星期三 21时29分04秒
 ************************************************************************/

#include<stdio.h>
#define N 10
int fun(int a[],int n,int key)
{
    int i,j= 0 ,b[N] ;
    for(i= 0;i< N ;i++) 
    {
        if(a[i] != key ) 
            b[j++]=a[i];
    }
    for(i= j ;i>=0 ;i--)
        a[i]=b[i];
    return j;
}
int main(void)
{
    int i,j,n= N;
    int a[N],key;
    for(i= 0;i < N ;i++)
        scanf("%d",&a[i]);
    printf("please input the key :");
    scanf("%d",&key);
    n=fun(a,n,key);
    if(n == N) 
        printf("the key is not exist !!\n");
    for(i= 0;i< n;i++)
        printf("%4d",a[i]);
    printf("\n");
    return 0;
}

