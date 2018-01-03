/*************************************************************************
	> File Name: Map.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月27日 星期一 20时45分32秒
 ************************************************************************/

#include"Map.h"
#include<vector>
using namespace std;

Node::Node(char data)  //构造函数
{
    m_cData = data ;
    visted =  false ;
}
Map::Map(int MAX)   //构造函数
{
    MaxVertexCount = MAX ;
    AlreadyInCount = 0;
    pNodeArray = new Node[MaxVertexCount];   //用来存放顶点
    pMartrix = new int[MaxVertexCount*MaxVertexCount]; //存放边,以为当二维用
    memset(pNodeArray,0,MaxVertexCount*sizeof(Node));
    memset(pMartrix,0,MaxVertexCount*MaxVertexCount*sizeof(int));
}
Map::~Map()  //析构函数
{
    delete []pNodeArray;
    delete []pMartrix;
}
bool Map::addNode(char ch)
{
    pNodeArray[AlreadyInCount].m_cData = ch ;
    AlreadyInCount++;
    return true;
}
void Map::resetNode()
{
    for(int i=0;i != MaxVertexCount ;++i)
        pNodeArray[i].visted = false ; 
}
bool Map::setValToDirectedGraph(int row,int col,int val)
{
   pMartrix[row*MaxVertexCount+col] =  val ; //因为人家把一维数组当二位数组来用了，所以是这种形式
    return true;
    
}
bool Map::setValToUndirectedGraph(int row,int col,int val)
{
    pMartrix[row*MaxVertexCount+col] =  val ;
    pMartrix[col*MaxVertexCount+row] =  val ;
    return true;
}
void Map::printMartrix()
{
    for(int i=0;i != AlreadyInCount ;++i)
    {
        for(int j =0;j != AlreadyInCount ;++j)
            cout << pMartrix[i*MaxVertexCount+j] <<   "  ";
        cout << endl ;
    }
}

void Map::printNode()
{
    for(int i=0;i != AlreadyInCount ;++i)
        cout << pNodeArray[i].m_cData   << "  "  << pNodeArray[i].visted   << endl ;
    cout << endl ;
}

//static int nodes[1000][1000] ;
/*void Map::init()
{
    for(int i = 0 ;i < 1000 ;i++)
    {
        for(int j = 0 ;j< 1000 ;j++)
            nodes[i][j] = -10 ;
    }
}*/
void Map::ddffss(int ima, int edo, int depth)
{


    static int nodes[1000]  ;
    nodes[depth] =  ima ;
    pNodeArray[ima].visted = true ;

    if (ima == edo )
    {
        for (int i = 1; i <= depth; i++)
        {
            cout << nodes[i] ;


        }
        cout << endl;
        return;
    }

    for (int i = 0; i < AlreadyInCount; i++)
    {
        if (pMartrix[MaxVertexCount * ima + i] != 0) 
        {
            if (pNodeArray[i].visted == false)
            {
                pNodeArray[i].visted = true;
                ddffss(i, edo, depth + 1);
                pNodeArray[i].visted = false;
            }
        }
    }
}
/*void Map::print()
{
    for(int i = 0 ;i < 1000 ;i++)
    {
        for(int j = 0 ;j< 1000 ;j++)
            printf("nodes[%d][%d] == %d ",nodes[i][j]);
        cout << endl ;
    }
}*/
/*void Map::DFS(int NodeIndex,int index_B)
{
    cout << pNodeArray[NodeIndex].m_cData   << " " ;
    // VecString.push_back( pNodeArray[NodeIndex].m_cData  )  ;

    if(NodeIndex == index_B )  
    {
        // for(auto i: VecString )
        //     cout << i << "  "  ;
         cout << endl ;
        // VecString.pop_back() ;
        return  ;
    }

    pNodeArray[NodeIndex].visted = true ;

    for(int i = 0;i != AlreadyInCount ;++i)
    {
        //if(pMartrix[i] ==  1 && pNodeArray[i].visted ==  false )
          //  DFS_next(i);
          if(pMartrix[MaxVertexCount*NodeIndex+i] != 0)
          {
              if(pNodeArray[i].visted == false )
                  DFS(i,index_B ) ;
          }
    }
}*/

void Map::RealBFS(vector<int> &TempVec)
{
    vector<int> CurVec ;
    //cout << "TempVec.size == " << TempVec.size() <<  endl ;
    for(auto i= 0 ; i != TempVec.size() ; ++i )
    {
       // cout << "遍历 Temp  vector ："  << TempVec[i] << endl ;
        for(int j= 0 ;j != AlreadyInCount ;++j)
        {
            //cout << "pMartrix[i*MaxVertexCount+j] == " <<  pMartrix[i*MaxVertexCount+j] << endl ;
            if(pMartrix[TempVec[i]*MaxVertexCount+j] == 1 && pNodeArray[j].visted == false )
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
void Map::BFS(int NodeIndex)  // NodeIndex = 0 
{
    cout <<  pNodeArray[NodeIndex].m_cData  << "  ";
    pNodeArray[NodeIndex].visted = true ;

    vector<int> vec1 ;
    vec1.push_back(NodeIndex);

    RealBFS(vec1);
}


