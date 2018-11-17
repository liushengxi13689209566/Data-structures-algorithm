/*************************************************************************
	> File Name: 损坏的键盘.c
	> Author: Linuxer_liu
	> Mail: 
	> Created Time: 2017年08月09日 星期三 19时28分16秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct type {
    char ch ;
    struct type *next ;
}LIST ;
LIST * create()
{
    LIST *head  ;
    head=(LIST *)malloc(sizeof(LIST));
    head->next =NULL ;
    return head ;
}
int main(void)
{
    int i;
    char temp ;
    LIST *head ,*end ,*p;
    while(1)
    {
        head =end =create  ; /*创建头结点*/
        if(scanf("%c",temp) == EOF )   break ;
        if(temp == '\n')      // 输出
        if(temp != '[' && temp != ']')   
        {
            p=(LIST *)malloc(sizeof(LIST));
            p->next = NULL ;
            p->ch=temp ;
            end->next= p ;
            end= p ;
        }
        if(temp  ==  '[')
        {
            p=(LIST *)malloc(sizeof(LIST));
            p->next =NULL ;

        }                   
                       }
                       
                            
                        



    }
   return 0;
}


