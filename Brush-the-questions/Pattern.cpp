/*************************************************************************
	> File Name: Pattern.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月06日 星期三 12时59分48秒
 ************************************************************************/
/*
* 给定一个n个整数序列a 1，a 2，...，a n，a 132模式是一个子序列a i，a j，a k，使得i < j < k且a i <a k <a j。设计一个算法，将n个数字列表作为输入，并检查列表中是否有132个模式。

注意： n将小于15,000。

例1：
输入： [1，2，3，4] 输出：错误说明：序列中没有132模式。


例2：
输入： [ 3，1，4，2 ] 输出：真说明：序列中有一个132模式：[1,4,2]。


例3：
输入： [-1,3,2,0] 输出：真说明：序列中有三个132个模式：[-1,3,2]，[-1,3,0]和[-1,2， 0]。
*/

//嗯～，的却很高超，需要改变习惯，不一定非要从数组的头开始遍历啊！！！！记得转换思维
//
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution{
    public:
    bool find132pattern(vector<int>& nums) {
        int s3 = INT_MIN ;
        stack<int> st;
        for( int i = nums.size()-1; i >= 0; i -- ){
            if( nums[i] < s3 ) return true;   //s3 存了大值后面的最后一个数字，那么这里就会比较前后两个数值的关系
            else while( !st.empty() && nums[i] > st.top() ){ 
                s3 = st.top(); 
                st.pop(); 
            }  //大的值会把栈压空！！
            st.push(nums[i]);
        }
        return false;
    }
};

/*class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size() == 0 ) 
            return false ;

        int min = nums[0]  ;
        int tag = 0 ;

        for(auto i= 1 ; i != nums.size(); ++i){    
            if( nums[i] <  min ){
                tag = i ;
                min = nums[i];
            }  //记录最小值的下标与数值   
        }
        cout << "tag  == " << tag  << endl;
        cout << "min  == " << min  << endl;
        cout << "size   == " << nums.size()  << endl;
        for(int i= tag+1 ;i != nums.size() ;++i){
            for(int j = i ;j != nums.size();++j){
                    cout << "nums[i] == " << nums[i] << endl ;
                    cout << "nums[j] == " << nums[j] << endl ;
                if(nums[i] > min && nums[j] > min && nums[j] < nums[i] )
                {
                    return true ;
                }
            }
        }
        return false ;
    }
};*/
int main(void)
{
    Solution s;
    vector<int> temp={3,5,0,3,4};
    s.find132pattern(temp);
}
