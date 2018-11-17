/*题目描述：
Description
整天待在方块里的骑士感到特别的无聊，于是他决定来一场说走就走的旅行。
然而他只能走日字，如右图所示，如果骑士当前在棋盘的正中央，他可以走标记有白点的八个区域。
骑士知道世界是一个列数和行数均不超过8（即8×8）的棋盘。
并且骑士有一点强迫症，如果用A-Z来表示列，1-99来表示横行，他只愿意走字典序最小的一条道路。
你能帮助勇敢的骑士制定一个适合他的旅行计划，使得他可以走遍整个棋盘吗？骑士可以在任一方块出发或者结束。
Input
第一行中有一个正整数n，代表数据有n组。
对于每组数据，都含有两个正整数p和q(1 <= p * q <= 26)，代表棋盘有p行q列。
Output
每组数据首先应当输出"Scenario #i:"，i代表输出的是第i组数据的结果。
然后在一行之内输出一条可以走遍棋盘的路径，如果有多条路径可以走遍棋盘，那么输出按字典序排序第一的路径。
最后，留一个空行。若现在是最后一条数据，则不留空行。

在输出路径时，用A代表第一列，B代表第二列..以此类推。而使用1代表第一行，2代表第二行。
例如，若要表示从第一行第一列到第二行第三列，可以用字符串：A1C3来表示。
Sample Input
样例输入①：
3
1 1
2 3
4 3

样例输入②：
4
5 5
3 3
4 5
6 3
Sample Output
样例输出①：
Scenario #1:
A1

Scenario #2:
impossible

Scenario #3:
A1B3C1A2B4C2A3B1C3A4B2C4

样例输出②：
Scenario #1:
A1B3A5C4A3B1D2E4C5A4B2D1C3B5D4E2C1A2B4D5E3C2E1D3E5

Scenario #2:
impossible

Scenario #3:
A1B3C1A2B4D3E1C2D4E2C3A4B2D1E3C4A3B1D2E4

Scenario #4:
impossible*/

#include<stdio.h>  
#include<string.h>  
  
#define maxn    30 
int vis[maxn][maxn];  
int n,m;  
int dir[8][2] = {-2,-1, -2,1, -1,-2, -1,2, 1,-2, 1,2, 2,-1, 2,1};  
//注意方向也要按照字典序来 ！！！
struct Path{  
    int x,y;  
}p[maxn];  //保存走的路径
int flag;  //作为结束标志
int check(int xx,int yy)  //check函数，检查路径
{
    if(xx <  1 || xx >  n || yy < 1 || yy > m) //最终xx输出为列，所以与n 比较 ！！！！
        return 0;
    if(vis[xx][yy] != 0)
            return 0;
    return 1 ;
}
void dfs(int x, int y, int step)  
{  
    if(flag )
        return ;
    p[step].x = x; //结构体数组保存所走的路径 
    p[step].y = y;  
    if(step == n*m)  
    {  
        flag = 1;  
        return;  
    }  
    struct  Path next;  
    int i ;
    for( i = 0; i < 8; i++)   /*八个方向*/
    {  
        next.x = x + dir[i][0];  
        next.y = y + dir[i][1];  
        if(check(next.x,next.y))  
        {  
            vis[next.x][next.y] = 1;  
            dfs(next.x, next.y, step+ 1); 
            vis[next.x][next.y] =  0;  /*需要回退*/
        }  
    }  
    return;  
}  
int main(void)  
{  
    int T,i,t;  
    while(scanf("%d", &T) != EOF ) 
    {
        for( t = 1; t <= T; t++)  
        {  
            scanf("%d%d", &m,&n);    //先输入行再输入列
            memset(vis,0,sizeof(vis));  
            memset(p,0,sizeof(p));  
            flag = 0;  
            vis[1][1] = 1;  
            dfs(1,1,1);  
            printf("Scenario #%d:\n", t);  
            if(flag)  
            {  
                for( i = 1; i <= n*m; i++)  
                    printf("%c%d", p[i].x-1+'A', p[i].y);  
                printf("\n");  
            }  
            else printf("impossible\n");  
            if(t != T) printf("\n");  
        }  
    }
    return 0;  
}  
