/*************************************************************************
	> File Name: myhead.h
	> Author: 
	> Mail: 
	> Created Time: 2017年12月30日 星期六 22时31分17秒
 ************************************************************************/

#ifndef _MYHEAD_H
#define _MYHEAD_H
#define MAXVEX  20 
#define INFINITY 32768
class Node{   //顶点
    public:
    Node() = default ;
    private:
    char str ;
    friend class Graph ;
};
class Graph{
    public:
    Graph() ;
    void create(Graph &); //创建图
    void print(Graph &); 
    void Floyd(Graph &,int F[][20]) ;
    void getPath(int ,int ,int path[][20]) ;
    private:
    int arcs[MAXVEX][MAXVEX];
    Node vex[MAXVEX];
    unsigned int vexnum ; //顶点数
    unsigned int arcnum ;  //边数
};
#endif
