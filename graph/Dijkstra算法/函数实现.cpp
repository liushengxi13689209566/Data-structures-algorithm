/*************************************************************************
	> File Name: 函数实现.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月30日 星期六 22时41分09秒
 ************************************************************************/

#include<iostream>
#include"myhead.h"
using namespace std;
Graph::Graph()
{
    int i,j;
    for(i = 0 ;i != MAXVEX ;++i)
    {
        for(j= 0;j != MAXVEX ;++j)
        {
            arcs[i][j] = INFINITY ; //无穷大
        }
    }
    vexnum = 0 ;
    arcnum = 0 ;
}
void Graph::create(Graph &G)
{
    printf("请输入有向图的顶点数和边数：\n");
    cin >> G.vexnum >> G.arcnum ;
    printf("请输入有向图%d 个顶点 \n",G.vexnum);
    for(int i=0 ;i != G.vexnum ;++i)
    {
        printf("第%d 个顶点：",i+1);
        cin >>  G.vex[i].str  ; 
    }
    printf("请输入有向图%d 个边  \n",G.arcnum);
    printf("A_index--------->B_index \n");
    unsigned int A_index ,B_index ,weight ;
    for(int i= 0;i != G.arcnum ;++i)
    {
        printf("第%d 条边：",i+1);
        cin >> A_index >> B_index ;
        printf("权值\n");
        cin >> weight ;
        G.arcs[A_index][B_index] = weight ;
    }
}
void Graph::print(Graph &G)
{
    for(int i= 0;i != G.vexnum ;++i)
    {
        for(int j= 0 ;j != G.vexnum ;++j)
        {
            printf("  %d  ",G.arcs[i][j]);
        }
        printf("\n");
    }
}
void Graph::Dijkstra(Graph &G,int start,int end ,int *dist,int path[][20]) //path 初始化为-1
{
     for(int i= 0;i < 20 ;++i)
    {
        for(int j=0;j< 20;++j)
        {
            path[i][j] = -1;
        }
    }
    for(int i= 0;i != G.vexnum ;++i)
    {
        dist[i] = G.arcs[start][i] ; //把该行抽离出来
        if(G.arcs[start][i] != INFINITY ) //如果有路，就把start 点记录在path 数组中
            path[i][1] = start ;
    }
    path[start][0] = 666  ;// start 进入 集合 S
    int temp ,k ;
    for(int i= 1 ;i != G.vexnum ;++i)
    {
        temp = INFINITY ;
        for(int j= 0; j!= G.vexnum ;++j)
        {
            if(path[j][0] == -1  && dist[j] < temp ) 
            {
                k= j;
                temp = dist[j];
            }
        }
        if(temp == INFINITY ) return ;
        path[k][0] = 666 ; //表示已经加入集合 S
        int t ;
        for(int j= 0 ;j != G.vexnum ; ++j)
        {
            if(path[j][0] == -1 && G.arcs[k][j] < INFINITY )
            {
                if(dist[k]+ G.arcs[k][j] < dist[j])
                {
                    dist[j] = dist[k] + G.arcs[k][j];
                    t= 1;
                    while(path[k][t] != -1  ) //记录最短路径
                    {
                        path[j][t] = path[k][t];
                        t++ ;
                    }
                    path[j][t] = k;
                    path[j][t+1] = -1;
                }
            }
        }
        for(int i= 0; i< 20 ;i++)
        {
            for(int j=1;j< 20 ;++j)
            {
                if(path[i][j] != -1 )
                    cout << G.vex[path[i][j]].str << "  " ;
            }
            cout << endl ;
        }
          
    }
}



