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
}BiNode ; 

typedef struct temp{
    BiNode *ptr;
    int tag ;
    struct temp *next ;
}SeqStack;

void CreteBitree(BiNode **root)  
{
    char ch ;
    cin >> ch ;
    if( ch == '#' ) 
        *root= NULL;
    else {
        *root = (BiNode *)malloc(sizeof(BiNode));
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

void Push(SeqStack *S,SeqStack p)
{
    SeqStack *temp ;
    temp=(SeqStack *)malloc(sizeof(SeqStack));
    temp->tag = p.tag ;
    temp->ptr = p.ptr ;
    temp->next = S->next ;
    S->next = temp ;
}

SeqStack Pop(SeqStack *S ,SeqStack p)
{
    SeqStack *t ;
    t= S->next ;
    p.ptr = t->ptr ;
    p.tag = t->tag ;
    S->next = t->next ;
    free(t);
    return p ;
}
int IsEmpty(SeqStack *S)
{
    if(S->next == NULL )
        return 1;
    else return 0;
}
void PostOrder_with_stack(BiNode *root)
{
    SeqStack *S;
    SeqStack p ;
    InitSeqStack(&S); 
    p.ptr = root ;
    while(p.ptr != NULL || !IsEmpty(S) )
    {
        while(p.ptr != NULL )
        {
            //入栈
            p.tag= 0 ;
            Push(S,p);
            p.ptr=p.ptr->Lchild;
        }
        if(!IsEmpty(S))
        {
            p=Pop(S,p);
    //cout << "3333333" << endl ;
            if(p.tag == 0 ){
                p.tag = 1;
                Push(S,p);
                p.ptr=p.ptr->Rchild;
            }
            else{
                cout << p.ptr->data ;
                p.ptr = NULL  ; // 这是为什么？？
            }
        }
    }
    cout << endl ;
}

int main(void)
{
    BiNode *root;
    cout  << "Please input the  string :" << endl ;

    CreteBitree(&root);
    cout << "非递归！！！后序遍历：" << endl;
    PostOrder_with_stack(root);  
    return 0;
}



