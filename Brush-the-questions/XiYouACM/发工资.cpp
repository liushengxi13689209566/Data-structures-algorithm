/*************************************************************************
	> File Name: 水果.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月30日 星期二 18时01分14秒
 ************************************************************************/
/* 题目描述：
作为杭电的老师，最盼望的日子就是每月的8号了，因为这一天是发工资的日子，养家糊口就靠它了，呵呵 
但是对于学校财务处的工作人员来说，这一天则是很忙碌的一天，财务处的小胡老师最近就在考虑一个问题：如果每个老师的工资额都知道，最少需要准备多少张人民币，才能在给每位老师发工资的时候都不用老师找零呢？ 
这里假设老师的工资都是正整数，单位元，人民币一共有100元、50元、10元、5元、2元和1元六种。 
Input
输入数据包含多个测试实例，每个测试实例的第一行是一个整数n（n<100），表示老师的人数，然后是n个老师的工资。 
n=0表示输入的结束，不做处理。 
Output
对于每个测试实例输出一个整数x,表示至少需要准备的人民币张数。每个输出占一行。 
Sample Input
3
1 2 3
0
Sample Output
4 */
#include<iostream>
#include<vector>
using namespace std ;
// fun 函数的目的就是找到多少张钱
vector<int> RMB{100,50,10,5,2,1} ; 

int fun(int temp ,vector<int>::const_iterator index ){   //542 RMB  N = 100 
// cout << temp << "888888 " << *index << endl; // 3 8888 2 
	int sum  =  0 ;
	while(temp){    // 542 
		sum += temp/(*index);
		temp %= *index ;
		index++;
	}
	// cout << sum << endl ;
	return sum ;
}
int main(void){
	int  n ,temp ,count  ;
	while(cin >> n){
		if(  !n  )	
			return 0 ; 
		count =  0 ;
		for(int i=0 ;i< n ;i++){
			cin >> temp ;
			if(temp > 100 )
				count += fun(temp , RMB.begin());
			else if(temp <= 100 && temp >= 50)
				count += fun(temp,RMB.begin()+1);
			else if(temp <= 50 && temp >= 10 )
				count += fun(temp,RMB.begin()+2);
			else if(temp <= 10 && temp >= 5 )
				count += fun(temp,RMB.begin()+3);
			else if(temp <= 5 && temp >= 2 )
				count += fun(temp,RMB.begin()+4);
			else 
				count += fun(temp,RMB.begin()+5);
		}
		cout << count << endl; 
	}
	return 0 ;
}

