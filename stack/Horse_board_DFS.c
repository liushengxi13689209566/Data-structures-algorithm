/*************************************************************************
	> File Name: Horse_board_DFS.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月15日 星期日 21时59分51秒
 ************************************************************************/

/*问题描述：
* 将马随机放在国际象棋的Board[0～7][0～7]的某个方格中，马按走棋规则进行移动。走遍棋盘上全部64个方格。
* 编制程序，求出马的行走路线，并按求出的行走路线，将数字1，2，…，64依次填入一个8×8的方阵，输出之。*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#define ROW  8
#define COL  8

int integer[ROW][COL] ;
int  print(int integer[ROW][COL]);

int dir[8][2]={
    {1,2},{2,1},
    {2,-1},{1,-2},
    {-1,-2},{-2,-1},
    {-2,1},{-1,2}
}  ;     //方向数组,代表 8  个方向

int check(int x,int y)
{
    if(x< 0 || y<0 || x>= ROW || y>= COL || integer[x][y]  !=  0 )    //不是0 ，就不能走了 
        return 0;
    return 1;
}

int dfs(int x,int y ,int step_num)    //已经踏到了  x , y ，即x,y  可踏
{
    int xx,yy ,i ;
    if(step_num == 65 )  //思考一下为什么是25 ？当下面step_num == 63赋值完成后时，step_num === 64 进入dfs ，遇到if 终止程序了，故64并没有被赋值
    {
        print(integer);
        exit(1);
    }
    for(i= 0;i< 8 ;i++)   //  8 个方向 
    {
        xx =  x + dir[i][0];
        yy =  y + dir[i][1];
        if(check(xx,yy))  //xx ,yy 可踏上去
        {
            integer[xx][yy]=step_num;
            dfs(xx,yy,step_num+1) ;
            integer[xx][yy]= 0;    //回朔
        }
    }
    return 0;
}
int print(int integer[ROW][COL])
{
    int i,j;
    for(i=0;i<ROW ;i++)
    {
        for(j=0 ;j<COL ;j++)
        {
            printf("%6d",integer[i][j]);
        }
        printf("\n\n");
    }
}
int main(void)
{
    int i,j ;
    memset(integer,0,sizeof(integer));
    integer[0][0]= 1;
    dfs(0,0,2) ; 
}

