/*************************************************************************
	> File Name: 1-4奇数移动到偶数之前-一层循环.c
	> Author: 
	> Mail: 
	> Created Time: 2017年06月15日 星期四 09时53分08秒
 ************************************************************************/
#define N 8
#include<stdio.h>
int main(void)
{
    int i,j,temp;
    int a[N];
    for(i= 0;i< N;i++)
        scanf("%d",&a[i]);
    for(i= 0,j= N-1;i< j;)
    {
        if(a[i]%2) i++;//前面是奇数
        if(!(a[j]%2)) j--;//后面是偶数
        if((!(a[i]%2))&&(a[j]%2))//前偶后奇时，交换.换完之后再推进
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i++;
            j--;
        }
    }
    for(i= 0;i< N;i++)
        printf("%5d",a[i]);
    printf("\n");
    return 0 ;
}
