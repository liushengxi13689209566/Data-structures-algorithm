/*************************************************************************
	> File Name: 三角形最小路径和.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2019年02月15日 星期五 12时37分25秒
 ************************************************************************/

#include<iostream>
using namespace std;
例如，给定三角形：

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

说明：

如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。
class Solution {
public:
    //三角形的形状是固定的
    int minimumTotal(vector<vector<int>>& tri) {
        
        int row = tri.size();
        if(row  <= 0 )
            return 0;
        
        if(row == 1) //一行　
            return tri[0][0];
        
        for(int i = row-2 ;i >= 0 ; i--){
            
             for(int j= 0;j<= i;j++){
                 
                 tri[i][j] = min(tri[i][j] + tri[i+1][j],tri[i][j]+tri[i+1][j+1]);
             }
        }
        return tri[0][0]; 
    }

};
