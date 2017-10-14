

#include<stdio.h>
#include<stdlib.h>
typedef struct Link{
    int data;
    int passwd ;
    struct Link *next;
}LinkList ;

LinkList* creat(int n)   //  特殊情况；n == 1 
{
    LinkList  *head,*rear, *new ;
    int i ;
    head=rear=(LinkList *)malloc(sizeof(LinkList));
    head->next =NULL;
    for(i= 0 ;i< n;i++)
    {
        new=(LinkList *)malloc(sizeof(LinkList));
        new->data = i+1;
        printf("请输入第%d 个人的密码：",new->data);
        scanf("%d",&new->passwd);
        new->next = NULL ;
        rear->next = new ;
        rear = new ;
    }
    rear->next = head->next ;
    return rear ;
}

/*int print_2(LinkList *rear)   //打印循环链表
{
    LinkList *temp= rear->next  ;
    while(temp != rear )
    {
        printf("出对顺序为：");
        printf("%d\t",temp->data);
        temp= temp->next ;
    }
    return 0;  
}*/

LinkList *fun(LinkList *rear ,int n)
{
    LinkList  *temp, *new_head , *new_rear  ;
    int i ;
    int t= n ;
    new_head =  new_rear = (LinkList *)malloc(sizeof(LinkList));
    new_head->next = NULL ;
    while(rear != rear->next)
    {
        for(i= 0 ;i< t - 1 ;i++)
            rear= rear->next ;
        temp = rear->next ;   //要删除的就是rear 的下一个节点
        rear->next = temp->next ;
        temp->next = NULL ;
        t = temp->passwd;  //当passwd == 0 时，直接会删除rear 的下一个节点，符合逻辑，保留
        new_rear->next = temp ;
        new_rear = temp ;
        new_rear->next= NULL ;
    }
    new_rear->next = rear ;    //把最后剩的一个连到另一个链表的尾部
    new_rear = rear ;
    new_rear->next= NULL ;
    return new_head;
}

int print(LinkList *head2)
{
    LinkList *temp= head2->next ;
    while(temp)
    {
        printf("出对顺序为：");
        printf("%d\n",temp->data);
        temp= temp->next ;
    }
    return 0;
    
}
int main(void){  
    LinkList *rear ,*head2 ;
    int n ;
    printf("请输入一共有多少个人：");
    scanf("%d",&n);
    rear = creat(n);
//    print_2(rear);
    head2 = fun(rear,3) ;
    print(head2);
    return 0;
}  




