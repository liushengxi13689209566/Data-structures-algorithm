/*************************************************************************
	> File Name: 相对分子质量.c
	> Author: Linuxer_liu
	> Mail: 
	> Created Time: 2017年08月07日 星期一 13时47分05秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void)
{
    char str[100];
    int n ;
    char temp[50];
    double sum = 0 ;
    int i,j ;
    while(scanf("%d",&n) != EOF )
    {
        getchar();
        while(n--)
        {
            sum= 0 ;
            memset(str,0,sizeof(str));
            memset(temp,0,sizeof(temp));
            fgets(str,0,sizeof(str));
            for(i= 0 ;str[i] ;i++)
            
