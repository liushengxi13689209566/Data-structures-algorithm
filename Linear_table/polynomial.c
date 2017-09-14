/*************************************************************************
	> File Name: polynomial.c
	> Author: Linuxer_liu
	> Mail: 
	> Created Time: 2017年09月11日 星期一 17时23分51秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
typedef struct TT {
    int coef ;
    int index ;
    struct TT *next ;
}Polyn;
Polyn *CreatePoly() //创建多项式
{
    Polyn *head,*rear,*new;
    int c,e ;
    rear= head=(Polyn *)malloc(sizeof(Polyn));
    printf("请依次输入多项式的系数和指数：(输入0 结束)\n"); //默认指数从大到小
    scanf("%d ,%d ",&c,&e);
    while(c &&  e ) // c 和e 都不为0 时
    {
        new = (Polyn *)malloc(sizeof(Polyn));
        new->coef= c ;
        new ->index = e ;
        rear->next = new ;
        rear = new ;
        scanf("%d ,%d ",&c,&e);
    }
    rear->next = NULL;
    return head ;
}

void printPolyn(Polyn *head )
{


    
}

 
