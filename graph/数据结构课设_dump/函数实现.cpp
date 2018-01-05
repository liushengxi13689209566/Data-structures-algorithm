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

int Graph::GraphUserQueryRoute()    //查 询 两 地 之 间 的 线 路  
{
    string start ,end ;
    printf(YELLOW"\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t    请 输 入 起 点 ：   \n\n"END);
    cin >> start ;
    printf(BLUE  "\t\t\t\t\t\t\t    请 输 入 终 点 ：   \n\n"END); 
    cin >> end ;

    int index_A,index_B ;
    index_A = getCityIndex(start); 
    index_B = getCityIndex(end);

    printRoute(index_A,index_B) ;

    int choice ;
    do
    {
        //printf("\033c");
        printf(YELLOW"\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t    0.中 转 次 数 最 少   \n\n"END); //一旦要选择排序就意味着
                                                                                        //必须要进行存储
        printf(BLUE  "\t\t\t\t\t\t\t    1.距 离 最 优  \n\n"END);  
        printf(RED   "\t\t\t\t\t\t\t    2.money  最 少 \n\n" END);
        printf(BLUE  "\t\t\t\t\t\t\t    3.时 间 最  短   \n\n"END); 
        printf(RED   "\t\t\t\t\t\t\t    4.      取   消\n\n" END);
        printf(      "\t\t\t\t\t\t\t    请输入你的选择 ：" );
        cin >> choice ;
        switch(choice)
        {
            case 0:  printRouteByCount(index_A,index_B);     break ;
            case 1:  printRouteBydistance(index_A,index_B);   break ;
            case 2:  /*printRouteByMoney() ;*/break ;
            case 3:  /*printRouteByTime() ;  */break;
            case 4: break ;
            default :printf(RED"\n\n\t\t\t\t\t\t\t输入有错～～～,请检查后重新输入!!!\n"END); sleep(1) ;  break ;
        }
    }while(choice != 4 ) ;
    return 0;
}
int Graph::printRouteByCount(int index_A ,int index_B)  //集中精力处理SmallPath 
{
    int min = SmallPath[1][0], index = 1 ;
    for(int i = 0 ; i <  k ;++i)
    {   
        if(SmallPath[i][0] < min )
        {
            min = SmallPath[i][0];
            index =  i ;
        }
    }
    for(int j =  1 ;j < MAXMAX ;++j)
    {
        if(SmallPath[index][j] != MAXMAX )
            cout <<  vex[SmallPath[index][j]].CityName << "---> "  ;
    }
    cout << endl  ; 
}


void Graph::getPath(int j ,int k,int Path[][MAXSIZE]){
    if(Path[j][k] != -1)  
    {  
        cout << "*****************************************" <<  endl ;
        getPath(j,Path[j][k],Path);  
        cout <<   "--> "      << Path[j][k];  
        getPath(Path[j][k],k,Path);  
    }  
}  
void Graph::Floyd(int A[][MAXSIZE],int index_A,int index_B)
{
    int Path[MAXSIZE][MAXSIZE] ;
    for (int i = 0;i < MAXSIZE ; i++)  
        for (int j = 0;j < MAXSIZE ;j++)  
        {  
            A[i][j] = arcs_distance[i][j];  
            Path[i][j] = -1 ;  
        }  
    int N = vexnum ;
    for (int k = 0;k < N;k++)  
        for (int i = 0;i < N;i++)  
            for (int j = 0;j < N;j++){  
                if (A[i][k] + A[k][j] < A[i][j])  
                {  
                    A[i][j] = A[i][k] + A[k][j];  
                    Path[i][j] =  k ;   
                }  
            } 
        for(int i = 0;i < N ; i++)
        {
            for(int j = 0;j< N  ; j++)
            {
                printf("%d ",Path[i][j]);
            }
            printf("\n");
        }
    getPath(index_A,index_B,Path);
}
int Graph::printRouteBydistance(int index_A,int index_B)    //floyd 算法
{
    cout << "7&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&  " <<  endl ;
    int F[MAXSIZE][MAXSIZE] ;
    Floyd(F,index_A,index_B);
    return 0;
}

void Graph::ddffss(int index_A, int index_B, int depth)
{
    nodes[depth] = index_A  ;
    vex[index_A].visted = true ;
    if ( index_A == index_B) 
    {
        for (int i = 1 ; i <= depth; i++)
        {
            SmallPath[k][i] = nodes[i] ;  
            if(i != depth )
                cout <<   vex[nodes[i]].CityName  <<  "---->> "   ;
            else 
                 cout <<   vex[nodes[i]].CityName  << endl ;
        }
        SmallPath[k][0] = depth + 1  ;
        k++ ;
        cout  <<  endl;
        return ;
    }
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

int Graph::printRoute(int index_A ,int index_B ) //查询两地之间的所有路线,第一个执行的函数
{
/****************************初始化*********************/
    for(int i= 0;i< MAXMAX ;++i)
    {
        for(int j = 0 ;j < MAXMAX ;++j)
            SmallPath[i][j]= MAXMAX ;
    }
    k = 0 ;
    for(int i= 0 ;i< 1000 ;i++)
        nodes[i] = MAXMAX ;

    for (int i = 0; i < vexnum; i++)
        vex[i].visted = false;
    ddffss(index_A,index_B ) ;
}

/*****************************************管理员(提供与数据库交互的接口)****************************************/
int Graph::GraphRoot()
{
    int choice  ;
    MYSQL_RES *res ;
    MYSQL_ROW row ;
    mysql = mysql_init(NULL);   //打开数据库
    if(!mysql)   cout << "数据库初始化出错  " << endl ;
    mysql_connect(mysql) ; 
    do
    {
        //printf("\033c");
        printf(YELLOW"\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t    0.删 除 一 个 地 点   \n\n"END); //一旦要选择排序就意味着
                                                                                        //必须要进行存储
        printf(BLUE  "\t\t\t\t\t\t\t    1.撤 销 路 线  \n\n"END);  
        printf(RED   "\t\t\t\t\t\t\t    2.增 加 一 个  地 点 \n\n" END);
        printf(BLUE  "\t\t\t\t\t\t\t    3.增 加 一 条 路  线   \n\n"END); 
        printf(BLUE  "\t\t\t\t\t\t\t    4.我 要 布 网 \n\n"END);  
        printf(RED   "\t\t\t\t\t\t\t    5.      取   消\n\n" END);
        printf(      "\t\t\t\t\t\t\t    请输入你的选择 ：" );
        cin >> choice ;
        switch(choice)
        {
            case 0:  deleteACity() ;  break ;
            case 1:  undoRoad();  break ;
            case 2:  AddCity() ;break ;
            case 3:  /*AddRoad() ;  */break;
            case 4:  SetNet();  break;
            case 5: break ;
            default :printf(RED"\n\n\t\t\t\t\t\t\t输入有错～～～,请检查后重新输入!!!\n"END); sleep(1) ;  break ;
        }
    }while(choice != 5) ;
    close_connection(mysql);
    return 0;
}
int  Graph::deleteACity()  //删 除 一 个 地 点  success 
{
    string name ;
    printf(YELLOW"\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t    请 输 入 地 点 名 称 ：   \n\n"END);
    cin >> name ;

    int index_A ;   // 为了删除边的信息，必须要它所对应的下标
    index_A = getCityIndex(name) ; 
    // cout << index_A << endl ;
    string temp = to_string(index_A);
    string query2= "delete from Edge  where  index_A =   " + temp + "  or  index_B =  " + temp  ;
    // cout << query2 << endl ;
    
    int t =  mysql_real_query(mysql ,query2.c_str(),query2.size());
    if(t != 0 )    cout << "server mysql_real_query" << endl ;
    
    string query1 = "delete from City  where CityName =  '"+ name + "'" ;
    t =  mysql_real_query(mysql ,query1.c_str(),query1.size());
    if(t != 0 )    cout << "server mysql_real_query" << endl ;

    
}
int Graph::undoRoad()  // 撤 销  路 线  success 
{
    string  start ,end ;
    printf(YELLOW"\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t    请 输 入 起 点 ：   \n\n"END);
    cin >> start ;
    printf(BLUE  "\t\t\t\t\t\t\t    请 输 入 终 点 ：   \n\n"END); 
    cin >> end  ;

    int index_A,index_B  ;   
    index_A = getCityIndex(start) ; 
    index_B = getCityIndex(end) ;
   
    string temp_A = to_string(index_A);
    string temp_B = to_string(index_B) ;

    string query2 = "delete from Edge  where  index_A = " + temp_A + "  and  index_B = " + temp_B   ;
        // cout <<" query2 ==  " << query2 << endl ;

    int t =  mysql_real_query(mysql ,query2.c_str(),query2.size());
    if(t != 0 )    cout << "server mysql_real_query" << endl ;
    
    string query1 = "delete from Edge   where index_A =   " + temp_B + "  and  index_B   =  " + temp_A   ;
    // cout <<" query1 ==  " << query1 << endl ;
    t =  mysql_real_query(mysql ,query1.c_str(),query1.size());
    if(t != 0 )    cout << "server mysql_real_query" << endl ;
}

int Graph::AddCity()  //增 加 一 个  地 点 success
{
    string name ;
    printf(YELLOW"\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t    请 输 入 地 点 名 称 ：   \n\n"END);
    cin >> name ;
    string webUrl ;
    printf(YELLOW"\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t    请 输 入 地 点 查 询 网 址  ：   \n\n"END);
    cin >> webUrl  ;
    string query2= "INSERT INTO City VALUES(NULL, '" + name +"' , '"+ webUrl + "' )"  ;
    cout << query2 << endl ;
    
    int t =  mysql_real_query(mysql ,query2.c_str(),query2.size());
    if(t != 0 )    cout << "server mysql_real_query" << endl ;

}
// int Graph::AddRoad() // 增 加 一 条 路  线  
// {
// }

int Graph::SetNet()  //我 要 布 网  
{
    string  start ;
    printf(YELLOW"\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t    请 输 入 起 点 ：   \n\n"END);
    cin >> start ;
    int index = getCityIndex(start);
    cout << "index  == " << index << endl ;
    Prim(index);
    return  0; 
} 
void Graph::Prim(int start)    // 找到最小生成树 prim 算法    布网！！！！ （根据距离～～） 有bug！！！！ 
{
    struct{
        int adjvex;
        int lowcost;
    }closedge[MAXSIZE];
    int i, e, k, m, min ;
    //初始化
    closedge[start].lowcost = 0;
    for(i = 0 ; i < vexnum; i++){
        if(i != start){
        closedge[i].adjvex = start;
        closedge[i].lowcost = arcs_distance[start][i];
        }
    }
    //找最小值的边
    for(e =  0 ; e < vexnum ; e++){
        min = MAXMAX ;
        for(k =  0;  k <   vexnum; k++){
            if(closedge[k].lowcost != 0 && closedge[k].lowcost < min){
                m = k;
                min = closedge[k].lowcost;
            }
        }
        cout << vex[closedge[m].adjvex].CityName << "----->" << vex[m].CityName 
        <<   "距离为 "  <<  closedge[m].lowcost  << endl ;
        closedge[m].lowcost = 0;
        //加入后，更新closedge数组
        for(i =  0 ; i <   vexnum; i++){
            if(i != m &&  arcs_distance[m][i] < closedge[i].lowcost){
                closedge[i].lowcost = arcs_distance[m][i];
                closedge[i].adjvex = m;
            }
        }
    }
}
