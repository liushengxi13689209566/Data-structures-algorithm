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
class Node{      //此类表示顶点
    public:
    Node(char data=0); //data == 0 默认函数参数，可不进行传参
    char m_cData ;
};

class Map{
    public:
    Map(int MAX) ;
    ~Map();
    bool addNode(char ch);

    bool setValToDirectedGraph(int row,int col,int val = 1);
    bool setValToUndirectedGraph(int row,int col,int val = 1);
    void printMartrix();
    void printNode();

    private:
    int MaxVertexCount ;
    int AlreadyInCount ;
    Node *pNodeArray;
    int *pMartrix;
};
#endif
