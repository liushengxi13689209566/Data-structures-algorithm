/*************************************************************************
	> File Name: First_Missing_Positive.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月28日 星期日 10时22分26秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
/* 题目描述 ：
给定一个未分类的整数数组，找到第一个缺少的正整数 。 

例如，
给定[1,2,0]返回3，
给定 [3,4,-1,1]返回2。

你的算法应该在O（n）时间运行，并使用恒定的空间。 */
/*题解： 首先搞懂什么是正整数，即 >0 的数 */
//typedef map<int,bool,less<int> >  mmid ; 
//less<unsigned> 按从小到大的顺序排列
//[0,2,2,1,1]   还有重复的数字
class Solution{
public:
    int firstMissingPositive(vector<int>& nums) {
		if(nums.size() == 0 ) return 1;
		sort(nums.begin(),nums.end()); //排序，除去负数和0 
		unsigned count = 1 ;
		for(int i= 0 ;i < nums.size() ;++i ){
			if(nums[i] > 0 ){
				if( nums[i] != count  )  
			 		return count ;
				if(nums[i+1] != count )
					count++ ;
			}
		}
		return count ;	
    }
};
/* 大神代码：
Put each number in its right place.

For example:

When we find 5, then swap it with A[4].

At last, the first place where its number is not right, return the place + 1.

class Solution
{
public:
    int firstMissingPositive(int A[], int n)
    {
        for(int i = 0; i < n; ++ i)
            while(A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i])
                swap(A[i], A[A[i] - 1]);
        
        for(int i = 0; i < n; ++ i)
            if(A[i] != i + 1)
                return i + 1;
        
        return n + 1;
    }
}; */
