/*************************************************************************
	> File Name: 邻接表.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月08日 星期五 12时23分55秒
 ************************************************************************/

#include<iostream>
#include"Map.h"
using namespace std;
int main(void)
{
    Map graph ;
    graph.addVertexToVertexNode('A');
    graph.addVertexToVertexNode('B');
    graph.addVertexToVertexNode('C');
    graph.addVertexToVertexNode('D');
    graph.setArc('A','B',10);
    graph.setArc('C','B',3);
    graph.setArc('A','C',5);
    graph.setArc('A','D',2);
    graph.print();
}
