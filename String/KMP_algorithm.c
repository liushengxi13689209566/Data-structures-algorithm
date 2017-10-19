/*************************************************************************
	> File Name: KMP_algorithm.c
	> Author: 
	> Mail: 
	> Created Time: 2017年09月29日 星期五 14时27分44秒
 ************************************************************************/

#include<stdio.h>
// 原则：移动位数 = 已匹配的字符数 - 对应的部分匹配值
int match_table[25];   //存放部分匹配表

int main(void)
{
    char Parent_str[125];
    char Search_str[25];
    printf("please input the Parent_str \n");
    scanf("%s",Parent_str);
    printf("Please input the search_str \n");
    scanf("%s",search_str);

    calute(Search_str); //计算出部分匹配表

    for(i= 0 ,j= 0;Parent_str[i] ; )
    {
        if(Parent_str[i] ==  Search_str[j] )
        {
            i++ ;
            j++ ;
        }

    

    }




}

