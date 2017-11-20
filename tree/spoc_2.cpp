#include<iostream>
using namespace std;

typedef struct Node {
    char data ;
    struct Node * Lchild ;
    struct Node * Rchild ;
} BiNode ;

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
void  change(BiNode *root)    //  先序遍历
{
    BiNode *temp ;
    if(root)
    {
        temp= root->Lchild;
        root->Lchild =root->Rchild;
        root->Rchild = temp ;
        //cout << root->data  <<"  " ;
        change(root->Lchild);
        change(root->Rchild);
    }
}

void PreOrder(BiNode *root)    //  先序遍历
{
    if(root)
    {
        cout << root->data  <<"  " ;
        PreOrder(root->Lchild);
        PreOrder(root->Rchild);
    }
}


int main(void)
{
    BiNode *root;
    cout  << "Please input the  string :" << endl ;

    CreteBitree(&root);
    cout << "PS : 都是先序遍历的------交换节点之前：" << endl ;
    PreOrder(root) ;
    cout << endl ;
    change(root);
    cout << "交换节点之后：" << endl ;
    PreOrder(root);
    cout << endl ;
    return 0;
}
