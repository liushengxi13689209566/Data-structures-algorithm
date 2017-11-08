/*************************************************************************
	> File Name: fristrBiTree.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月07日 星期二 22时14分12秒
 ************************************************************************/

#include<iostream>
#include <limits> // 为了使用numeric_limits
#define MAX 512
using namespace std;

typedef struct Node {
    char data ;
    struct Node * Lchild ;
    struct Node * Rchild ;
} BiNode ,*BiTree ; //感觉主要是树上的BiTree复杂了

void CreteBitree(BiTree *root)  
{
    char ch ;
    //cin >> ch ;
    scanf("%c",&ch);
    if( ch == '#' ) 
        *root= NULL;
    else {
        cout  << ch << endl ;
        *root = (BiTree)malloc(sizeof(BiNode));
        (*root)->data = ch;
        CreteBitree(&(*root)->Lchild);
        CreteBitree(&(*root)->Rchild);
    }
}

/*BiTree CreteBitree()  
{
    BiNode *p;
    char ch ;
    cin >> ch ;
    if(ch  == '^') 
        return NULL;
    else {
        cout  << ch << endl ;
        p= (BiNode *)malloc(sizeof(BiNode));
        p->data = ch  ;
        p->Lchild=CreteBitree();
        p->Rchild=CreteBitree();
    }
    return p; //p is root 
}*/

void InOrder(BiTree root) //BiTree 就是 BiNode*    中序遍历
{
    if(root)
    {
        InOrder(root->Lchild);
        cout << root->data ;
        InOrder(root->Rchild);
    }
}

int main(void)
{
    BiTree root;
    cout  << "Please input the  string :" << endl ;

    CreteBitree(&root);
//    root = CreteBitree();
    InOrder(root);
    cout << endl ;
    return 0;
}
