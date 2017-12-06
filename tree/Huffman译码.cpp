/*************************************************************************
	> File Name: huffman.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月18日 星期六 14时08分39秒
 ************************************************************************/
#include<iostream>
#include<string.h>
using namespace std;
//备注：数组一切以1 开始
#define N 30
#define M 2*N-1
typedef struct HtNode{
    int weight;
    int parent;
    int Lchild;
    int Rchild;
    char str ;
}HtNode;

typedef char *  HuffManCode[N+1];  //HuffManCode === char *[N+1]
HuffManCode hc ;

void select_1(HtNode ht[] ,int n,int *s1_p ,int *s2_p);
void print(HtNode ht[],int m);

void CreateHuffMan(HtNode *ht,int W[],int n,char *t)
{
    int m=2*n-1;   //总共有m个结构体数组
    for(int i=1;i<= n;++i)
        ht[i]={W[i],0,0,0,t[i]};
    for(int i=n+1; i<=m ; ++i )
        ht[i]={0,0,0,0,'\0'};
    int s1,s2 ;
    for(int i= n+1 ;i<= m;++i)
    {
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
    min = 2147483647 ;
    Next_min = 2147483647;
    *s1_p = *s2_p = 0;
    for(int i= 1 ;i<= n;++i)
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
}
void print(HtNode ht[],int m)
{
    printf("\t weight  parent Lchild Rchild\n");
    for(int i= 1 ;i<= m;++i){
        printf("\t%d  %d  %d  %d %c  \n",ht[i].weight,ht[i].parent ,ht[i].Lchild,ht[i].Rchild,ht[i].str);
    }
}
void encode(HtNode *ht,HuffManCode hc,int n) //n个叶子节点
{
    char *cd;
    int start;
    int c,p;
    cd = (char *)malloc(n*sizeof(char));
    cd[n-1]='\0';
    for(int i= 1;i<= n;++i) //循环所有的叶子节点
    {
        start = n-1;
        c = i ;  ///当前节点
        p = ht[i].parent ;  //p 是双亲
        while(p != 0)
        {
            --start ;
            if(ht[p].Lchild == c) cd[start]='0';
            else cd[start] = '1';
            c= p;
            p=ht[p].parent;
        }
        hc[i] =  (char *)malloc(sizeof(char)*(n-start)); //n-start 
        strcpy(hc[i],&cd[start]);
    }
    free(cd);
}



void deCode(HuffManCode hc,HtNode *ht,int n)   //译码
{
    cout << "111111" << endl ;
    int index ;
    for(int i= 1;i<= n;++i)  //遍历hc
    {
        index = 2*n-1 ; //从根节点开始
        //cout << "index == " << index << endl ;
        //cout << "hc[i] == " << hc[i] << endl ;
        for(int j= 0; hc[i][j]; ++j)
        {
        //cout << "hc[i][j] == " << hc[i][j] << endl ;
            if(hc[i][j] == '0'){
                index = ht[index].Lchild ;
            }
            else {
                index = ht[index].Rchild ;
            }
        }
        cout << ht[index].str << endl ;
    }
}


int main(void)
{
    HtNode HuffMan[M+1]={0};
    int W[N]={0};
    char t[N];
    int n;

    cout << "请输入有几种类型：" << endl ;
    cin >> n ;
    int j ;
    for(int i = 1; i<= n ;i++){
        cout <<  "输入所对应的频率 和 字符 ：" << endl;

        cin >> j ;
        W[i] = j ;

        cin >> t[i] ;
    }
    CreateHuffMan(HuffMan,W,n,t );
    print(HuffMan,2*n-1);

    encode(HuffMan,hc,n);
    deCode(hc,HuffMan,n);

    for(int i = 1;i<= n;++i)
        cout <<  W[i] << " : "<< hc[i] << endl;

    return 0;
}
