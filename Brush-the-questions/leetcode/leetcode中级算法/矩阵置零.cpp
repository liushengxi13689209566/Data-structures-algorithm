/*************************************************************************
	> File Name: 矩阵置零.cpp
	> Author: Liu Shengxi
	> Mail: 13689209566@163.com
	> Created Time: 2018年07月17日 星期二 11时12分26秒
 ************************************************************************/
/* 矩阵置零
给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。

示例 1:

输入:
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
输出:
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
示例 2:

输入:
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
输出:
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
进阶:

一个直接的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
你能想出一个常数空间的解决方案吗？*/
#include<iostream>
#include<vector>
#include<set>
using namespace std ;
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int tag  ;
		vector<int> v(matrix[0].size(), 0);
		set<int> intSet ;
		for (int i = 0; i !=  matrix.size() ; ++i )   // 行
		{
			tag = 0 ;
			for ( int j = 0  ; j != matrix[0].size() ; j++)  // 列
			{
				if ( matrix[i][j] == 0 ) {
					tag = 1 ; //说明该行出现了0元素
					intSet.insert(j);
				}
			}
			if (tag)		matrix[i] = v ;//将整个一行置零
		}

		//将整个一列置零
		set<int>::iterator it = intSet.begin();
		for ( ; it != intSet.end() ; ++it )
		{
			for (int k = 0 ; k != matrix.size() ; ++k )
			{
				matrix[k][*it] = 0 ;
			}
		}

		for (int i = 0; i < matrix.size() ; ++i )
		{
			for ( std::vector<int>::iterator  it = matrix[i].begin() ; it != matrix[i].end() ; it++)
			{
				cout << *it << "  " ;
			}
			cout << endl ;
		}
	}
};



