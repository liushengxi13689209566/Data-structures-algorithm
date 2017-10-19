/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月12日 星期四 16时02分08秒
 ************************************************************************/

#include<stdio.h>
int main(void)
{
    int i,j ;
    int integer[100][100];
    int m,n ;
    printf("请输入迷宫的行数与列数：");
    scanf("%d%d",&m,&n);
    getchar();
    for(i= 0; i< m ;i++ )
        for(j= 0 ;j< n ;j++)
            scanf("%d",&integer[i][j]);  //输入二维数组

    for(i= 0; i< m ;i++ )
    {    for(j= 0 ;j< n ;j++)
            printf("\t%d\t",integer[i][j]);  //输入二维数组
    printf("\n");
    }
}

