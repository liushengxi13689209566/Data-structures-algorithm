/*************************************************************************
	> File Name: Maze_solution.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月11日 星期三 14时02分34秒
 ************************************************************************/
/*问题描述：迷宫的布局放入到一个二维的数组中  非零0  代表该地方走不通为墙，0 代表该地方可以走通，打印出来小人走的顺序*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#define ROW 9
#define COL 9

int integer[ROW][COL]={
    {1,0,1,1,1,1,1,1,1},
    {1,0,1,1,1,0,0,0,1},
    {1,0,0,0,0,0,1,0,1},
    {1,0,1,1,1,0,1,0,1},
    {1,0,1,0,0,0,1,0,1},
    {1,0,1,1,1,0,1,0,1},
    {1,0,0,0,0,1,1,0,1},
    {1,0,1,1,1,1,1,0,0},
    {1,1,1,1,1,1,1,1,1}
};
int  print(int integer[ROW][COL],int x,int y);

int dir[4][2]={
{1,0},{-1,0},
{0,1},{0,-1},
}  ;     //方向数组,代表 4 个方向

int visted[120][120] ;    //  1  代表访问过  0 代表没有访问过

int check(int x,int y)
{
    if(x< 0 || y<0 || x>= ROW || y>= COL)  
        return 0;
    if(visted[x][y])
        return 0;
    if(integer[x][y] !=  0 )
        return 0;
    return 1;
}

int dfs(int x,int y)    //已经踏到了  x , y ，即x,y  可踏
{
    int xx,yy ,i ;
    usleep(100000);
    printf("\033c");
    print(integer,x,y);

    if(x == 7 && y == 8)
        exit(0);

    for(i= 0;i< 4 ;i++)   // 4 个方向 
    {
        xx =  x + dir[i][0];
        yy =  y + dir[i][1];
        if(check(xx,yy))  //xx ,yy 可踏上去
        {
            visted[xx][yy]= 1;
            dfs(xx,yy) ;
            visted[xx][yy] = 0 ;
        }
    }
    usleep(100000);
    printf("\033c");
    print(integer,x,y);
    return 0;
}

int print(int integer[ROW][COL],int x,int y)
{
    int i,j;
    for(i=0;i<ROW ;i++)
    {
        for(j=0 ;j<COL ;j++)
        
        {
            //if(i == x && j == y )
            if(visted[i][j])
               printf("\033[41;32m  *  \033[0m") ;
            else 
                printf("  %d  ",integer[i][j]);
        }
        printf("\n\n");
    }
}
int main(void)
{
    int i,j ;

    memset(visted,0,sizeof(visted));
    /*
    for(i= 0 ;i< ROW;i++)
    {
        for(j= 0;j< COL ;j++)
        {
            if(integer[i][j] ==  0 && visted[i][j] !=  1 )   //满足返回 1
            {
                visted[i][j]= 1;
                dfs(i,j) ; 
            }
        }
    }
    */
    visted[0][1]=1; //从入口出发
    dfs(0,1) ; 
}

