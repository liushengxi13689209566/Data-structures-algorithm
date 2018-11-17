/*************************************************************************
	> File Name: 字符串的周期.c
	> Author: Linuxer_liu
	> Mail: 
	> Created Time: 2017年08月07日 星期一 12时48分00秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void)
{
    char str[100];
    char temp[100];
    int n,i ;
    int k,j ;
    while(scanf("%d",&n) != EOF)
    {
        getchar() ;
        while(n--)
        {
            memset(str,0,sizeof(str));
            memset(temp,0,sizeof(temp));
            fgets(str ,1000,stdin);
            len = strlen(str) ;
            temp[0] =  str[0] ;
            j=  1 ;
            for(i= 1 ;str[i] ;i++,j++)
            {
                if(str[i] == str[0]) break;
                temp[j]= str [i];
            }
            if(len % strlen(temp) != 0)  { printf("0\n\n"); break;}
            for(str[])
        }
    }
}

