/*************************************************************************
	> File Name: Decimal_conversion_with_Liner.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月16日 星期一 22时30分50秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define STACKSIZE   100
typedef struct node{
    int top;
    int base;
    int *count ;   //容器
}Mystack;

int IsEmptyStack(Mystack *p) 
{
    if(p->top == p->base )
        return 1;
    else return 0;
}
int pop(Mystack *p)  //出栈,判断是否栈空
{
    int temp ;
    if(IsEmptyStack(p) == 1){
        printf("The stack is empty  \n");
        return -1;
    }
    temp=p->count[p->top];
    p->top--;
    return temp;
}
int push(Mystack *p,int t)  //入栈，判断是否栈满
{
    if(p->top - p->base == STACKSIZE){
        printf("The stack is full \n");
        return -1;
    }
    p->top++;
    p->count[p->top]=t ;
    return 0;
}
int ExchangeBin(Mystack *p,int x)
{
    int tag= 0;  //tag == 1 就是负数
    int temp  = abs(x);
    if(x < 0) tag =  1;
    while(temp){
        push(p,temp%2);
        temp/=2;
    }
    if(tag == 1)
        printf(" -");
    while(IsEmptyStack(p) !=  1)
        printf("%2d",pop(p));
    printf("\n\n");
    return 0;
}
int main(void)
{
    Mystack *s ;
    int x ;
    printf("Please input the integer \nX: ");
    scanf("%d",&x);
    if(x == 0){
        printf(" 0 \n\n");
        return 0;
    }
    s=(Mystack *)malloc(sizeof(Mystack) );
    s->count=(int *)malloc(sizeof(int)*STACKSIZE);
    s->top = s->base = -1 ;

    ExchangeBin(s,x);
    free(s->count);
    free(s);
    return 0;
}
