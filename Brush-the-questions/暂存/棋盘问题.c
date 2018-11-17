/*************************************************************************
	> File Name: 棋盘问题.c
	> Author: Linuxer_liu
	> Mail: 
	> Created Time: 2017年07月26日 星期三 21时21分11秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#define MAX 10
int n, k ,sum , t ;
int map[MAX][MAX] ;
int visit[100]={0};
int dfs(int a,int b)
{
    int i ,j ;
    if(t == k)
    {
        sum++  ;
        return  0;
    }
    visit[b]= 1; 
    for(i= a+ 1;i<= n;i++ )
    {
        for(j= 1 ;j<= n;j++ )
        {
            if(map[i][j]== '#' && visit[j] == 0)
            {
                t++ ;
                dfs(i ,j);
                t-- ;
            }
        }
    }
    visit[b]= 0;
}
int main(void)
{
    int i,j ;
    while(scanf("%d%d",&n,&k) != EOF)
    {
        if(n== -1 && k== -1)
           break;
        sum = 0;
        for(i= 1 ;i<= n;i++)
        {
            getchar();
            for(j= 1;j<=n;j++)
            {
                scanf("%c",&map[i][j]);
            }
        }
        for(i= 1 ;i<= n;i++)
        {
            for(j= 1;j<= n;j++)
            {
                if(map[i][j]== '#')
                {
                    t = 1;
                    dfs(i ,j);
                }
            }

        }
        printf("%d\n",sum );
    }
}
