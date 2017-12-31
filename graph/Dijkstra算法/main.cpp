/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月31日 星期日 10时47分03秒
 ************************************************************************/

#include<iostream>
#include"myhead.h"
using namespace std;
int main(void)
{
    Graph g ;
    g.create(g);
    g.print(g);
    int dist[20];
    int path[20][20];
    for(int i= 0;i < 20 ;++i)
    {
        for(int j=0;j< 20;++j)
        {
            path[i][j] = -1;
        }
    }
    g.Dijkstra(g,0,1,dist,path);
    for(int i= 0;i < 5  ;++i)
    {
        for(int j=0;j< 5;++j)
        {
            printf("path == %d ",path[i][j]);
        }
        printf("\n");
    }
    for(int i= 0 ;i< 5 ;++i)
        printf("\n\ndist == %d  ",dist[i]);
    printf("\n");

    return 0;

}
