/*题目描述：
GeoSurvComp地质调查公司负责探测地下石油储藏。 GeoSurvComp现在在一块矩形区域探测石油，并把这个大区域分成了很多小块。他们通过专业设备，来分析每个小块中是否蕴藏石油。如果这些蕴藏石油的小方格相邻，那么他们被认为是同一油藏的一部分。在这块矩形区域，可能有很多油藏。你的任务是确定有多少不同的油藏。

Input
输入可能有多个矩形区域（即可能有多组测试）。每个矩形区域的起始行包含m和n，表示行和列的数量，1<=n,m<=100，如果m =0表示输入的结束，接下来是n行，每行m个字符。每个字符对应一个小方格，并且要么是'*'，代表没有油，要么是'@'，表示有油。

Output
对于每一个矩形区域，输出油藏的数量。两个小方格是相邻的，当且仅当他们水平或者垂直或者对角线相邻（即8个方向）。

Sample Input
 
1 1
*
3 5
*@*@*
**@**
*@*@*
1 8
@@****@*
5 5 
****@
*@@*@
*@**@
@@@*@
@@**@
0 0 
 
Sample Output
0
1
2
2*/
#include<stdio.h>
#include<string.h>
int m,n ;
char str[1000][1000];
int dir[8][2]={
{1,0},{-1,0},
{0,1},{0,-1},
{1,1},{-1,1},
{-1,-1},{1,-1}
}  ;     //方向数组,代表八个方向
int visted[120][120] ;    //1  代表访问过  0 代表没有访问过
int check(int x,int y)
{
    if(x< 0 || y<0 || x>=m || y>=n)  
        return 0;
    if(visted[x][y])
        return 0;
    if(str[x][y]!='@')
        return 0;
    return 1;
}
int dfs(int x,int y)
{
    int xx,yy ,i ;
    for(i= 0;i< 8;i++)   // 8 个方向 
    {
        xx =  x + dir[i][0];
        yy =  y + dir[i][1];
        if(check(xx,yy))
        {
            visted[xx][yy]= 1 ;
            dfs(xx,yy) ;
        }
    }
    return 0;
}
int main(void)
{
    int i,j ;
    int count ;
    while(scanf("%d %d",&m,&n)!= EOF)
    {
        getchar();
        if(!m)
            break ;
        memset(str,0,sizeof(str));
        memset(visted,0,sizeof(visted));
        count = 0 ;
        for(i= 0; i< m ;i++ )
              scanf("%s",str[i]);
        for(i= 0 ;i<  m;i++)
        {
            for(j= 0;j<  n ;j++)
            {
                if(str[i][j]== '@' && visted[i][j]!= 1)   //满足返回 1
                {
                    visted[i][j]= 1;
                    dfs(i,j) ; 
                    count++  ;
                }
            }
        }
        printf("%d\n",count);
    }
}
