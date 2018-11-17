/*题目描述：
zty是一个充满热情的男人，他励志解决世界上所有的ACM难题。
但他有一个怪癖，他不喜欢刷一个比他刷过的题更简单的题。
现在他找到了n个难题，并且估算出了他在解决某道题之后解决另一道题所需要的时间。
现在需要你编写程序来帮助zty算出他在满足他的怪癖下最多可以解决几道题。

已知：
①zty是一个很强大的人，他解决第1个问题所需时间仅仅为0分钟。
②一个题花费的时间越多，那么它肯定更难。
③而正如前面所说的，zty总是选择难度不小于上一题的题目来解决。
Input
输入包含多组测试数据。
每组输入数据的最开始是一个整数n，代表有n个难题。( 2< n < 15)。
接下来的n行每行包含n个整数，假设我们用T(i,j)表示第i行第j列的整数的话，T(i,j)的意思是当zty解决了问题i之后，
解决问题j需要花费T(i,j)分钟。我们保证：0 <= n <= 10.
Output
对于每组输入数据，输出他最多可以刷多少道题。
Sample Input
3
0 0 0
1 0 1
1 0 0
3
0 2 2
1 0 1
1 1 0
5
0 1 2 3 1
0 0 2 3 1
0 0 0 3 1
0 0 0 0 2
0 0 0 0 0
Sample Output
3
2
4
Hint
对于样例②，刚开始zty在0分钟内解决了第1题，当他解决问题1之后，他可以选择问题2或者问题3，
因为T(1,2)==2>0，T(1,3)==2>0。假设他选择了问题2，那么由于T(2,3)==1<2，
因此他将不能继续刷问题3。假设他选择了问题3，那么由于T(3,2)==1<2，所以他也不能刷问题2。
因此最终结果为2。*/

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
int  n ,max ;
int a[20][20];   // 保存题目
int visted[100]  ;
int dfs(int x,int time ,int count )  //x 表示当前题 ，time 表示做当前题目所需要的时间 ， count **表示一条路上**的最大题目数量 
{
    int i ;
    if(max < count)
        max =count ;  //max 表示最终 ,最大的题目数量
    for( i= 2 ; i<= n  ; i++ )   //i 表示下一道题
    {
        if( ( time<= a[x][i])  && !visted[i] ) //比较时间和标记
        {
            visted[i] =  1;
            dfs(i,a[x][i],count + 1);
            visted[i] = 0;
        }
    }
}
int main(void)
{
    int i ,j ;
    int count ;
    while(scanf("%d",&n) != EOF)
    {
        count  = 0;
        max = 0;
        memset(a,0,sizeof(a));
        memset(visted,0,sizeof(visted));
        for(i= 1 ;i<= n;i++)
            for(j= 1;j<= n;j++)
                scanf("%d",&a[i][j]);
        dfs(1,0,1) ;
        printf("%d\n",max);
    }
}
