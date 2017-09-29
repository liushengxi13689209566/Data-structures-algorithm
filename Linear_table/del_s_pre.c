/*************************************************************************
	> File Name: del_s_pre.c
	> Author: 
	> Mail: 
	> Created Time: 2017年09月22日 星期五 13时36分41秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define N    6   //3 10 11 
#define M    9
typedef struct student{
    int num ;
    struct student *next ;
}STU;

void printList(STU *head)
{
    STU *temp = head ;
    while(temp->next  != head )
    {
        printf("\t%d\t",temp->num );
        temp = temp->next ;
    }
    printf("\t%d\t",temp->num );
    printf("\n");
}

int get_s(STU *head,STU **s)
{
    STU *temp =  head ;
    int i ;
    for(i=  1  ;i< M ;i++)
        temp = temp->next ;
    *s=temp ;
    return 0;
}
int del_s_pre(STU *s)
{
    STU *Ppre,*Pre ;
    Ppre = Pre = s;     //考虑指到他本身的情况和指到头节点的情况
    while(Ppre->next->next != s)
    {
        Ppre = Ppre->next ;
        Pre = Pre->next ;
    }
    Pre = Pre->next ;
    Ppre->next =Pre->next ;
    free(Pre);
    return 0;
}

int main(void)    //循环链表的长度大于1 
{
    STU  *new ,*head ,*end ,*s ;
    int i ;
    end = head =(STU *)malloc(sizeof(STU));
    head->next = NULL ;
    printf("please input the num :");
    scanf("%d",&head->num );
    //printf("head->num == %d\n",head->num);
    /*if(temp->num == 0 )    
    {
        printf(" Is not match the question ,please try again \n");
        return  -1 ;
    }*/
    for(i = 1;i< N ;i++)
    {
        new =(STU *)malloc(sizeof(STU));
        new->next = NULL ;
        printf("please input the num :");
        scanf("%d",&new->num );
        //printf("new->num == %d\n",new->num);
        end->next = new ;
        end = new ;
    }
    end->next = head ;
    printList(head);
    get_s(head,&s);
    del_s_pre(s); //如果删除的是头节点的话，还要把head 传进去
    printList(head);
}
