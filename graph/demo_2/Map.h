/*************************************************************************
	> File Name: Node.h
	> Author: 
	> Mail: 
	> Created Time: 2017年11月27日 星期一 20时29分14秒
 ************************************************************************/

#ifndef _NODE_H
#define _NODE_H
#include<string.h>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
class Node{      //此类表示顶点
    public:
    Node(char data=0); //data == 0 默认函数参数，可不进行传参
    char m_cData ;
    bool visted ; //保存是否被访问
};
class Edge{   //表示边
    public:
        Edge(int  A = 0 ,int B = 0,int w = 0);
        int indexA;  //无向与有向
        int indexB;
        int weight ; 
        bool selected ;
};
class Map{     //图
    public:
    Map(int MAX) ;
    ~Map();
   
    bool addNode(char ch);

    void resetNode();
    bool setValToDirectedGraph(int row,int col,int val = 1);
    bool setValToUndirectedGraph(int row,int col,int val = 1);

    bool getValueFromMartix(int row,int col,int &val);

    void printMartrix();
    void printNode();


    void RealBFS(std::vector<int> TempVec) ;
    void BFS(int NodeIndex);  //递归
    
    
    void primTree(int nodeIndex);
    int getMinEdge(std::vector<Edge>  edgeVec);

    private:
    int MaxVertexCount ;
    int AlreadyInCount ;
    Node *pNodeArray;
    int *pMartrix;
    Edge *pEdge ;
};
#endif
