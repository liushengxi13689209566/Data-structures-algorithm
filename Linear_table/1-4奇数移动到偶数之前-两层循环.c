/*************************************************************************
	> File Name: 1-4奇数移动到偶数之前.c
	> Author: 
	> Mail: 
	> Created Time: 2017年06月14日 星期三 22时02分56秒
 ************************************************************************/
//奇偶 ，奇奇，偶偶，偶奇
#define N 8
#include<stdio.h>
void Inverse(int a[],int start,int end)
{
    int i,j,temp;
    temp=a[start] ;
    for(i=start;i< end  ;i++) //移动
        a[i]=a[i+ 1] ;
    a[end]=temp ;
}
int main(void)
{
    int a[N] ;
    int i,j,n =N;
    printf("Please intput the datas\n");
    for(i= 0;i< N;i++)
        scanf("%d",&a[i]);
    for(i= 0;i< N;i++)
           printf("%5d",a[i]);
    printf("\n") ;
    for(i= 0;i< n ;)
    {
        if(!(a[i]% 2))   //是偶数，往最后一位移动
        {
            Inverse(a,i,N-1) ;
            n--;
        }
        else i++ ;
    }

    printf("The array is processed : ") ;
    for(i= 0;i< N;i++)
        printf("%5d",a[i]) ;
    printf("\n") ;
    return 0;
}
