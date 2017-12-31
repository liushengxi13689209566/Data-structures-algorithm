/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月31日 星期日 10时47分03秒
 ************************************************************************/

#include<iostream>
#include"myhead.h"
using namespace std;
int main(void)
{
    Graph g ;
    g.create(g);
    g.print(g);
    int F[20][20];
   
   
    g.Floyd(g,F);
   
    return 0;

}
