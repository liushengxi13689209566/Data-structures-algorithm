/*************************************************************************
	> File Name: 3-2.c
	> Author: Linuxer_liu
	> Mail: 
	> Created Time: 2017年07月19日 星期三 13时18分58秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main(void)
{
    int n ,i;
    int flag ;
    char str[10000] ;
    while(scanf("%d",&n) != EOF)
    {
        while(n--)
        {
            getchar();
            flag = 0;
            gets(str);
            for(i =0 ;str[i] ;i++)
            {
                if(str[i]  <  0)
                flag++;
            }
            printf("%d\n",flag /2 ) ;
        }

    }
}
