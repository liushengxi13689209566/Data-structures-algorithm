/*************************************************************************
	> File Name: 图的存储与遍历.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月27日 星期一 20时24分48秒
 ************************************************************************/

#include<iostream>
#include"Map.h"
using namespace std;
/*图的存储用邻接矩阵实现，
* 遍历有两种 DFS与BFS */
int main(void)
{
    Map map(15);
    map.addNode('A');
    map.addNode('B');
    map.addNode('C');
    map.addNode('D');
    map.addNode('E');
    map.addNode('F');
    map.addNode('G');
    map.addNode('H');

    /*map.setValToUndirectedGraph(0,1);
    map.setValToUndirectedGraph(0,4);
    map.setValToUndirectedGraph(1,0);
    map.setValToUndirectedGraph(1,4);
    map.setValToUndirectedGraph(1,5);
    map.setValToUndirectedGraph(2,3);
    map.setValToUndirectedGraph(2,5);
    map.setValToUndirectedGraph(3,2);
    map.setValToUndirectedGraph(3,5);
    map.setValToUndirectedGraph(4,0);
    map.setValToUndirectedGraph(4,1);
    map.setValToUndirectedGraph(5,1);
    map.setValToUndirectedGraph(5,2);
    map.setValToUndirectedGraph(5,3);*/

    map.setValToUndirectedGraph(0,1);
    map.setValToUndirectedGraph(0,3);
    map.setValToUndirectedGraph(1,2);
    map.setValToUndirectedGraph(1,5);
    map.setValToUndirectedGraph(3,6);
    map.setValToUndirectedGraph(3,7);
    map.setValToUndirectedGraph(6,7);
    map.setValToUndirectedGraph(2,4);
    map.setValToUndirectedGraph(4,5);
    map.printMartrix();
    map.printNode();

    map.resetNode();
    map.DFS(0);
    cout << endl ;

    map.resetNode();
    map.BFS(0);

    return 0;
}


