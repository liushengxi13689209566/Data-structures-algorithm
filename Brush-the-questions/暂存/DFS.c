#include <stdlib.h>
#include <string.h>
#include<stdio.h> 
#define MAX 9
 
int n, k, sum, sumk;
char map[MAX][MAX];
int visit[100] = {0};
void dfs(int a, int b)
{
    int i, j;
    if (sumk == k)
    {
        sum++;
        return;
    }
    /* 置当前列不可放 */
    visit[b] = 1;
    /* 从下一行开始搜索 */
    for (i = a + 1; i <= n; i++)
    {
        /* 每一行从左向右搜索 */
        for (j = 1; j <= n; j++)
        {
            if (map[i][j] == '#' && visit[j] == 0)
            {
                /* 格子可放棋子数 + 1 */
                sumk++;
                /* 继续向下搜索 */
                dfs(i, j);
                /* 回溯时棋子数 - 1 */
                sumk--;
            }
        }
    }
    /* 回溯时重置列可放 */
    visit[b] = 0:
