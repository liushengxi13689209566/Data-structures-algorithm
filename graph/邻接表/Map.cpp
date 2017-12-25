/*************************************************************************
	> File Name: Map.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月08日 星期五 12时55分05秒
 ************************************************************************/

#include<iostream>
#include"Map.h"
using namespace std;
Map::Map() //构造函数
{
    vertexNode = new vertex[MAXNODESIZE]; //顶点数组
    vertexCount = 0 ;
    arcCount = 0;
}
Map::~Map() 
{
    delete []vertexNode;
}
bool Map::addVertexToVertexNode(char ch) //加入点
{
    vertexNode[vertexCount].vertexData  =  ch ;
    vertexNode[vertexCount].head = NULL  ;
    vertexCount++ ;
    return true ;
}

bool Map::setArc(char Node,int index,int weight)//加边
{
    Edge *p = NULL ;
    for(int i=0;i< MAXNODESIZE;++i){
        if(vertexNode[i].vertexData == Node){
            p=vertexNode[i].head  ;

        }
    }
}

