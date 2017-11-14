/*************************************************************************
	> File Name: fristrBiTree.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月07日 星期二 22时14分12秒
 ************************************************************************/

#include<iostream>
#define MAX 512
using namespace std;

typedef struct Node {
    char data ;
    struct Node * Lchild ;
    struct Node * Rchild ;
} BiNode ;

/*void CreteBitree(BiNode **root)  
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
}*/

BiNode * CreteBitree()  
{
    BiNode *p;
    char ch ;
    cin >> ch ;
    if(ch  == '#') 
        return NULL;
    else {
        p= (BiNode *)malloc(sizeof(BiNode));
        p->Lchild->data = ch  ;
        p=CreteBitree();
        p->Rchild=CreteBitree();
    }
    return p; //p is root 
}

void PreOrder(BiNode *root)    //  先序遍历
{
    if(root)
    {
        cout << root->data ;
        PreOrder(root->Lchild);
        PreOrder(root->Rchild);
    }
}

void InOrder(BiNode  *root) //  中序遍历
{
    if(root)
    {
        InOrder(root->Lchild);
        cout << root->data ;
        InOrder(root->Rchild);
    }
}
void PostOrder(BiNode *root) // 后序遍历
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

//    CreteBitree(&root);
    root = CreteBitree();
    cout<< "递归！！！先序遍历：" << endl ;
    PreOrder(root);
    cout << endl;
    cout<< "中序遍历：" << endl ;
    InOrder(root);
    cout << endl;
    cout<< "后序遍历：" << endl ;
    PostOrder(root);
    cout << endl ;
    return 0;
}
