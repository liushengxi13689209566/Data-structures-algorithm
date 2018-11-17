/*************************************************************************
	> File Name: Best_Time_to_Buy_and_Sell_Stock.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月17日 星期六 22时26分05秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*题目描述：
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction 
(ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.*/
class Solution {
public:
    int maxProfit(vector<int>& prices){
		int min_number =  INT_MAX ;
		int max_number = 0 ;
		for(int i = 0 ;i < prices.size() ;++i ){
			min_number = min(min_number,prices[i]) ;
			max_number = max(max_number,prices[i]- min_number);
		}
		return max_number ;
    }
};

