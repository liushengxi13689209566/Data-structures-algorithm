/*************************************************************************
	> File Name: 气球问题.c
	> Author: Linuxer_liu
	> Mail: 
	> Created Time: 2017年08月07日 星期一 19时21分32秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 1005
int main(void)
{
    char str[N][20] ;
    int n ;
    int count[1005];
    int temp ;
    int i ,j ,t ;
    while(scanf("%d",&n) != EOF )
    {
        if(n == 0)     break ;
        memset(count,0,sizeof(count));
        for(i= 0 ;i< n ;i++ )
            scanf("%s",str[i]);
        for(i= 0;i <  n-1 ; i++ )
        {
            for(j= i+ 1 ;j< n ;j++)
            {
                if( !strcmp(str[i],str[j])  )
                {
                    count[i]++ ;  /*存储第 i 个颜色出现的次数*/
                }
            }
        }
        temp = count[0];
        t= 0 ;
        for(j= 0;j< i ;j++ )
            if(count[j] > temp)  { temp= count[j];t= j ;} //t 就是最大次数的下标
        printf("%s\n",str[t]);
    }
}


