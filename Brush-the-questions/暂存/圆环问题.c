/*************************************************************************
	> File Name: 圆环问题.c
	> Author: Linuxer_liu
	> Mail: 
	> Created Time: 2017年08月01日 星期二 20时34分19秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
int  n ; 
int M = 0 ;
int visted[1000]; //标记数组
int a[50] ;  //存储路径
int sushu(int t)
{
    int i ;
    for(i= 2 ;i< t ;i++)
    {
        if(!(t%i))
        break;
    }
    if(i  ==  t)  return 1; //是素数
    else   return 0 ;//不是素数
}
int check(int x ,int  xx) //xx 表示下一个数 ，x 表示是当前数
{
    if( !(x%2)  && !(xx%2)) //排除同奇同偶的情况
        return 0;
    if( (x%2)  && (xx%2))
        return 0;
    if(!(sushu(x + xx)))  //判断相加是不是素数
       return 0 ;
    if(visted[xx])
        return 0;
    return 1;
}
int dfs(int x,int step)
{
    int i  ;
    if( (step ==  n + 1) && (sushu(a[1]+ a[n])))
    {
        printf("Case %d:\n",++M);
        for(i= 1 ;i<= n ;i++)  //从这里开始输出，第一次见
           printf("%d ",a[i]);
        printf("\n");
    }
    for(i= 2 ;i<= n  ;i++)
    {
        if(check(x,i))
        {
            a[step]= i ;
            visted[i]= 1;
            dfs(i,step + 1);  //step 是步数
            visted[i] = 0  ;
        }
    }
    return 0;
}
int main(void)
{
    while(scanf("%d",&n) != EOF )
    {
        int i;
        memset(a,0,sizeof(a));
        memset(visted,0,sizeof(visted));
        visted[1]= 1; //默认第一步
        a[1] = 1;  
        dfs(1,2); //找第二步
    }
    return 0;
}
