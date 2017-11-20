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
int  PreOrder(BiNode *root)    //  先序遍历
{
    int num = 0;
    if(root)
    {
        if(root->Lchild && root->Rchild)
            num++;
        cout << root->data  <<"  " ;
        PreOrder(root->Lchild);
        PreOrder(root->Rchild);
    }
    return num+1;
}


int main(void)
{
    BiNode *root;
    cout  << "Please input the  string :" << endl ;

    CreteBitree(&root);
    cout<< "叶子节点树为：" << PreOrder(root)  << endl ; 
    return 0;
}
