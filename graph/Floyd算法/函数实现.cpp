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
            printf("%-8d",G.arcs[i][j]);
        }
        printf("\n");
    }
}
void Graph::Floyd(Graph &G ,int F[][20])
{
    int path[20][20];
    for(int i= 0 ;i != G.vexnum ;++i)
    {
        for(int j=0;j != G.vexnum ;++j)
        {
            F[i][j] = G.arcs[i][j];
            path[i][j] = INFINITY ;        
        }
    }
    /*for(int k= 0 ;k != G.vexnum ;++k)
    {
        for(int  i =0;i != G.vexnum ;++i)
        {
            for(int j= 0 ;j !=G.vexnum ;++j)
            {
                if(F[i][j] >  (F[i][k] + F[k][j]));
                {
                    F[i][j] = F[i][k] + F[k][j]; 
                    path[i][j] =  k; //k 点作为中转点，存入
                }
            }
        }
    }*/
    int n= G.vexnum ;
    for(int k = 0;k < n ; k++)
    {
        for(int i = 0;i < n; i++)
        {
            for(int j = 0;j< n ; j++)
            {
                if(F[i][j] > (F[i][k] + F[k][j]))
                { 
                    F[i][j] = F[i][k] + F[k][j];
                    path[i][j] =  k; //k 点作为中转点，存入
                }
            }
        }
    } 
    for(int i= 0;i < 5  ;++i)
    {
        for(int j=0;j< 5;++j)
        {
            printf("path == %-8d",path[i][j]);
        }
        printf("\n");
    }
    for(int i= 0;i < 5  ;++i)
    {
        for(int j=0;j< 5;++j)
        {
            printf("F[][] == %-8d",F[i][j]);
        }
        printf("\n");
    }

    printf("please input the start and end  \n");
    int start ,end ;
    cin >> start >> end ;
    getPath(start,end,path);
}
void Graph::getPath(int i ,int j,int path[][20]){
    if(i==j)     return;
    if(path[i][j] == INFINITY ) printf("%c ",j+'a');
    else{
        getPath(i,path[i][j],path);
        getPath(path[i][j],j,path);
    }
}
