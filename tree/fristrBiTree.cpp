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
} BiNode ,*BiTree ;

//void CreteBitree(BiTree *root,char str[])  //那这个 root 最后指向了哪里呐？？root 是一个

BiTree CreteBitree(char str[])  
{
    BiNode *p;
        if(str[0]  == '^' ) 
            p= NULL;
        else {
            cout  << str[0] << endl ;
            p= (BiNode *)malloc(sizeof(BiNode));
            p->data = str[0] ;
            p->Lchild=CreteBitree(str+1);
            p->Rchild=CreteBitree(str+1);
        }
    return p; //p is root ptr  
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
    char str[MAX];
    cout  << "Please input the string :" << endl ;
    cin >> str;
    BiNode *root;
    root = CreteBitree(str);
//    root = CreteBitree();
    InOrder(root);
    cout << endl ;
    return 0;
}
