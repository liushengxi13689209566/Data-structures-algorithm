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
void  get_next(PP T , int *next) 
{
    int after , front;
    after= 1;  // 表示后缀
    front= 0;  // 表示前缀
    next[1]= 0;
    while(after <= T.count )
    {
        if( front== 0 || T.str[after] == T.str[front]){
            after++;
            front++;
            next[after] = front;
        }
        else {
        //front 回溯,关键点
            front=next[front];
        }
    }
}
// 返回字串T 在主串S中的位置，不存在返回 0 
int  index_kmp(PP S ,PP T, int pos )  
{
    int i = pos;
    int j =  1;
    int  next[MAX] ;

    get_next(T,next);

    /*for(int  i= 1;i<= T.count ; ++i)
        printf("next[%d] ==%d\n",i,next[i]);*/
    // next 是数组正确

    while(i <= S.count  && j<= T.count)
    {
        if( j ==  0 ||  S.str[i] == T.str[j]){
            i++ ;
            j++ ;
        }
        else {
            j=next[j];
        }
    }
    if(j > T.count)
        return i-T.count;
    else 
        return 0;
}
//前缀是固定的，二后缀是相对的
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
    scanf("%d",&pos);
    cout << index_kmp(S,T,pos) << endl ;

}
