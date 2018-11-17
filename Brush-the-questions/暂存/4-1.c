/*************************************************************************
	> File Name: 4-1.c
	> Author: Linuxer_liu
	> Mail: 
	> Created Time: 2017年07月20日 星期四 12时26分21秒
 ************************************************************************/

#include<stdio.h>
int main(void)
{
	int i,t,n,sum,m,temp;
    int flag ;
	while(scanf("%d%d",&m,&n) != EOF)
    {
        flag= 0 ;
        for(i = m ;i<= n;i++)
        {
		    t = i;    //用复制出的模板进行计算，用真实值做最终比较！！！1 
		    sum=0;
		    for(;t> 0;) 
		    {
			    temp=t%10;
			    sum=sum+temp*temp*temp;
			    t=t/10;
		    }
		    if(sum == i ) //找到水仙花数 
            {
                flag++;
                printf("%d ",i);
            }
        }
        if(flag == 0)
            printf("no\n");
        else printf("\n");
    }
} 	
