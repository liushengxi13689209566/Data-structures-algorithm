/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月10日 星期二 20时39分33秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int cal(char **str,int j)
{
    int temp =0 ;
    int i ;
    for(i= 0 ;i< j;i++)
        temp += *(*str+i);
    return temp ;
}

int main(void)
{
    char *str="abc";
    int t;
    int j=strlen(str);
    t = cal(&str,j);
    printf("t== %d \n",t) ;
}
