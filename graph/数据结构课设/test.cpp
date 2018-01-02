/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月02日 星期二 16时40分29秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include <fstream>
using namespace std;
 
int main()
{
    /*ofstream ocout; 写文件
    ocout.open("test.txt");
    ocout<<"Hello,C++!";
    ocout.close();*/
 // 读文件
    ifstream fcin ;
    fcin.open("input.txt");
    int a,b ;
    string temp ;
    fcin >> temp ;
    a = atoi((char *)temp); 
    printf("a== %d \n",a);
    fcin >> temp ;
    b = atoi((char *)temp); 
    printf("b== %d \n",b);
    fcin.close();

    return 0;
}
