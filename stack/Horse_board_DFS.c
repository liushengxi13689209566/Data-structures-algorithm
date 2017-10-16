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
#include <unistd.h>
#define ROW  8
#define COL  8
/*运行出来是两个36*/
int integer[ROW][COL] ;
int  print(int integer[ROW][COL],int x,int y);

int dir[8][2]={
    {1,2},{2,1},
    {2,-1},{1,-2},
    {-1,-2},{-2,-1},
    {-2,1},{-1,2}
}  ;     //方向数组,代表 8  个方向

int visted[120][120] ;    //  1  代表访问过  0 代表没有访问过

int check(int x,int y)
{
    if(x< 0 || y<0 || x>= ROW || y>= COL)  
        return 0;
    if(visted[x][y])
        return 0;
    return 1;
}

int dfs(int x,int y ,int step_num)    //已经踏到了  x , y ，即x,y  可踏
{
    int xx,yy ,i ;
    //usleep(100000);
    printf("\033c");
    print(integer,x,y);

    if(step_num == 64 )
        exit(1);

    for(i= 0;i<  8 ;i++)   //  8 个方向 
    {
        xx =  x + dir[i][0];
        yy =  y + dir[i][1];
        if(check(xx,yy))  //xx ,yy 可踏上去
        {
            integer[xx][yy]=step_num;
            visted[xx][yy]= 1;
            dfs(xx,yy,step_num+1) ;
            visted[xx][yy] = 0 ;
        }
    }
    //usleep(100000);
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
            if(i == x && j == y )
            //if(visted[i][j])
               printf("\033[41;32m  %d  \033[0m",integer[i][j]) ;
            else 
                printf("  %d  ",integer[i][j]);
        }
        printf("\n\n");
    }
}
int main(void)
{
    int i,j ;
    int step_num = 2  ;

    memset(visted,0,sizeof(visted));
    visted[0][0]= 1; //   从(0,0)出发
    integer[0][0]= 1;
    dfs(0,0,step_num) ; 
}

