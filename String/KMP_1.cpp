/*************************************************************************
	> File Name: KMP_algorithm.c
	> Author: 
	> Mail: 
	> Created Time: 2017年09月29日 星期五 14时27分44秒
 ************************************************************************/

#include<stdio.h>
#include<iostream>
#define MAX 255 
using namespace std ;

// 原则：移动位数 = 已匹配的字符数 - 对应的部分匹配值
void get_next(char *T , int *next) 
{
    int i , j;
    i= 1;  // 表示后缀
    j= 0;  // 表示前缀
    next[1]= 0;
    while(i < T[0])
    {
        if(j== 0 || T[i] == T[j]){
            i++;
            j++;
            next[i] = j;
        }
        else {
        //j 回溯,关键点
            j=next[j];
        }
    }
}

// 返回字串T 在主串S中的位置，不存在返回 0 


int  index_kmp(char *S ,char *T )  
{
    int i = 2 ; 
    int j =  1;
    int  next[MAX] ;

    get_next(T,next);

    while(i <= S[0]  && j<= T[0])
    {
        if( j ==  0 && S[i] == T[j]){
            i++ ;
            j++ ;
        }
        else {
            j=next[j];
        }
    }
    if(j > T[0] ){
        return i-T[0];
    }
    else 
        return 0;
}
//前缀是固定的，二后缀是相对的
int main(void)
{
    char  S[MAX];
    char T[MAX] ;
    cout <<  "请输入主串：" << endl ;
    cin >> S ;
    cout <<  "请输入模式匹配串：" << endl ;
    cin >> T ;
   
    cout << index_kmp(S,T) << endl ;
  
}
