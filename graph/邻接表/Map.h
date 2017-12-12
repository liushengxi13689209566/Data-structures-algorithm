/*************************************************************************
	> File Name: Map.h
	> Author: 
	> Mail: 
	> Created Time: 2017年12月08日 星期五 12时24分47秒
 ************************************************************************/

#ifndef _MAP_H
#define _MAP_H
class vertex{  //顶点
    public:
    vertex(char ch= 0 );

    char vertexData ; //顶点数据
    bool visted ;  //顶点是否被访问
    Edge *head ;  //连接边
};
class Edge{   //边
    public:
    Edge();
    private:
    int Nodeindex ; //下一条边所链接的顶点的下标
    int weight;     //权重
    Edge *next ;    //链表指针
};

class Map{    //图
    public:
    Map(int temp);
    ~Map();
    bool addVertexToVertexNode(char ch) ;
    bool setArc(char Node,int index,int weight);//加入边
    void print();

    private：
    int MAXNODESIZE ; //最大顶点数
    vertex *vertexNode; //顶点数组
    int vertexCount ; //顶点个数
    int arcCount ;  //边的个数
};

#endif
