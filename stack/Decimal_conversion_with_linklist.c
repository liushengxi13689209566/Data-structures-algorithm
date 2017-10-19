/*************************************************************************
	> File Name: Decimal_conversion.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月16日 星期一 20时08分13秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define STACKSIZE 100 
typedef struct node{
    int data;
}NODE ;
typedef struct stack{
    NODE *top;
    NODE *base;
    int StackSize ;
}Mystack;

int InitStack(Mystack *p)
{
    p->top = p->base =(NODE *)malloc(sizeof(NODE)*STACKSIZE);
    if(p->top == NULL)
    {
        printf("malloc  error \n");
        return -1;
    }
    p->StackSize = STACKSIZE ;
    return 0;
}
int IsEmptyStack(Mystack *p)
{
    if(p->top == p->base)
        return 1;
    else return 0;
}
int pop(Mystack *p)
{
    NODE temp;
    if(IsEmptyStack(p)){
        printf("The stack is empty \n");
        return 0;
    }
    temp=*(p->top-1);
    p->top--;
    return temp.data;
}
int push(Mystack *p,int t)
{
    NODE element;
    if(p->top - p->base == STACKSIZE){
        printf("The stack is full \n");
        return -1;
    }
    element.data = t ;
    *(p->top) = element ;
    p->top++;
}
int ExchangeBin(int x)
{
    Mystack ty ;
    int tag =  0 ;
    int temp = abs(x ) ;
    if(x< 0)   tag = 1;
    InitStack(&ty);
    while(temp) 
    { 
        push(&ty,temp%2);
        temp /=2 ;
    }
    if(tag)   printf(" -");
    while(IsEmptyStack(&ty) != 1)
        printf("%2d",pop(&ty));
    printf("\n\n");
    return 0;

}
int main(void)
{
    int x;
    printf("Please input the \nX :");
    scanf("%d",&x);
    ExchangeBin(x);
    return 0;
}
