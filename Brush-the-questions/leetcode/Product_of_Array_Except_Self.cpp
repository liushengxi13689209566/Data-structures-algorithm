/*************************************************************************
	> File Name: Product_of_Array_Except_Self.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月07日 星期四 23时46分37秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
/*
给定的阵列Ñ整数其中Ñ > 1， nums，返回一个数组output，使得output[i]等于所有元素的乘积nums除nums[i]。

解决它没有分裂和O（n）。

例如，给定[1,2,3,4]，返回[24,12,8,6]。

跟进：
你能解决它恒定的空间复杂性？（注意：为了空间复杂度分析的目的，输出数组不计为额外的空间。）
*/

/*解题思路：
* */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sum = 1 ;
        vector<int> result ;
        for(auto i=nums.begin() ;i != nums.end(); ++i){ //nums[0,0]
            sum =  1;
            for(auto j=nums.begin() ;j != nums.end(); ++j){
                //cout << "(*i,*j)" << *i << *j << endl ;
                if( j== i)    continue; //除过自己本身
                //cout << "(*i,*j)" << *i << *j << endl ;
                if((*j) == 0  ){ //特判0 的情况
                    sum = 0;
                    break;
                }
                sum *= (*j);
            }
            //cout << "sum == "  << sum << endl ;
            if(sum == 0 ) 
                result.push_back(0);
            else 
                result.push_back(sum);
        }
    return result ;
    }
};
int main(void)
{
    Solution s;
    vector<int> t={0,0};
    s.productExceptSelf(t);
}
