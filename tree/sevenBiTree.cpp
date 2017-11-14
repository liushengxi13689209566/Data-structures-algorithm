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
} BiNode ,*BiTree ; //感觉主要是树上的BiTree复杂了

void CreteBitree(BiTree *root)    
{
    char ch ;
    cin >> ch ;
    if( ch == '#' ) 
        *root = NULL;
    else {
        *root = (BiTree)malloc(sizeof(BiNode));
        (*root)->data = ch ;
        CreteBitree(&(*root)->Lchild);
        CreteBitree(&(*root)->Rchild);
    }
}
void PreOrder(BiTree root) //BiTree 就是 BiNode*    后序遍历
{
    if(root)
    {
        PreOrder(root->Lchild);
        PreOrder(root->Rchild);
        cout << root->data ;
    }
}
int main(void)
{
    BiTree root;
    cout  << "Please input the  string :" << endl ;

    CreteBitree(&root);
    cout<< "递归！！！后序遍历：" << endl ;
    PreOrder(root);
    cout << endl;
   
    return 0;
}
