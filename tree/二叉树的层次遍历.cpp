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
typedef struct t1{
    BiNode *ptr ;
    struct t1 *next ;
}Queue;
typedef struct t2{  
    Queue *front;
    Queue *rear;
}LinkList_Queue;
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
void InitQueue(LinkList_Queue **Q)
{
    *Q =(LinkList_Queue *)malloc(sizeof(LinkList_Queue)) ;
    (*Q)->front = (*Q)->rear = (Queue *)malloc(sizeof(Queue));
    (*Q)->front->next  = NULL;
}

void InQueue(LinkList_Queue *Q ,BiNode *p)
{
    Queue *temp ;
    temp = (Queue *)malloc(sizeof(Queue));
    temp->ptr = p ;
    temp->next = Q->rear->next ;  //尾插
    Q->rear->next = temp ;
    Q->rear = temp ;
}
void OutQueue(LinkList_Queue *Q,BiNode **p)  //赋值给p ，头取
{
    Queue *temp ;
    temp = Q->front->next;
    (*p) = Q->front->next->ptr ;
    Q->front->next = temp->next ;
    if(Q->front->next == NULL ) //一个元素时，需要修改尾指针 ！！！！
        Q->front = Q->rear ;
}

int IsEmpyt(LinkList_Queue *Q)
{
    if(Q->front == Q->rear )  
        return 1;
    else return 0;
}
void LevelOrder(BiNode *root) //层次遍历
{
    LinkList_Queue *Q;
    BiNode *p;
    InitQueue(&Q);
    InQueue(Q,root);
    while( !IsEmpyt(Q))
    {
        OutQueue(Q,&p);  //p 是 BiNode 型的，Q 是LinkList_Queue 型的
        cout << p->data << "  ";
        if(p->Lchild != NULL )
            InQueue(Q,p->Lchild);
        if(p->Rchild != NULL)
            InQueue(Q,p->Rchild);
    }
    cout << endl ;
}
void PostOrder(BiNode *root) //后序遍历
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
    BiNode *root;
    cout  << "Please input the  string :" << endl ;
    CreteBitree(&root);
    //PostOrder(root);
    //cout << endl ;
    cout << "层次遍历：" << endl ;
    LevelOrder(root);
    cout << endl;
    return 0;
}



