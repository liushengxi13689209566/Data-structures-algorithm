/*************************************************************************
	> File Name: 函数实现.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月02日 星期二 13时16分08秒
 ************************************************************************/

#include<iostream>
#include"myhead.h"
using namespace std;
/*
private:
    TT  arcs_distance[MAXSIZE][MAXSIZE] = { 0 } ; //代表有弧相连和权值（即公里数，票价，时间等。。。）
    float arcs_fare[MAXSIZE][MAXSIZE] =  { 0.0 };   //如果用户选择了其中某一个进行查询（设置标志位）
    TT arcs_time[MAXSIZE][MAXSIZE] = { 0 } ; //数据是必然要存储的
    Node vex[MAXSIZE] ;  //地点集合
    TT vexnum = 0 ;
    TT arcsnum = 0 ;
    MYSQL *mysql ;
*/
/*****************************************构造与析构******************************************/
Graph::Graph()
{
    for(int i = 0 ; i < MAXSIZE ;++i)
    {
        for(int j= 0;j< MAXSIZE ;++j)
        {
            arcs_distance[i][j] = MAXMAX ;
            arcs_fare[i][j] = MAXMAX ;
            arcs_time[i][j] = MAXMAX ;
        }
    }
    vexnum = 0 ;
    arcsnum = 0 ;
}

Graph::~Graph()
{
}
/*************************************数据库操作函数**************************************/
void Graph::mysql_connect(MYSQL *mysql)
{  
    if(  !(mysql=mysql_real_connect(mysql, HOST, USER, PASSWD, DB_NAME, 0, NULL, 0) ) ) {  
             cout << "数 据 库 连 接 出 错   " << endl  ;
    mysql_query(mysql,"set names gbk");     //防止乱码。设置和数据库的编码一致就不会乱码
    }  
}  
void Graph::close_connection(MYSQL *mysql)
{
    mysql_close(mysql);
}


/*************************************关于图的一些函数**************************************/
int Graph::create()     //读入信息从而创建图
{
    ifstream fcin("input.txt",ios::in) ;
    fcin >>  vexnum  >> arcsnum ;
     printf("vexnum == %d \n",vexnum );
     printf("arcsnum == %d \n",arcsnum);

    mysql = mysql_init(NULL);   //打开数据库
    if(!mysql)   cout << "数据库初始化出错  " << endl ;
    mysql_connect(mysql) ;
    
    string query1 ;
    string query2 ;


    // for(int i = 0 ;i < vexnum ;++i)    //读取各个城市信息 11
    // {
    //     fcin >> this->vex[i].CityName  >> this->vex[i].QueryUrl  ;//读入信息
    //     this->vex[i].CityNumbers = i+1 ;

    // cout << this->vex[i].CityNumbers << endl ;
    // cout << this->vex[i].CityName << endl ;
    // cout << this->vex[i].QueryUrl << endl ;
    // }

    // TT index_A ,index_B ,distance , minutes ;
    // float money ;

    // for(int  i = 0 ;i < arcsnum  ; ++i  )       //读取边的信息 15
    // {
    //     fcin >> index_A >> index_B  >> distance   ; 
    //     this->arcs_distance[index_A][index_B] = distance ;
    //     this->arcs_distance[index_B][index_A] = distance ;
    //     fcin >> money ;
    //     this->arcs_fare[index_A][index_B] = money ;
    //     this->arcs_fare[index_B][index_A] = money ;
    //     fcin >> minutes ;
    //     this->arcs_time[index_A][index_B] = minutes ;
    //     this->arcs_time[index_B][index_A] = minutes ;
    // }
    // // printf("arc_distance[%d][]\n");
    // // for(int i= 0;i < vexnum ;++i)
    // // {
    // //     for(int j= 0 ;j< vexnum ;++j)
    // //     {
    // //         // if(arcs_distance[i][j] == MAXMAX )
    // //         //     cout << "    " ;
    // //         // else 
    // //         printf("%7d",arcs_distance[i][j]);
    // //             //cout << arcs_distance[i][j]    << "      " ;
    // //     }
    // //     cout << endl ;
    // // }
    // fcin.close();
     close_connection(mysql);
    return 0;
}


/**********************************************用户****************************************/
int  Graph::GraphMenu()
{

    int choice ;
    do
    {
        //printf("\033c");

        printf(GREEN"\n\n\n\n\n\n\n\n\t\t\t\t\t\t欢 迎 来 到 为 你 精 心 打 造 的 飞 车 系 统 \n\n\n"END);
        printf(YELLOW"\t\t\t\t\t\t\t    0.   用  户  登   录  \n\n"END);
        printf(BLUE  "\t\t\t\t\t\t\t    1.管  理  员   登   录\n\n"END);        //登录完成再进行各种处理
        printf(RED   "\t\t\t\t\t\t\t    2.   取       消\n\n" END);
        printf(      "\t\t\t\t\t\t\t    请输入你的选择：");
        cin >> choice ;
        switch(choice)
        {
            case 0:  GraphUser();  break ;
            case 1:  GraphRoot();   break ;
            case 2:           break ;
            default :printf(RED"\n\n\t\t\t\t\t\t\t输入有错～～～,请检查后重新输入!!!\n"END); sleep(1) ;  break ;
        }
    }while(choice !=  2 );     //取消
    return 0 ;
}
int Graph::GraphUser()
{
    int choice ;
    do
    {
        //printf("\033c");

        printf(GREEN"\n\n\n\n\n\n\n\n\t\t\t\t\t\t欢 迎 来 到 城 市 飞 车 信 息 查 询 系 统 \n\n\n"END);
        printf(YELLOW"\t\t\t\t\t\t\t    0.查 询 基 本 信 息   \n\n"END);
        printf(BLUE  "\t\t\t\t\t\t\t    1.查 询 某 城 市 基 本 情 况\n\n"END);  
        printf(YELLOW"\t\t\t\t\t\t\t    2.查 询 两 地 之 间 的 线 路   \n\n"END);
        printf(RED   "\t\t\t\t\t\t\t    3.      取   消\n\n" END);
        printf(      "\t\t\t\t\t\t\t    请输入你的选择：");
        cin >> choice ;
        switch(choice)
        {
            case 0:  /*GraphUserListInfo(); */ break ;
            case 1:  GraphUserQueryCity();   break ;
            case 2:  GraphUserQueryRoute() ;  break ;
            case 3:  break ;
            default :printf(RED"\n\n\t\t\t\t\t\t\t输入有错～～～,请检查后重新输入!!!\n"END); sleep(1) ;  break ;
        }
    }while(choice != 3 );
    return 0;
}
/*int Graph::GraphUserListInfo() // 查 询 基 本 信 息
{

    
}*/
int Graph::GraphUserQueryCity()  //查 询 某 城 市 基 本 情 况
{
    int choice ;
    do
    {
        //printf("\033c");

        printf(YELLOW"\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t    0.交 通 情 况  查 询   \n\n"END);
        printf(BLUE  "\t\t\t\t\t\t\t    1.城 市 信 息 查 询 \n\n"END);  
        printf(RED   "\t\t\t\t\t\t\t    2.      取   消\n\n" END);
        printf(      "\t\t\t\t\t\t\t    请输入你的选择：");
        cin >> choice ;
        switch(choice)
        {
            case 0:  /*GraphUserListCityTraffic();  */   break ;
            case 1:  /*GraphUserQueryCityInformation(); */  break ;
            case 2:   break ;
            default :printf(RED"\n\n\t\t\t\t\t\t\t输入有错～～～,请检查后重新输入!!!\n"END); sleep(1) ;  break ;
        }
    }while(choice != 2);
}
int Graph::GraphUserQueryRoute()  //查 询 两 地 之 间 的 线 路  
{
    string start ,end ;
    printf(YELLOW"\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t    请 输 入 起 点 ：   \n\n"END);
    cin >> start ;
    printf(BLUE  "\t\t\t\t\t\t\t    请 输 入 终 点 ：   \n\n"END); 
    cin >> end ;
    //printRoute();   // /dfs/bfs 查询  
    //sleep(8)
    int choice ;
    do
    {
        //printf("\033c");

        printf(YELLOW"\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t    0.按 中 转 次 数 排 序   \n\n"END);
        printf(BLUE  "\t\t\t\t\t\t\t    1.按 距 离 排 序  \n\n"END);  
        printf(RED   "\t\t\t\t\t\t\t    2.按  money  排   序\n\n" END);
        printf(BLUE  "\t\t\t\t\t\t\t    3.按 时 间 排 序  \n\n"END); 
        printf(RED   "\t\t\t\t\t\t\t    4.      取   消\n\n" END);
        printf(      "\t\t\t\t\t\t\t    请输入你的选择：");
        cin >> choice ;
        switch(choice)
        {
            case 0:  /*printRouteByCount();*/     break ;
            case 1:  /*printRouteBydistance();  */ break ;
            case 2:  /*printRouteByMoney() ;*/break ;
            case 3:  /*printRouteByTime() ;  */break;
            case 4:  break;
            default :printf(RED"\n\n\t\t\t\t\t\t\t输入有错～～～,请检查后重新输入!!!\n"END); sleep(1) ;  break ;
        }
    }while(choice != 4);
    return 0;
}

/*****************************************管理员****************************************/
int Graph::GraphRoot()
{

}
