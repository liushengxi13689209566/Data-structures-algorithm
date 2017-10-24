/*************************************************************************
	> File Name: sparse_matrix.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月20日 星期五 14时59分30秒
 ************************************************************************/

#include<stdio.h>
#define MAX  1000
#define ROW   6
#define COL   6
#define ElementType  int 
typedef struct {
    int row ,col ;
    ElementType value ;
}Triple;
typedef struct {
    Triple data[MAX+1];
    int rows,cols,nums;
}TSMatrix;

void Fast_TransposeTSMatrix(TSMatrix *A ,TSMatrix *B)
{
    int num[MAX],position[MAX];
    B->rows=A->cols ;
    B->cols = A->rows;
    B->nums = A->nums ;
    if(B->nums){
        for(col=1;col<A.cols ;col++)
            num[col]=0;
        for(t=1;t<= A->len;t++)
            num[A->data[t].col]++;
        position[1]= 1;
        for(col=2;col<=A.n;col++)
            position[col]= position[col-1]+num[col-1];
        for(p=1;p<= A->nums;p++){
            col =A->data[p].col;
            q=position[col];
            B->data[q].row=A->data[p].col;
            B->data[q].col =A->data[p].col;
            B->data[q].value =A->data[p].value;
            position[col]++;
        }
    }
}
int print_array(TSMatrix *B)
{

}
int main(void)
{
    int a[ROW][COL]={
        {3,0,0,0,0,0},
        {0,2,5,0,0,0},
        {5,0,0,1,2,0},
        {0,0,0,0,0,0},
        {0,1,0,0,1,0},
        {1,0,0,0,9,3}
    };
    TSMatrix A ,B;
    int i ,j;
    int k = 1;
    for(i=  0;i<ROW ;i++)
    {
        for(j=0;j< COL ;j++)
        {
            if(a[i][j] != 0){
                A.data[k].row = i ;
                A.data[k].col = j ;
                A.data[k].value = a[i][j];
            }
        }
    }
    Fast_TransposeTSMatrix(&A ,&B);
    print_array(B);
    return 0;
}
