/*************************************************************************
	> File Name: KMP_algorithm.c
	> Author: 
	> Mail: 
	> Created Time: 2017年09月29日 星期五 14时27分44秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<iostream>
#define MAX 255 
using namespace std ;
typedef struct {
    int count ;
    char str[MAX];
}PP ;
int  BF(PP S ,PP T, int pos )  
{
    int i = pos;  // i 指向主串
    int j =  1;  // j 指向模式串
    while(i <= S.count  && j<= T.count)
    {
        if( S.str[i] == T.str[j]){
            i++ ;
            j++ ;
        }
        else {
            j= 1 ;
            i =  i-j + 2 ;
        }
    }
    if(j > T.count)
        return i-T.count;
    else 
        return 0;
}
int main(void)
{
    PP S,T ;
    S.str[0]=' ';
    T.str[0]=' ';
    cout <<  "请输入主串：" << endl ;
    scanf("%s",&S.str[1]);
    
    cout <<  "请输入模式匹配串：" << endl ;
    scanf("%s",&T.str[1]);

    S.count = strlen(S.str)-1;
    T.count = strlen(T.str)-1;
   
    printf("S.str==%s\n",S.str) ;
    printf("S.count ==%d\n",S.count);

    printf("T.str==%s\n",T.str);
    printf("T.count ==%d\n",T.count);

    int pos ;
    cout <<  "请输入模式匹配串要在主串的何处开始匹配查找 ：" << endl ;
    scanf("%d",&pos);  //判断 pos

    cout << BF(S,T,pos) << endl ;
}
