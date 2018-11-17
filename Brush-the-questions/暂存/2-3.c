/*************************************************************************
	> File Name: 2-3.c
	> Author: Linuxer_liu
	> Mail: 
	> Created Time: 2017年07月18日 星期二 14时25分59秒
 ************************************************************************/

#include<stdio.h>

int calculation(int *p ,int m )     //从0加到m ,求出平均数
{
    int result = 0;
    int i;
    for(i= 0 ;i< m ;i++ ,*p+= 2)
        result += *p;
     printf("%.0f",(float)result/m ) ;
}
int main(void)
{
    int a;
    int n ,m;
    while(scanf("%d%d",&n,&m) != EOF)
    {
        a= 2;
        while(n>= m)
        {
            calculation(&a,m);
            n-=m ;
            putchar(n?' ':'\n');
        }
        if(n)
        {
            calculation(&a,n);
            printf("\n");
        }
    }
}


