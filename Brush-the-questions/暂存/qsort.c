/*************************************************************************
	> File Name: qsort.c
	> Author: Linuxer_liu
	> Mail: 
	> Created Time: 2017年07月24日 星期一 21时43分55秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<time.h>
#define SIZE 10000
int cmp(const void *a,const void *b)
{
    return(*(int *)b - *(int *)a);
}
int main (void)
{
    int a[SIZE];
    int i;
    srand(time(NULL));
    for(i=  0 ;i< SIZE ;i++)
    {
        a[i]=rand() /600;
    }
    qsort(a,SIZE,sizeof(int),cmp) ;
    for(i=  0 ;i< SIZE ;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
    return  0;
}
