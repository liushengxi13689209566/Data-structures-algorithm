/*************************************************************************
	> File Name: Single_Number_III.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月12日 星期二 19时44分55秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
class temp{
    public:
    temp():number(0) ,count(0){} ; //初始化列表
    int  number ;
    int count  ;
};
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        const int size  = nums.size() / 2 + 1 ;  //假定全出现了 两次
        temp t[size] ;  //temp 的一个类，里面存放数值与出现的次数
        int k= 0   ;
        for(int i= 0 ;i !=  nums.size(); ++i  ){  // 1 

            cout << "num[i] == " << nums[i] << endl ;

            for(int j= 0 ;j != size ;++j ){     //出现两次

            cout << " nums[i] == " <<nums[i] << endl ;
            cout << "t[j].number == " << t[j].number << endl ;

                if( nums[i] == t[j].number ){
                    t[j].count++ ;
                    break;
                }
            }

            if(t[k].count == 0  ){
                t[k].number  =  nums[i];
                t[k].count++;
                k++;
            }
        }
        for(int j= 0 ;j != size ;++j ){
            cout << "t[j].number == " << t[j].number << endl ;
            cout << "t[j.count] == " << t[j].count << endl ;

        }

        vector<int> result ;
        for(int j= 0 ;j != size ; ++j ) {
            if(t[j].count  == 1 )
                result.push_back(t[j].number);
        }
        return result; 
    }
};
int main(void)
{
    Solution s ;
    vector<int> a={1,2,1,3,2,5};
    s.singleNumber(a);
}
