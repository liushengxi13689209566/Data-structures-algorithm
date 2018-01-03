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
    for(int i= 0;i< MAXMAX ;++i)
    {
        for(int j = 0 ;j < MAXMAX ;++j)
            SmallPath[i][j]= MAXMAX ;
    }
    k = 0 ;
    for(int i= 0 ;i< 1000 ;i++)
        nodes[i] = MAXMAX ;

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
     int index ,index_A ,index_B  ;
    fcin >>  vexnum  >> arcsnum ;
     printf("vexnum == %d \n",vexnum );
     printf("arcsnum == %d \n",arcsnum);
    fcin.close() ;

    MYSQL_RES *res ;
    MYSQL_ROW row ;

    mysql = mysql_init(NULL);   //打开数据库
    if(!mysql)   cout << "数据库初始化出错  " << endl ;
    mysql_connect(mysql) ;

    string query1  = "select  *   from  City " ;
    int t =  mysql_real_query(mysql ,query1.c_str(),query1.size());
    if(t != 0 )    cout << "server mysql_real_query" << endl ;
    res = mysql_store_result(mysql) ;
    if( !res )     cout << "server mysql_real_query" << endl ;

    int a = mysql_num_rows(res) ;
    printf("a== %d \n",a);

    for(int i =  0 ;i < a ;++i)
    {
        row = mysql_fetch_row(res);
        cout << "--------" << row[0] << endl ;
        index = atoi(row[0]) - 1 ;
        cout << "index == " << index << endl ;
        this->vex[index].CityNumbers  = atoi(row[0]);
        this->vex[index].CityName =  row[1];
        this->vex[index].QueryUrl  = row[2];

        cout << vex[i].CityNumbers << " "<< vex[i].CityName << "  "<< vex[i].QueryUrl << endl ;
    }
    
    string query2  = "select  *   from  Edge  " ;
    t =  mysql_real_query(mysql ,query2.c_str(),query2.size());
    if(t != 0 )    cout << "server mysql_real_query" << endl ;
    res = mysql_store_result(mysql) ;
    if( !res )     cout << "server mysql_real_query" << endl ;
    a = mysql_num_rows(res) ;
     printf("a== %d \n",a);
    for(int i = 0 ;i< a ;++i)
    {
        row = mysql_fetch_row(res);
        index_A  =  atoi(row[1]) ;
        index_B = atoi(row[2]);
        this->arcs_distance[index_A][index_B] = atoi(row[3]);
        this->arcs_distance[index_B][index_A] = atoi(row[3]);

        this->arcs_fare[index_A][index_B] = atof(row[4]);
        this->arcs_fare[index_B][index_A] = atof(row[4]);

        this->arcs_time[index_A][index_B] = atoi(row[5]);
        this->arcs_time[index_B][index_A] = atoi(row[5]);
    }
   
    printf("arc_distance[%d][]\n");
    for(int i= 0;i < vexnum ;++i)
    {
        for(int j= 0 ;j< vexnum ;++j)
        {
            
            printf("%7d",arcs_distance[i][j]);

        }
        cout << endl ;
    }
    for(int i= 0;i < vexnum ;++i)
    {
        cout << vex[i].CityNumbers << vex[i].CityName << vex[i].QueryUrl << endl ;
    }

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
            case 0:  GraphUserListInfo();  break ;
            case 1:  GraphUserQueryCity();   break ;
            case 2:  GraphUserQueryRoute() ;  break ;
            case 3:  break ;
            default :printf(RED"\n\n\t\t\t\t\t\t\t输入有错～～～,请检查后重新输入!!!\n"END); sleep(1) ;  break ;
        }
    }while(choice != 3 );
    return 0;
}
int Graph::GraphUserListInfo()  // 查 询 基 本 信 息,GraphUser case 0 :
{
    printf(GREEN"\n\n\n\n\n\n\t\t\t\t\t\t城 市 基 本 信 息  为 ：\n\n\n"END);
    printf(YELLOW"\t\t\t\t\t\t\t 城市<------>城市 ： 距离   费用   耗费时间   \n\n"END);
    for(int i= 0 ;i< vexnum ;++i)
    {
        for(int j = 0 ;j <  i  ;++j)  //无向图，查一半
        {
            if(arcs_distance[i][j] != MAXMAX )
            {
                cout << vex[i].CityName   << "<------>" <<  vex[j].CityName 
                << "  ： " << arcs_distance[i][j] <<  "  "
                << arcs_fare[i][j]  << "  "
                << arcs_time[i][j]  << endl  ;   
            }
        }
    }
} 
int Graph::GraphUserQueryCity()  //查 询 某 城 市 基 本 情 况, GraphUser case 1 :
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
            case 0:   GraphUserListCityTraffic();     break ;
            case 1:   GraphUserQueryCityInformation();  break ;
            case 2:   break ;
            default :printf(RED"\n\n\t\t\t\t\t\t\t输入有错～～～,请检查后重新输入!!!\n"END); sleep(1) ;  break ;
        }
    }while(choice != 2);
}

int  Graph::getCityIndex(string name) // 得到某一个城市的下标
{
    for(int i= 0 ;i< vexnum ; ++i)
    {
        if(vex[i].CityName  == name) 
        return i ;
    }
}


int Graph::GraphUserListCityTraffic()//某城市交通情况查询,GraphUser:::GraphUserQueryCity case 0 :
{
    string name ;
    printf(YELLOW"\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t    请 输 入 城 市 名 称  ：   \n\n"END);
    cin >> name  ;
    int  index = getCityIndex(name) ;

    printf(GREEN"\n\n\n\n\n\n\t\t\t\t\t\t城 市 交 通 情 况 为 ：\n\n\n"END);
    printf(YELLOW"\t\t\t\t\t\t\t 城市<------>城市 ： 距离   费用   耗费时间   \n\n"END);

    for(int i= 0 ;i< vexnum ;++i)
    {
        if(i == index )
        {
            for(int j=0 ;j< vexnum ;++j)
            {
                if(arcs_distance[i][j] != MAXMAX )
                {
                    cout << vex[index].CityName   << "<------>"  << vex[j].CityName 
                    << "  ： " << arcs_distance[i][j] <<  "  "   //有疑问，感觉应该是arcs[index][j];
                    << arcs_fare[i][j]  << "  "
                    << arcs_time[i][j]  << endl  ;   
                }
            }
        }
    }
    return 0 ;
}

int Graph::GraphUserQueryCityInformation()  //某城 市 信 息 查 询,GraphUser:::GraphUserQueryCity case 1 :
{
    string name ;
    printf(YELLOW"\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t    请 输 入 城 市 名 称  ：   \n\n"END);
    cin >> name  ;       // 需要检查是否输入正确哦，后面再处理 ～～
    int  index = getCityIndex(name) ;
    pid_t  pid_love ;
    int status_love ;
    pid_love = fork();  //第一次fork 进程
    name = "/opt/google/chrome/google-chrome   " + vex[index].QueryUrl   ;   //google-chrome www.baidu.com 
    switch(pid_love)
    {
        case -1:   printf("fork pid_love  ERROR !!!\n") ;return 0;
        case 0 :   system(name.c_str());
        default:  break ;   //父进程再不管子进程了
    }
}

int Graph::GraphUserQueryRoute() //查 询 两 地 之 间 的 线 路  
{
    string start ,end ;
    printf(YELLOW"\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t    请 输 入 起 点 ：   \n\n"END);
    cin >> start ;
    printf(BLUE  "\t\t\t\t\t\t\t    请 输 入 终 点 ：   \n\n"END); 
    cin >> end ;

    int index_A,index_B ;
    index_A = getCityIndex(start);
    index_B = getCityIndex(end);
    cout <<"0.**********************************************k   ==   "   <<  k   <<    endl  ;
    int choice ;
    do
    {
        //printf("\033c");
        printf(YELLOW"\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t    0.中 转 次 数 最 少   \n\n"END); //一旦要选择排序就意味着
                                                                                        //必须要进行存储
        printf(BLUE  "\t\t\t\t\t\t\t    1.距 离 最 优  \n\n"END);  
        printf(RED   "\t\t\t\t\t\t\t    2.money  最 少 \n\n" END);
        printf(BLUE  "\t\t\t\t\t\t\t    3.时 间 最  短   \n\n"END); 
        printf(BLUE  "\t\t\t\t\t\t\t    4.查 看 所 有 路 线  \n\n"END);  
        printf(RED   "\t\t\t\t\t\t\t    5.      取   消\n\n" END);
        printf(      "\t\t\t\t\t\t\t    请输入你的选择 ：" );
        cin >> choice ;
        switch(choice)
        {
            case 0:  printRouteByCount(index_A,index_B);     break ;
            case 1:  /*printRouteBydistance();  */ break ;
            case 2:  /*printRouteByMoney() ;*/break ;
            case 3:  /*printRouteByTime() ;  */break;
            case 4:  printRoute(index_A,index_B);  break;
            case 5: break ;
            default :printf(RED"\n\n\t\t\t\t\t\t\t输入有错～～～,请检查后重新输入!!!\n"END); sleep(1) ;  break ;
        }
    }while(choice != 5) ;
    return 0;
}



int Graph::printRouteByCount(int index_A ,int index_B)  //集中精力处理SmallPath 
{
    int count  =  0 ;
    k = 0 ;
    cout << " #########################################" << endl ;
    cout <<"1.**********************************************k   ==   "   <<  k   <<    endl  ;


    ddffss(index_A,index_B,1) ;

    cout <<"2.**********************************************k   ==   "   <<  k   <<    endl  ;


    for(int i= 0;i< k  ;++i)
    {
        for(int j = 0 ;j < k ;++j)
            cout << SmallPath[i][j]  <<  " " ;
            cout << endl ;
    }

    cout << " @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl ;
    for(int i= 0;i< MAXMAX ;++i)
    {
        count  = 0  ;
        for(int j = 1 ; j < MAXMAX ;++j)
        {
            if(SmallPath[i][j] != MAXMAX  )
                count++ ;
        }
        SmallPath[i][0] = count ;
    }
    

    for(int i= 0;i< 20 ;++i)
    {
        for(int j = 0 ;j < 20 ;++j)
            cout << SmallPath[i][j]  <<  " " ;
            cout << endl ;
    }
    cout << " &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&  " << endl ;


    int min = SmallPath[0][0] ,index = 0  ;
    cout << "min == " << min << endl ;  // 3
    cout << "index  == " << index  << endl ;  // 3
    for(int i = 0 ;i < MAXMAX ;++i)
    {   
        if(SmallPath[i][0] < min )
        {
            min = SmallPath[i][0];
            index =  i ;
            cout << "min == " << min << endl ;  // 3
            cout << "index  == " << index  << endl ;  // 3
        }
    }
    cout << "min == " << min << endl ;  // 3
    cout << "index  == " << index  << endl ;  // 3
    for(int i= 0;i< 20 ;++i)
    {
        for(int j = 0 ;j < 20 ;++j)
            cout << SmallPath[i][j]  <<  " " ;
            cout << endl ;
    }
    cout << " %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% " << endl ;
    for(int i = 0 ;i< MAXMAX ;++i)
    {
        if(SmallPath[index][i] != MAXMAX )
            cout <<  vex[SmallPath[index][i]].CityName << "---> "  ;
    }
    cout << endl ;
    exit(0);

}


void Graph::ddffss(int index_A, int index_B, int depth)
{
    nodes[depth] = index_A  ;
    vex[index_A].visted = true ;

    if ( index_A == index_B) 
    {
        k++ ;
        for (int i = 1 ; i <= depth; i++)
        {
            SmallPath[k][i] = nodes[i] ;  
            cout <<   vex[nodes[i]].CityName  <<  "---->> "   ;
        }
        cout  <<  endl;
        return ;
    }
    // for (int i = 0; i < vexnum  ; i++)
    // {
    //     cout << arcs_distance[index_A][i] << "   " ;
    // }
    // cout <<  endl   ;
    for (int i = 0; i < vexnum  ; i++)
    {
        if (arcs_distance[index_A][i] != MAXMAX ) 
        {
            if (vex[i].visted == false)
            {
                vex[i].visted  =  true ;
                ddffss(i, index_B, depth + 1) ;
                vex[i].visted  =  false ;
            }
        }
    }
}

int Graph::printRoute(int index_A ,int index_B ) //查 询 两 地 之 间 的 所 有 路 线
{
    k = 0 ;
    ddffss(index_A,index_B ) ;
}

/*****************************************管理员****************************************/
int Graph::GraphRoot()
{

}
