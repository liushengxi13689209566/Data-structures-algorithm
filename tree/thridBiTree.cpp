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
    int tag ;    //标记是左子树进栈的还是右子树进栈的
    struct temp *next ;
}SeqStack;

void CreteBitree(BiTree *root)  
{
    char ch ;
    cin >> ch ;
    //cout << ch ;
    //scanf("%c",&ch);
    if( ch == '#' ) 
        *root= NULL;
    else {
        //cout  << ch << endl ;
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
void Push(SeqStack *S,BiTree p,int flag)
{
    SeqStack *temp ;
    temp = (SeqStack *)malloc(sizeof(SeqStack));
    temp->tag = flag; //标志
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

void PostOrder_with_stack(BiTree root)
{
    SeqStack *S;
    BiTree p ;
    int flag = 0  ;
    InitSeqStack(&S); 
    p = root ;
    while(p != NULL || !IsEmpty(S) )
    {
        while(p != NULL ) //都是在左子树
        {
            //入栈
            Push(S,p,flag);
            cout << S->next->ptr->data  <<  "   " ;
            cout << S->next->tag  << endl ;

            p = p->Lchild;
            flag= 0 ;
        }
        if(!IsEmpty(S))
        {
            cout << S->next->tag << endl ;
            if(S->next->tag == 1){
                cout << "111111" << endl ;
                Pop(S,&p);
                cout << p->data ;
            }
            else {
                cout << "222222" << endl ;
                flag =  1;

                p=S->next->ptr->Rchild ;
                cout << p->data << endl ;
            }
        }
    }
    cout << endl ;
}

void PostOrder(BiTree root) //BiTree 就是 BiNode*    后序遍历
{
    if(root)
    {
        PostOrder(root->Lchild);
        PostOrder(root->Rchild);
        cout << root->data ;
    }
}

int main(void)
{
    BiTree root;
    cout  << "Please input the  string :" << endl ;

    CreteBitree(&root);
    //PostOrder(root);
    //cout << endl ;
    PostOrder_with_stack(root);  
    return 0;
}



