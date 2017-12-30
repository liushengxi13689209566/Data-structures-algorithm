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
bool Map::addVertexToVertexNode(char ch) //加入点 ,正确的
{
    vertexNode[vertexCount].vertexData  =  ch ;
    vertexNode[vertexCount].head = NULL  ;
    vertexCount++ ;
    return true ;
}

bool Map::setArc(char start,char end,int weight)//加边,从那到那,无向图
{
    int startIndex ,endIndex ; //找到起始点与结束点下标
    for(int i=0; i < vertexCount ; ++i) {
        if(vertexNode[i].vertexData == start )
            startIndex = i ;
        if(vertexNode[i].vertexData == end  )
            endIndex = i ;
    }
    printf("start == %c end == %c startIndex ==%d endIndex == %d \n",start,end,startIndex,endIndex);
    //头插法更简单
    Edge *temp =  new Edge ;
    temp->Nodeindex = endIndex ;
    temp->weight = weight ;
    temp->next = vertexNode[startIndex].head  ;
    vertexNode[startIndex].head = temp ;

    
    Edge *temp_1 =  new Edge ;
    temp_1->Nodeindex = startIndex ;
    temp_1->weight = weight ;
    temp_1->next = vertexNode[endIndex].head ;
    vertexNode[endIndex].head = temp_1 ;
}
void Map::print()
{
    for(int i=0;i != vertexCount;++i)
    {
        printf("      vertexNode[%d]    == %c  \n",i,vertexNode[i].vertexData);
        for(Edge *p=vertexNode[i].head ; p != NULL ;p=p->next)
            printf("Nodeindex == %d  weight == %d \n",p->Nodeindex,p->weight);
    }
    printf("\n\n\n\n 顶点数为 ： vertexCount == %d \n",this->vertexCount);
}

