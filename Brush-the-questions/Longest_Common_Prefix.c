/*************************************************************************
	> File Name: Longest_Common_Prefix.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月11日 星期三 14时08分22秒
 ************************************************************************/
 /*题目描述：
  Write a function to find the longest common prefix string amongst an array of strings.*/
  /*解题思路：
  * 这是一个二维的字符数组，如果求公共前缀字符串，那么必然在最短的一个里面找。
  * 遍历它，然后与其他字符串进行比较，不同时，给最短的字符串加上\0 返回即可   */
 //a[i] =>*(a+i)     a[i][j] =>  *(*(a+i)+j)  
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char* longestCommonPrefix(char strs[3][12], int strsSize) {    // strs 必须是malloc之后产生的 
    int  *a;
    a=(int *)malloc(sizeof(int)*strsSize);
    int i ,j= 0 ,t ,k ; 
    for(i=0;i<strsSize ;i++ )
        a[j]=strlen(*(strs+i));  //int 数组保存对应字符串的长短
    int min=a[0];
    for(i= 1;i< strsSize ;i++){
        if(min > a[i]) {
            t= i ;   //t 就是最小字符串的下标
            min= a[i];
        }
    }
    for(i= 0; *(*(strs+t)+i) ; i++){       //遍历最小字符串
        for(j= 0 ;j< strsSize ;j++){   //遍历所有的字符串
                if(strs[j][i] != strs[t][i]){
                    strs[t][i]='\0';
                    break;
                }
             //跳过自身
            //一有不同就停止,给最小字符串给个\0 即可
        }
    }
    free(a);
    return strs[t];
}
int main(void)
{
    char strs[3][12]={
        "abcmjbdef",
        "abcdefvnrv",
        "abcdefhgewcv"
    };
    char *temp;
    temp =longestCommonPrefix(strs,3);
    printf("the result is %s \n",temp);
    return 0;


}
