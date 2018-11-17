/*题目描述：
有一个单人的字母游戏，在一个R行C列的矩阵上进行。矩阵上的每一个点都写着一个大写字母。在游戏开始之前，有一个指示物处于矩阵的左上角（第1行第1列），玩家可以向上下左右四个方向移动这个指示物，但是每个字母只可以经过一次（包括刚开始指向的字母）。 

这个游戏的目标就是尽可能经过更多的字母。现在请你写一个程序，求出在给定矩阵情况下，最多可以经过多少个不同的字母？
Input
输入包含多组数据。

每组数据的第一行包含两个整数R和C，代表是一个R行C列的矩阵（ 1 <= R, S <= 20）。 接下来的R行每行包含S个字母，每一行代表矩阵中该行的字母情况。
Output
对于每一组数据，你只需要在一行中输出一个数字n，代表指示物最多可以经过多少个不同的字母。
Sample Input
3 6
HFDFFB
AJHGDH
DGAGEH
2 2
AA
AA
Sample Output
6
1*/
#include<stdio.h>
#include<string.h>
int R,C ;
int count ;
int max ;
char str[1000][1000];
int dir[4][2]={
{1,0},{-1,0},
{0,1},{0,-1},
}  ;     //方向数组,代表4个方向
int visted[128];    //1  代表访问过  0 代表没有访问过
int check(int x,int y)
{
    if(x< 0 || y< 0 || x>= R || y>= C)  
        return 0;
    if(visted[str[x][y]]) //visted[str[xx][yy]] 的转换是关键
        return 0;
    return 1;
}
int dfs(int x,int y,int count)
{
    int xx,yy ,i ;
    if(max < count)
        max = count ;
    for(i= 0;i< 4 ; i++)     // 4 个方向 
    {
        xx =  x + dir[i][0];  //xx ,yy 代表下一步
        yy =  y + dir[i][1];
        if(check(xx,yy) )   //检查下一步是否可走
        {
            visted[str[xx][yy]]= 1 ; 
            dfs(xx,yy,count + 1) ;
            visted[str[xx][yy]]= 0 ;
        }
    }
    return 0;
}
int main(void)
{
    int i,j ;
    int count ;
    while(scanf("%d%d",&R,&C)!= EOF)
    {
        count = 0;
        max = 0 ;
        memset(str,0,sizeof(str));
        memset(visted,0,sizeof(visted));
        for(i= 0; i< R ;i++ )
              scanf("%s",str[i]);
        count = 1;
        visted[str[0][0]]= 1;
        dfs(0,0,count) ;  //认定第一步踩到第 0 个格子上 
        printf("%d\n",max);
    }
}
