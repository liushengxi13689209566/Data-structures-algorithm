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
    pid_t  pid_love ;
    int status_love ;
    pid_love=fork();
             switch(pid_love)
             {
                 case -1:   printf("fork pid_love  ERROR !!!\n") ;return 0;
                 case 0 :   /*execvp("/opt/google/chrome/google-chrome",arg );*/
                 system("/opt/google/chrome/google-chrome  https://github.com/ ");
                 sleep(8) ; exit(0);
                 default:if(waitpid(pid_love ,&status_love,0)< 0)
                        {
                            printf("waitpid is  ERROR !!!\n");
                            return  0;
                        }
                        break;
             }
}
