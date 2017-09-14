#include<stdio.h>
#include<stdlib.h>
typedef struct student{
    int data;
    struct student *next;

}STU;

STU *creat()
{
    STU *head;
    head=(STU *)malloc(sizeof(STU));
    head->data=0;
    head->next=NULL;
}
void push(STU *pHead)//存
{
    STU *p;
    p=(STU *)malloc(sizeof(STU));
    scanf("%d",&p->data);
    if(pHead->next==NULL)
    {
        pHead->next=p;
        p->next=NULL;
    }
    else 
    {
        p->next=pHead->next;
        pHead->next=p;
    }
}
void pop(STU *pHead)   //取
{
    STU *P;
    if(pHead->next==NULL)
    {
        printf("ERROR!!\n");
        return ;
    }
    P=pHead->next;
    printf("%d\t\n",P->data);
    pHead->next=P->next;
    free(P);
}
STU *creatList(int n)
{
    STU *pHead,*pNew,*pEnd;
    int i;
    pHead=pEnd=(STU *)malloc(sizeof(STU));
    pHead->data=0;
    pHead->next=NULL;
    for(i=0;i<n;i++)
    {
        pNew=(STU *)malloc(sizeof(STU));
        pNew->data=i;
        pEnd->next=pNew;
        pNew->next=NULL;
        pEnd=pNew;
    }
    return pHead;
}
void add(STU *pHead)
{
    STU *temp,*p;
    int n,i,t=0;
    temp=pHead;
    while(temp!=NULL)
    {
        temp=temp->next;
        t++;
    }
    scanf("%d",&n);
    if(n<0 || n>t)
    {
        printf("ERROR!!\n");
        return ;
    }
    temp=pHead;
    for(i=0;i<n;i++)
    {
        temp=temp->next;
    }
    p=(STU *)malloc(sizeof(STU));
    scanf("%d",&p->data);
    p->next=temp->next;
    temp->next=p;
}
void print(STU *pHead)
{
        STU *temp;
        temp=pHead->next;
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("\n\n");
}
int main(void)
{
        STU *pHead;
        pHead=creat();
        push(pHead);
        push(pHead);
        print(pHead);
        //add(pHead);
        pop(pHead);
        pop(pHead);
        pop(pHead);
        print(pHead);
        return 0;
}
