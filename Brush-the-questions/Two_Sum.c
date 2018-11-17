/*************************************************************************
	> File Name: Two_Sum.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月10日 星期二 21时26分02秒
 ************************************************************************/

#include<stdio.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
###问题描述： 
####给定一个整数数组，返回两个数字的索引，使它们相加到一个特定的目标。

您可以假设每个输入都只有一个解决方案，而您可能不会使用相同的元素两次。

例：
给定nums = [2，7，11，15]，target = 9，

因为nums [ 0 ] + nums [ 1 ] = 2 + 7 = 9，
返回[ 0，1 ] 
int* twoSum(int* nums, int numsSize, int target) {
    int i,j;
    int *temp;
    temp=(int *)malloc(sizeof(int)*5);
    for(i=0;i<numsSize ;i++)    //慢一点
    {
        for(j= 0;j<numsSize ;j++)
        {
            if(i != j)   //避免重复
            {
                if((nums[i]+ nums[j]) == target )
                {
                    if(i< j)   
                    {
                        temp[0]=i ;  //比较一下，把小的放在前面，大的放在后面
                        temp[1]=j;
                    }  
                    else{
                        temp[0]=j ;
                        temp[1]=i;
                    }
                }
            }
        }
    }
    return temp;
}

