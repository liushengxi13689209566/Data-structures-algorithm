/*************************************************************************
	> File Name: 线索二叉数的建立.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月22日 星期三 21时29分24秒
 ************************************************************************/

#include<iostream>
using namespace std;

typedef struct Node {
    char data ;
    int Ltag ;
    int Rtag ;
    struct Node * Lchild ;
    struct Node * Rchild ;
} BiNode ;

BiNode *pre = NULL ;

void CreteBitree(BiNode **root)  
{
    char ch ;
    cin >> ch ;
    if( ch == '#' ) 
        *root= NULL;
    else {
        *root = (BiNode *)malloc(sizeof(BiNode));
        (*root)->data = ch;
        (*root)->Ltag = 0 ;
        (*root)->Rtag = 0;
        CreteBitree(&(*root)->Lchild);
        CreteBitree(&(*root)->Rchild);
    }
}

BiNode *InNext(BiNode *p)
{
    BiNode *q = NULL ;
    BiNode *next = NULL ;
    if(p->Rtag == 1)
        next=p->Rchild ;
    else {
        for(q = p->Rchild ; q->Ltag == 0 ;q=q->Lchild)
            next =q;
    }
    return next ;
}

BiNode *Infrist(BiNode *bt)
{
    BiNode *temp =bt ;
    if(temp == NULL )
        return NULL;
    while(temp->Ltag == 0)
        temp = temp->Lchild;
    return temp ;
}

void TinOrder(BiNode *root) //中序遍历
{
    BiNode *p;
    p= Infrist(root);
    while(p != NULL)
    {
        cout << p->data  << endl ;
        p=InNext(p);
    }
}

void Inthread(BiNode  *root) //  中序线索化
{
    if(root)
    {
        Inthread(root->Lchild);
        if(root->Lchild == NULL)
        {
            root->Lchild = pre ;
            root->Ltag = 1;
        }
        if(pre != NULL && pre->Rchild == NULL)
        {
            pre->Rchild = root ;
            pre->Rtag = 1;
        }
        pre = root ;
        Inthread(root->Rchild);
    }
}
/*void InOrder(BiNode  *root) //  中序遍历
{
    if(root)
    {
        InOrder(root->Lchild);
        cout << root->data <<  "  ";
        cout << root->Ltag <<  "  ";
        cout << root->Rtag <<  "  ";

        InOrder(root->Rchild);
    }
    cout << endl ;
}*/

int main(void)
{
    BiNode *root;
    cout  << "Please input the  string :" << endl ;

    CreteBitree(&root);
    /*cout<< "递归！！先序线索化：" << endl ;
    Prethread(root);
    cout << endl;*/
    cout<< "中序线索化：" << endl ;
    Inthread(root);
    cout << endl;

    //InOrder(root);

    TinOrder(root);
/*    cout<< "后序线索化：" << endl ;
    PostOrder(root);
    cout << endl ;*/
    return 0;
}
