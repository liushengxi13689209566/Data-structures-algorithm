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

class Map{
    public:
    Map(int MAX) ;
    ~Map();
    //bool addNode(Node *p);
    bool addNode(char ch);

    void resetNode();
    bool setValToDirectedGraph(int row,int col,int val = 1);
    bool setValToUndirectedGraph(int row,int col,int val = 1);
    void printMartrix();
    void printNode();

    void DFS(int ,int  );
    void ddffss(int,int,int x = 1);

    //void DFS_next(int NodeIndex);  //非递归


    void RealBFS(std::vector<int> &) ;
    void BFS(int NodeIndex);  //递归
    
    //void BFS_next(int NodeIndex);  // 非递归

//    void print() ;
  //  void init() ;
    int MaxVertexCount ;
    int AlreadyInCount ;
    Node *pNodeArray;
    int *pMartrix;
    std::vector<char>  VecString ;

};
#endif
