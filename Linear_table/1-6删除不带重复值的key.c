/*************************************************************************
	> File Name: 1-6删除不带重复值的key.c
	> Author: 
	> Mail: 
	> Created Time: 2017年07月12日 星期三 20时41分55秒
 ************************************************************************/

#include<stdio.h>

void Delete_key(int a[],int *N ,int key)
{
    int i;
    for(i= 0;i< *N &&  a[i] != key ;i++) ;//查找key
    if(i == *N )
        printf("The key is not exist!! \n");
    else
    {
        *N=*N-1;//不管怎样，只删除一个数据，改变数组个数
        for( ;i< *N ;i++) //移动数组元素
            a[i]=a[i+ 1];
    }
}
int main(void)
{
    int a[8]={3,2,5,8,4,7,6,9};
    int key,i,N = 8;
    printf("please input the key :");
    scanf("%d",&key);
    Delete_key(a,&N,key);
    for(i= 0;i< N;i++)
    printf("%5d",a[i]);
    printf("\n");
    return 0;
}
