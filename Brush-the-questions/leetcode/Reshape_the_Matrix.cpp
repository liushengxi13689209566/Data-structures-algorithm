/*************************************************************************
	> File Name: Reshape_the_Matrix.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月12日 星期五 22时52分44秒
 ************************************************************************/
/*题目描述：
 * 在MATLAB中，有一个非常有用的函数称为“reshape”，它可以将矩阵重新塑造成一个不同大小的新矩阵，但保留其原始数据。
给出一个由二维数组表示的矩阵，两个正整数r和c分别代表所需的整形矩阵的行号和列号。
重构后的矩阵需要以原始矩阵的所有元素按照相同的行遍数顺序填充。
如果给定参数的“重塑”操作可能合法，则输出新的重塑矩阵; 否则，输出原始矩阵。
例1：
输入：  
nums = 
[[1,2]，
 [3,4]] 
r = 1，c = 4 输出： 
[[1,2,3,4]] 说明： nums 的行遍历为[1,2 ，3,4]。新的重塑矩阵是一个1 * 4矩阵，
使用前面的列表逐行填充它。
例2：
输入：  
nums = 
[[1,2]，
 [3,4]] 
r = 2，c = 4 输出： 
[[1,2]，
 [3,4]] 说明：无法重构2 * 2矩阵到2 * 4矩阵。所以输出原始矩阵。
注意：
给定矩阵的高度和宽度在[1，100]的范围内。
给定的r和c都是正数。
*/

/* 笔记：
vec1.size() 就是”二维数组”的行数
vec1[0].size() 就是”二维数组”的列数 
此题就是对于vector 和二维数组的一些处理，没什么难度哦 */
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	// r 行  ，c 列
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
		if(r*c > nums.size()*nums[0].size())
			return nums ;
		else {
			vector<vector<int> >  temp(r) ;
			int col  = nums[0].size() ; //列
			int newindex = 0 ; 
			int count = 0 ;
			for(int i = 0 ;i < nums.size() ;++i)
       			for(int j= 0 ;j < col   ;++j){
            		//处理该二维数组
					temp[newindex].push_back(nums[i][j]);
					count++ ;
					if(count  == c  )
						newindex++ ,
                        count = 0 ;
				}
			return temp ;
		}
	}
};
/* 大神代码！！！！
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size(), n = nums[0].size(), o = m * n;
        if (r * c != o) return nums;
        vector<vector<int>> res(r, vector<int>(c, 0));
        for (int i = 0; i < o; i++) res[i / c][i % c] = nums[i / n][i % n];
        return res;
    }
}; */