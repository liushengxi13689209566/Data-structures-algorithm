/*************************************************************************
	> File Name: 1.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月12日 星期四 17时58分46秒
 ************************************************************************/

/*问题描述： 
给你两个数组（没有重复） nums1，nums2其中nums1的元素是子集nums2。找到所有下一个更大的数字nums1在相应的地方的元素nums2。

一个号码的下更大数量的X中nums1是其在右侧的第一个较大的数目nums2。如果不存在，则为该数字输出-1。

示例1：
输入： nums1 = [4,1,2]，nums2 = [1,3,4,2]。
输出： [-1,3，-1]
 说明：
    对于第一个数组中的数字4，在第二个数组中找不到下一个较大的数字，因此输出-1。
    对于第一个数组中的数字1，第二个数组中的第二个数字为3。
    对于第一个数组中的数字2，第二个数组中没有下一个较大的数字，因此输出-1。
示例2：
输入： nums1 = [2,4]，nums2 = [1,2,3,4]。
输出： [3，-1]
 说明：
    对于第一个数组中的第2个，第二个数组中的第二个数字为3。
    对于第一个数组中的第4个，第二个数组中没有下一个较大的数字，因此输出-1。
注意：
在所有的元素nums1和nums2是唯一的。
两者的长度nums1和nums2不超过1000。*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* findNums, int findNumsSize, int* nums, int numsSize, int* returnSize) {
    int i, j ,k = 0 ;
    bool find =false ;
    int* returnArray = NULL;
    *returnSize = findNumsSize ;  //注意事项！！！！！
    returnArray = (int *)malloc((*returnSize) * sizeof(int));
    for(i= 0 ;i< findNumsSize ;i++)  //循环子集
    {
        find = false ;
        for(j= 0;j< numsSize;j++)    //循环大的这个集合
        {
            if(*(nums+j) == *(findNums+i))  //找到该元素
                find =  true ;
            if(find && (*(nums+j) > *(findNums + i)))
            { 
                *(returnArray + k++ ) = *(nums+j);
                break;
            }
            if( j == numsSize-1 )       //一个元素已经找完
                *(returnArray + k++) =  -1  ;
        }
    }
    return returnArray;
}



