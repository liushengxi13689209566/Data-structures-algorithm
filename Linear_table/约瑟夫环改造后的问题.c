/*************************************************************************
	> File Name: 约瑟夫环改造后的问题.c   //基本上得用循环链表实现
	> Author: Linuxer_liu
	> Mail: 
	> Created Time: 2017年09月12日 星期二 14时08分10秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>

#define N  8 
typedef struct man{
    int  ID;   //编号
    int passwd ;  //密码
    struct man *llink ,*rlink ;
}NODE ;

/*int freeList(NODE *head)
{
    NODE *temp= head ;
    while(temp->rlink != head)
        free(temp);
    free(temp);
    return 0;
}*/
int creatList(NODE *head )
{
    NODE *new, *mid ;
    int i ;
    mid =(NODE *)malloc(sizeof(NODE));
    mid = head ;
    for(i= 1 ;i< N ;i++)
    {
        new = (NODE *)malloc(sizeof(NODE));
        new->ID= i+1 ;
        printf("please input the  %d  man's passwd :",new->ID);
        scanf("%d",&new->passwd);
        new->llink = mid ;
        mid->rlink= new ;
        mid = new ;
    }
    new->rlink = head ; // 引发“Segmentation fault (核心已转储)”的原因
}


int printList(NODE *head)
{
    NODE *temp = head ;
    while(temp->rlink != head)
    {
        printf("The %d 's passwd is  %d \n",temp->ID,temp->passwd);
        temp=temp->rlink ;
    }
   // printf("The %d 's passwd is  %d \n",temp->ID,temp->passwd);
    return 0;
}



int Deal(NODE **head ,int m)     //要改变head 的值
{
    NODE *temp ;
    int i;
    if(*head == NULL )
    {

    }
    temp =(NODE *)malloc(sizeof(NODE));
    if(m  ==  0){  //delete the head 
        printf("the %d man is out and her passwd is %d \n",(*head)->ID ,(*head)->passwd);
        temp = *head ;
        *head = (*head)->rlink ;
        free(temp);
    }
    else if( m > 0){
        temp = *head ;
        for(i= 0;i< m ;i++)
            temp = temp->rlink ;
        m= temp->passwd ;
        temp =temp->rlink ;
        Deal(&temp ,m );
    }
    else {  //m < 0 

    }

}

int main(void)
{
    int m ;
    NODE *head ; 

    head =(NODE *)malloc(sizeof(NODE));
    head->ID = 1 ;
    printf("please input the  %d  man's passwd :",head->ID);
    scanf("%d",&head->passwd);
    //head->llink=head->rlink = NULL ; //左右指针都设置为空

    creatList(head);

    printList(head);
    //freeList(head) ;
    printf("Please input the original m :");
    scanf("%d",&m);

    Deal(&head,m);

    return 0 ;
}

