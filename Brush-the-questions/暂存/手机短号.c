/*************************************************************************
	> File Name: 手机短号.c
	> Author: Linuxer_liu
	> Mail: 
	> Created Time: 2017年07月22日 星期六 15时25分34秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main(void)
{
    int n;
    char str[21],i ;
    int len ;
    while(scanf("%d",&n) != EOF )
    {
        getchar() ;
        while(n--)
        {
            scanf("%s",str);
            len = strlen(str);
            printf("6");
            for(i= len- 5;i< len ;i++)
            printf("%c",str[i]);
            printf("\n");
        }
    }
}

