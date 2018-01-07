/*************************************************************************
	> File Name: myhead.h
	> Author: 
	> Mail: 
	> Created Time: 2018年01月02日 星期二 13时15分42秒
 ************************************************************************/

#ifndef _MYHEAD_H
#define _MYHEAD_H
#include<vector>
#include<unistd.h>
#include<stdlib.h>
#include<mysql/mysql.h>
#include<iostream>
#include<queue>
#include<string.h>

#define END          "\e[0m"
#define RED           "\e[1;31m"
#define GREEN       "\e[1;32m"
#define YELLOW      "\e[1;33m"
#define BLUE         "\e[1;34m"
#define PURPLE     "\e[1;35m"

#define HOST    "localhost"
#define USER    "root"
#define DB_NAME  "Graph"      // 以 root  的身份登录
#define	PASSWD    "thq520&iwwfyf"

#define  MAXSIZE  52  // 最大顶点数 
#define  MAXMAX       65535


class Graph ;
class Node{
    public:
    Node() = default ;
    //~Node() ;
    private:
    int CityNumbers = 0; //城市编号
    std::string CityName ; //名称
    std::string QueryUrl ; //信息查询网址
    bool visted  = false ;  // 为了遍历的时候，判断是否能够访问 

    friend Graph ;

};
class Graph{
public:
 /*********************************构造与析构*****************************/
    Graph()  ;
    //Graph() ;
    ~Graph() ;
/****************************关于图的一些函数********************/
    int GraphMenu() ;
    int create() ;   //从文件读入信息从而创建图
/********************************用户**********************************/
 
    int GraphUser() ;
    int GraphUserListInfo() ;// 查 询 基 本 信 息
    int GraphUserQueryCity() ; //查 询 某 城 市 基 本 情 况
    int GraphUserQueryRoute() ; //查 询 两 地 之 间 的 线 路  

/*****************************************管理员****************************************/
    int GraphRoot() ;


/*****************************************私有成员****************************************/
private:
    int  arcs_distance[MAXSIZE][MAXSIZE] = { 0 } ; //代表有弧相连和权值（即公里数，票价，时间等。。。）
    float arcs_fare[MAXSIZE][MAXSIZE] =  { 0.0 };   //如果用户选择了其中某一个进行查询（设置标志位）
    int arcs_time[MAXSIZE][MAXSIZE] = { 0 } ; //数据是必然要存储的
    Node vex[MAXSIZE] ;  //地点集合
    int vexnum = 0 ;
    int arcsnum = 0 ;
    MYSQL *mysql ; //MYSQL 句柄
    int  SmallPath[MAXSIZE][MAXSIZE] ={0};   //解决中转次数最少的问题
    int k = 0 ;
    int nodes[1000] ; 
    int tag = 0 ; //来标记用哪个权值计算最短路径
/*****************************************私有成员函数****************************************/

    void mysql_connect(MYSQL *mysql) ;
    void close_connection(MYSQL *mysql) ;
    int  GraphUserListCityTraffic();
    int  GraphUserQueryCityInformation() ;
    int  getCityIndex(std::string  ) ;
   
    void ddffss(int index_A, int index_B, int depth = 1 ) ;
    int  printRoute(int index_A ,int index_B ) ;
    int  printRouteByCount(int ,int )  ;
    int  deleteACity() ;
    int  undoRoad();
    int  AddCity() ;  //增 加 一 个  地 点
    void Prim(int nodeIndex)  ;
    int  SetNet()  ;
    void getPath(int i ,int j,int path[][MAXSIZE]) ;
    int  printRouteBydistance(int index_A,int index_B) ;
    void Floyd(int F[][MAXSIZE],int index_A,int index_B) ;
    void printgraph() ;
    void Dijkstra(int begin,int end);
 

  


};
/*****************************************模板函数****************************************/
//模板函数：将string类型变量转换为常用的数值类型（此方法具有普遍适用性）  
template <class Type>  
Type stringToNum(const std::string& str){  
    std::istringstream iss(str);  
    Type num;  
    iss >> num;  
    return num;      
}  

#endif
