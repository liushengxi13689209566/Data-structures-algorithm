/*************************************************************************
	> File Name: Map.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月27日 星期一 20时45分32秒
 ************************************************************************/
#include"Map.h"
#include<vector>
using namespace std;
Node::Node(char data)  //点的构造函数
{
    m_cData = data ;
    visted =  false ;
}
Map::Map(int MAX)   //图的构造函数
{
    MaxVertexCount = MAX ;
    AlreadyInCount = 0;
    pNodeArray = new Node[MaxVertexCount];   //用来存放顶点
    pMartrix = new int[MaxVertexCount*MaxVertexCount]; //存放边的关系,一维当二维用
    memset(pNodeArray,0,MaxVertexCount*sizeof(Node));
    memset(pMartrix,0,MaxVertexCount*MaxVertexCount*sizeof(int));
    pEdge = new Edge[MaxVertexCount-1]; //申请一个边的集合
}
Map::~Map()  //图的析构函数
{
    delete []pNodeArray;
    delete []pMartrix;
}
bool Map::addNode(char ch) //添加顶点
{
    pNodeArray[AlreadyInCount].m_cData = ch ;
    AlreadyInCount++;
    return true;
}

void Map::resetNode() //重置顶点
{
    for(int i=0;i != MaxVertexCount ;++i)
        pNodeArray[i].visted = false ; 
}

bool Map::setValToDirectedGraph(int row,int col,int val) //设置有向图
{
   pMartrix[row*MaxVertexCount+col] =  val ; //因为把一维数组当二位数组来用了，所以是这种形式
    return true;
}
bool Map::setValToUndirectedGraph(int row,int col,int val) //设置无向图，就是对称矩阵嘛
{
    pMartrix[row*MaxVertexCount+col] =  val ;
    pMartrix[col*MaxVertexCount+row] =  val ;
    return true;
}
void Map::printMartrix() //打印矩阵
{
    for(int i=0;i != AlreadyInCount ;++i)
    {
        for(int j =0;j != AlreadyInCount ;++j)
            cout << pMartrix[i*MaxVertexCount+j] <<   "  ";
        cout << endl ;
    }
}
void Map::printNode() //打印顶点
{
    for(int i=0;i != AlreadyInCount ;++i)
        cout << pNodeArray[i].m_cData   << "  "  << pNodeArray[i].visted   << endl ;
    cout << endl ;
}
void Map::RealBFS(vector<int> TempVec)
{
    vector<int> CurVec ;
    for(auto i= 0 ; i != TempVec.size() ; ++i )
    {
        for(int j= 0 ;j != AlreadyInCount ;++j)
        {
            if(pMartrix[TempVec[i]*MaxVertexCount+j] != 0 && pNodeArray[j].visted == false )
            {
                cout << pNodeArray[j].m_cData << "  " ;
                pNodeArray[j].visted = true ;
                CurVec.push_back(j);
            }
        }
    }
    if(CurVec.size() != 0 )
        RealBFS(CurVec);
}
void Map::BFS(int NodeIndex)  
{
    cout <<  pNodeArray[NodeIndex].m_cData  << "  ";
    pNodeArray[NodeIndex].visted = true ;
    vector<int> vec1 ;
    vec1.push_back(NodeIndex);
    RealBFS(vec1);
}

Edge::Edge(int A  ,int B ,int w ) //边
{
    indexA = A;
    indexB = B;
    weight = w;
    selected = false ;
}
bool  Map::getValueFromMartix(int row,int col,int &val)
{
    val = pMartrix[row*MaxVertexCount+col];
    return true ;
}
void Map::primTree(int nodeIndex)
{
    cout << "pNodeArray[nodeIndex].m_cData == " << pNodeArray[nodeIndex].m_cData << endl ;
    int value = 0 ;
    int edgeCount = 0 ;
    vector<int> nodeVec ;
    vector<Edge> edgeVec ;

    nodeVec.push_back(nodeIndex);
    pNodeArray[nodeIndex].visted = true;

    while(edgeCount < MaxVertexCount- 1 )
    {
        int temp = nodeVec.back();   //再取出来
        for(int i = 0;i< MaxVertexCount ; ++i){
            getValueFromMartix(temp,i,value);
            if(value != 0)
            {
                if(pNodeArray[i].visted  != true)
                {
                    Edge edge(temp,i,value);
                    edgeVec.push_back(edge);  //备选边,
                    //为什么不会重复放入呐？二维矩阵只是一个关系图，需要什么去查看就行了，
                    //真正表示边有没有被访问的是Edge 这个对象
                }
            }
        }
        //从可选边的集合中找到最小的边
        int edgeIndex= getMinEdge(edgeVec); //返回另一条（对面）边的索引
        edgeVec[edgeIndex].selected = true ;

    cout << " edgeVec[edgeIndex].indexA,B == " << edgeVec[edgeIndex].indexA << "," << edgeVec[edgeIndex].indexB  << endl ;
    cout << "edgeVec[edgeIndex].weight == " << edgeVec[edgeIndex].weight << endl ;
   cout << endl << endl ;

        pEdge[edgeCount] = edgeVec[edgeIndex];
        edgeCount++ ;
        int NextNodeIndex = edgeVec[edgeIndex].indexB ;
        nodeVec.push_back(NextNodeIndex);
        pNodeArray[NextNodeIndex].visted = true ;
        cout << "pNodeArrayp[NextNodeIndex].m_cdata == " << pNodeArray[NextNodeIndex].m_cData << endl ;
    }
}
int Map::getMinEdge(vector<Edge>  edgeVec)
{
    int minWeight = 0;
    int edgeIndex = 0 ;
    int i = 0 ;
    for(i=0;i< edgeVec.size();++i )
    {
        if( !edgeVec[i].selected )
        {
            minWeight= edgeVec[i].weight ;
            edgeIndex = i ; 
            break ;
        }
    }
    if(minWeight  ==  0)
    {
        return -1 ;
    }
    for(;i< edgeVec.size();++i)
    {
        if( !edgeVec[i].selected )
        {
            if(minWeight > edgeVec[i].weight)
            {
                minWeight = edgeVec[i].weight;
                edgeIndex= i ;
            }
        }
    }
    return edgeIndex ;
}
