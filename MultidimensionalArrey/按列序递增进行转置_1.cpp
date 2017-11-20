/*************************************************************************
	> File Name: 按列序递增进行转置_1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月15日 星期三 21时17分34秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include<stdio.h>
#define MAX  1000
#define ROW   4
#define COL   6
typedef struct {
    int row ,col;
    int value ;
}Triple;
typedef struct {
    Triple data[MAX];  //三元组顺序表
    int rows,cols,nums; //rows 矩阵的总行数，cols 矩阵的总列数,nums 为整个矩阵非零元素的个数
}TSMatrix;

int getNumber(int  a[ROW][COL])
{
    int num = 0;
    for(int i= 0;i != ROW ;++i)
    {
        for(int j=0 ;j != COL ;++j)
            if(a[i][j])
                num++;
    }
    return num;
}
void print_array(TSMatrix T )
{
    for(int i=  0;i !=  T.nums ;++i)
    {
        cout << T.data[i].row << " " << T.data[i].col << " "<< T.data[i].value << endl;
    }
}
void TransposeTSMatrix_1(TSMatrix &A,TSMatrix &B)
{
    B.rows = A.rows;
    B.cols = A.cols;
    B.nums = A.nums;

    if( B.nums > 0 ){
        int k = 0;
        for(int i= 0 ;i != A.cols ;++i )  //A 有多少列，B 就有多少行
        {
            for(int j= 0;j != A.nums ;++j) //遍历A 三元组
            {
                if(A.data[j].col == i)
                {
                    B.data[k].row = A.data[j].col;
                    B.data[k].col = A.data[j].row;
                    B.data[k].value = A.data[j].value;
                    k++;
                }
            }
        }
    }
}
int main(void)
{
    int a[ROW][COL]={
        {3,0,0,0,0,0},
        {0,2,5,0,4,0},
        {5,0,8,1,2,0},
        {0,0,9,0,0,0}
    };
    TSMatrix A ;
    A.rows = ROW ;
    A.cols = COL ;
    cout << "getNumber == " << getNumber(a) << endl ;
    A.nums= getNumber(a);

    int k =  0 ;
    for(int i= 0;i< ROW ;++i)
    {
        for(int j=0;j< COL ;++j)
        {
            if(a[i][j] ){
                A.data[k].row = i ; //将矩阵保存在 A 这个三元组中,(三元组的规则是行序从小到大排列)
                A.data[k].col = j ;
                A.data[k].value = a[i][j];
                k++ ; 
            }
        }
    }
    cout << "转置前的三元顺序表是 ：" << endl;
    print_array(A);
    TSMatrix B;
    TransposeTSMatrix_1(A ,B); //转置后的三元组在 B 中,传A和B的引用过去
    cout << "转置后的三元顺序表是 ：" << endl;
    print_array(B);
    return 0;
}

