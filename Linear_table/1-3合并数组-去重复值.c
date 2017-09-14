/*************************************************************************
	> File Name: 1-3合并数组-去重复值.c
	> Auchor: 
	> Mail: 
	> Creaced Time: 2017年06月07日 星期三 21时29分12秒
 ************************************************************************/

#include<stdio.h>
#define N 5
#define M 6
int main(void)
{
	int a[N]={11,17,75,77,99};//t1
	int b[M]={2,4,6,15,17,75};//t2
	int c[N+M];//m
	int t1=0,t2=0,m=0,i;
    while(t1<N && t2<M)
	{
		if(a[t1]< b[t2])
		{
			c[m++]=a[t1];
			t1++;
		}
		else if(a[t1] >b[t2])
		{
			c[m++]=b[t2];
			t2++;
		}
        else
        {
            c[m++]=a[t1];
            t1++;
            t2++;
        }
	}
	while(t1>=N&&t2<=M)
	{
		c[m++]=b[t2++];
	}
	while(t2>=N&&t1<=M)
	{
		c[m++]=a[t1++];
	}
	for(i=0;i< m-2;i++)// 0-----(m-1) 
		printf("%d\n",c[i]);
	return 0;
}
