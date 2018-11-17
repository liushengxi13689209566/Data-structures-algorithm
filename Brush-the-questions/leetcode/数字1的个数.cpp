/*************************************************************************
	> File Name: 数字1的个数.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2018年06月04日 星期一 23时07分50秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Solution {
public:
    int countDigitOne(int n) {
        if( n <= 0  )
            return 0 ;
        int count = 0 ;
        for( int i = 1 ;i<= n ;i++ ){ //solution with O(n^2) 
            auto str = to_string(i) ;
            for( auto i : str){
                if(i == '1')
                    count++ ;
            }
        }
    return count ;
    }
}; 

