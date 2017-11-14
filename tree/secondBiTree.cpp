/*************************************************************************
	> File Name: fristrBiTree.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月07日 星期二 22时14分12秒
 ************************************************************************/

#include<iostream>
using namespace std;

typedef struct Node {
    char data ;
    struct Node * Lchild ;
    struct Node * Rchild ;
}BiNode ,*BiTree ; //感觉主要是树上的BiTree复杂了

typedef struct temp{
    BiTree ptr;
    struct temp *next ;
}SeqStack;

void CreteBitree(BiTree *root)  
{
    char ch ;
    cin >> ch ;
    if( ch == '#' ) 
        *root= NULL;
    else {
        *root = (BiTree)malloc(sizeof(BiNode));
        (*root)->data = ch;
        CreteBitree(&(*root)->Lchild);
        CreteBitree(&(*root)->Rchild);
    }
}

void InitSeqStack(SeqStack **S)  //开始创建链表 ,S 就是头节点
{
    *S = (SeqStack *)malloc(sizeof(SeqStack));
    (*S)->next = NULL ;
}
void Push(SeqStack *S,BiTree p)
{
    SeqStack *temp ;
    temp = (SeqStack *)malloc(sizeof(SeqStack));
    temp-> ptr = p;
    temp->next = S->next ;
    S->next = temp ;
}

void Pop(SeqStack *S ,BiTree *p)
{
    SeqStack *t ;
    t= S->next ;
    *p = t->ptr ;
    S->next = t->next ;
    free(t);
}
int IsEmpty(SeqStack *S)
{
    if(S->next == NULL )
        return 1;
    else return 0;
}
void InOrder(BiTree root)
{
    SeqStack *S;
    BiTree p ;
    InitSeqStack(&S); 
    p = root ;
    while(p != NULL || !IsEmpty(S) )
    {
        while(p != NULL )
        {
            //入栈
            Push(S,p);
            p=p->Lchild;
        }
        if(!IsEmpty(S))
        {
            Pop(S,&p);
            cout << p->data ;
            p=p->Rchild ;
        }
    }
    cout << endl ;
}
void PreOrder(BiTree root)
{
    SeqStack *S;
    BiTree p ;
    InitSeqStack(&S); 
    p = root ;
    while(p != NULL || !IsEmpty(S) )
    {
        while(p != NULL )
        {
            //入栈
            cout << p->data ;
            Push(S,p);
            p=p->Lchild;
        }
        if(!IsEmpty(S))
        {
            Pop(S,&p);
            p=p->Rchild ;
        }
    }
    cout << endl ;
}

int main(void)
{
    BiTree root;
    cout  << "Please input the  string :" << endl ;

    CreteBitree(&root);
    cout << "非递归！！！先序：" << endl ;
    PreOrder(root); 
    cout << endl;

    cout << "非递归！！！中序：" << endl ;
    InOrder(root); 
    cout << endl;


    return 0;
}


