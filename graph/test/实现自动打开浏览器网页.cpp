/*************************************************************************
	> File Name: 实现自动打开浏览器网页.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月01日 星期一 16时11分36秒
 ************************************************************************/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>
using namespace std ;


int main(void)
{
   string name ;
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t    请 输 入 城 市 名 称  ：   \n\n");
    cin >> name  ;       // 需要检查是否输入正确哦，后面再处理 ～～
    pid_t  pid_love ;
    int status_love ;
    pid_love = fork();  //第一次fork 进程
    name = "/opt/google/chrome/google-chrome   " + name  ;
    switch(pid_love)
    {
        case -1:   printf("fork pid_love  ERROR !!!\n") ;return 0;
        case 0 :  
        system(name.c_str());
        default:  break;
    }
}
