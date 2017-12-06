/*************************************************************************
	> File Name: huffman.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月18日 星期六 14时08分39秒
 ************************************************************************/
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

#define N  128  //常用字符128 
#define M  2*N-1
//数组从零开始
typedef struct HtNode{
    int weight;
    int parent;
    int Lchild;
    int Rchild;
    char str ; //叶子节点保存原始字符
}HtNode;

typedef struct {
    int W[N] ;       //用来统计各个字符的权值
    char ch[N] ;      //用来保存字符
    int typeNumber ;  //有多少种字符就会开辟多大的结构体数组啊
}TT ;
int n ;

typedef char *  HuffManCode[N+1];  //HuffManCode === char *[N+1]
HuffManCode hc ;

void select_1(HtNode ht[] ,int n,int *s1_p ,int *s2_p);
void print(HtNode ht[],int m);

void CreateHuffMan(HtNode *ht,TT t) 
{
    int m=2*n-1; //总共有m个结构体数组
    for(int i= 0;i< n;++i)
        ht[i]={t.W[i],0,0,0,t.ch[i]};
    for(int i= n ; i< m ; ++i )
        ht[i]={0,0,0,0,'\0'};
    print(ht,m);
    int s1,s2 ;
    for(int i= n  ;i<  m;++i)
    {
        select_1(ht,i ,&s1,&s2);
        ht[i].weight = ht[s1].weight + ht[s2].weight;
        ht[i].Lchild = s1 ;
        ht[i].Rchild = s2 ;
        ht[s1].parent = i ;
        ht[s2].parent = i;
    print(ht,m);
    }
}
void select_1(HtNode ht[] ,int n,int *s1_p ,int *s2_p) //考虑平率重复的情况
{
    int min  ; //最小值
    int Next_min  ; //次小值
    min = 2147483647 ;
    Next_min = 2147483647;
    *s1_p = *s2_p = 0;
    for(int i= 0  ;i<  n;++i)
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
    printf("\t weight  parent Lchild Rchild   str \n");
    for(int i=  0 ;i< m;++i){
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
    for(int i=  0;i<  n;++i) //循环所有的叶子节点
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

void deCode(char *yimaStr,HtNode *ht,int n)   //译码
{
    //cout << "111111" << endl ;
    int index = 2*n-2 ;
    int tag = 0 ;
    for(int i= 0 ; yimaStr[i] ; ++i)  //遍历
    {
        if(tag ==  1)
            index = 2*n-2 ; //从根节点开始

        if(yimaStr[i] == '0'){
                index = ht[index].Lchild ;
        }
        else {
            index = ht[index].Rchild ;
        }
        if(ht[index].Lchild == 0 && ht[index].Rchild == 0  )
        {   
             cout << ht[index].str << "  " ;
             tag = 1;
        }
        else tag = 0 ;
    }
    cout << endl ;
}

int main(void)
{
    HtNode HuffMan[M+1]={0};
    FILE *fp ;
    fp=fopen("test","r");
    if( !fp) {
        printf("\t\t\t 打开文件失败哦 \n");
        return -1;
    }
    char temp[N];
    TT t ;
    memset(&temp,0,sizeof(temp));
    memset(&t,0,sizeof(TT));   //初始化用来统计文件中字符的各种变量
    while(fread(temp,1,sizeof(temp),fp) != 0 )  //一直读取完字符
    {
        printf("temp == %s \n",temp);
        //printf("555555555555555555\n") ;
        for(int i = 0 ;temp[i] != '\0'; ++i){
            t.ch[temp[i]-'0'] = temp[i];
            t.W[temp[i]-'0']++ ;   //统计各个字符出现频率
        }
    }
    printf("88888888888888888\n");
    for(int i= 0; i < N ;++i){
        if(t.W[i] != 0 )
            t.typeNumber++;
    }
    n = t.typeNumber-1 ;   //这是为什么呐？？

    TT result;

    printf("n  == %d \n",n);
    int j = 0;
    for(int i= 0; i < N ;++i){
        if(t.W[i] == 0 ) continue;
        result.W[j]= t.W[i];
        result.ch[j]= t.ch[i];
        //printf("t.W[%d] == %d    ",i,t.W[i]);
        //printf("t.ch[%d] == %c \n",i,t.ch[i]);
        j++;
    }
    for(int i= 0; i < n ;++i){
        printf("temp.W[%d] == %d    ",i,result.W[i]);
        printf("temp.ch[%d] == %c \n",i,result.ch[i]);

    }
    

    CreateHuffMan(HuffMan,result);

    print(HuffMan,2*n-1);

    encode(HuffMan,hc,n);

    for(int i = 0; i<  n;++i)
        cout <<    " : " << hc[i] << endl;
    cout << "\t\t\t 是否使用译码功能 (Y/N) ："   << endl;
    char a;
    cin >> a ;
    char yimaStr[N] ;
    if(a == 'y' || a== 'Y' ){
     cout << "\t\t\t 请输入译码字符串 ："    << endl ;
        cin >> yimaStr ;
        deCode(yimaStr,HuffMan,n);
    }
    else
        fclose(fp);
    return 0;
}
