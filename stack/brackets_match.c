/*************************************************************************
	> File Name: brackets_match.c
	> Author: 
	> Mail: 
	> Created Time: 2017年09月29日 星期五 12时00分24秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>

typedef struct link{
    char a;
    struct link *next;
}LinkList ;

LinkList*  InitLink( )
{
    LinkList *head ;
    head =(LinkList *)malloc(sizeof(LinkList));
    head->next = NULL ;
    return head ;
}

int InStack(LinkList *head,char p)  //链栈不需要判断栈满
{
    LinkList *temp ;
    temp =(LinkList *)malloc(sizeof(LinkList));
    temp->a = p;
    temp->next = head->next ;
    head->next = temp ;
    return 0;
}
int IsEmptyStack(LinkList *head)
{
    if(head->next == NULL)
        return -1 ; //为空栈
    else return 1;
}
char OutStack(LinkList *head)  //判断栈空
{
    char temp ;
    LinkList *t ;
    t= head->next ;
    temp=head->next->a ;
    head->next = t->next ;
    free(t);
    return temp;
}
int print(LinkList *head)
{
    LinkList *temp ;
    temp = head->next ;
    while(temp)
    {
        printf("str == %c\n",temp->a);
        temp=temp->next ;
    }
}
int main(void)
{
    char str[52];
    int i;
    char temp;
    int t = 0;
    LinkList *head ;
    head = InitLink();
    printf("please input the tseted string \n");  
    scanf("%s",str);
    for(i= 0 ;str[i] ;i++)
    {
        if(str[i] == '{' || str[i] == '(')
        {
            InStack(head,str[i]);
            //print(head);
        }
        else  if(str[i] == ')')
        {
            if(IsEmptyStack(head) <  0)
            {
                printf("右 括 号 冗 余 \n");
                break;
            }
            temp = OutStack(head);
            if(temp == '(')
                t++ ;
        }
        else if(str[i] == '}')
        {
            if(IsEmptyStack(head) <  0)
            {
                printf("右 括 号 冗 余 \n");
                break;
            }
            temp = OutStack(head);
            if(temp == '{')
                t++ ;
        }
    }
    if(IsEmptyStack(head) > 0)  //最后判断栈是否空
        printf("左括号冗余\n");
    else {
    printf("一共匹配了%d 对 \n",t);
    return 0;
    }
    printf("已匹配了%d 对\n",t);
    return 0;
}




