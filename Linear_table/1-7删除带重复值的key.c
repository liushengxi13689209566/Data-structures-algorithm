/*************************************************************************
	> File Name: 1-7删除带重复值的key.c
	> Author: 
	> Mail: 
	> Created Time: 2017年07月12日 星期三 21时29分04秒
 ************************************************************************/

#include<stdio.h>
#define N 10
int main(void)
{
    int i,j,n= N;
    int a[N],key;
    for(i= 0;i < N ;i++)
        scanf("%d",&a[i]);
    printf("please input the key :");
    scanf("%d",&key);
    for(i= 0;i< n ;) 
    {
        if(a[i] == key ) //找到的话就移动后续元素
        {
            for(j= i ;j< n- 1;j++)
               a[j]=a[j+ 1];
            n -- ;//如果找到，就把数组个数减一，以避免死循环
        }
        else i++ ;
    }
    if(n == N )
        printf("the key is not exist !!\n");
    for(i= 0;i< n;i++)
        printf("%4d",a[i]);
    printf("\n");
    return 0;
}

