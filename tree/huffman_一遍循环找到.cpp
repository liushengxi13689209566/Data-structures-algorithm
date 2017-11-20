/*************************************************************************
	> File Name: huffman.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月18日 星期六 14时08分39秒
 ************************************************************************/

#include<iostream>
using namespace std;
//备注：数组一切以1开始
#define N 30
#define M 2*N-1
typedef struct HtNode{
    int weight;
    int parent;
    int Lchild;
    int Rchild;
}HtNode;
void select_1(HtNode ht[] ,int n,int *s1_p ,int *s2_p);
void print(HtNode ht[],int m);

void CreateHuffMan(HtNode *ht,int W[],int n)
{
    int m=2*n-1;   //总共有m个结构体数组
    for(int i=1;i<= n;++i)
        ht[i]={W[i],0,0,0};
    for(int i=n+1; i<=m ; ++i )
        ht[i]={0,0,0,0};
    int s1,s2 ;

    print(ht,m);


    for(int i= n+1 ;i<= m;++i)
    {
        printf("1111111111\n");
        select_1(ht,i-1,&s1,&s2);
        ht[i].weight = ht[s1].weight + ht[s2].weight;
        ht[i].Lchild = s1 ;
        ht[i].Rchild = s2 ;
        ht[s1].parent = i ;
        ht[s2].parent = i;
    }
}

void select_1(HtNode ht[] ,int n,int *s1_p ,int *s2_p) //考虑平率重复的情况
{
    int min  ; //最小值
    int Next_min  ; //次小值
    /*if(ht[1].weight <= ht[2].weight ){
        min = ht[1].weight;
        *s1_p = 1;
        Next_min =ht[2].weight;
        *s2_p= 2;
    }
    else {
        Next_min  = ht[1].weight;
        *s2_p = 1;
        min =ht[2].weight;
        *s1_p= 2;
    }
    printf("min == %d Next_min == %d \n",min ,Next_min);
    for(int i= 3 ;i<= n;++i)
    {
        if(ht[i].parent == 0)
        {
            if(ht[i].weight < min )  
            {
                Next_min = min ;
                min= ht[i].weight;
                *s2_p = *s1_p;
                *s1_p = i;   //存储下标
            }
            else if(ht[i].weight <= Next_min )
            {
                Next_min = ht[i].weight;
                *s2_p = i;
            }
        }
    }
    printf("min == %d Next_min == %d \n",min,Next_min);
    printf("*s1_p == %d  *s2_p == %d \n",*s1_p,*s2_p);*/

}
void print(HtNode ht[],int m)
{
    printf("\t weight  parent Lchild Rchild\n");
    for(int i= 1 ;i<= m;++i){
        printf("\t%d  %d  %d  %d \n",ht[i].weight,ht[i].parent ,ht[i].Lchild,ht[i].Rchild);
    }
}
int main(void)
{
    HtNode HuffMan[M+1]={0};
    int W[N]={0};
    int n;
    cout << "请输入有几种类型：" << endl ;
    cin >> n ;
    int j ;
    for(int i = 1; i<= n ;i++){
        cout <<  "输入平率：" << endl;
        cin >> j ;
        W[i] = j ;
    }
    for(int i= 1;i<= n;++i)
        printf("W[%d]== %d \n",i,W[i]);
    CreateHuffMan(HuffMan,W,n);
    print(HuffMan,2*n-1);
    return 0;
}
