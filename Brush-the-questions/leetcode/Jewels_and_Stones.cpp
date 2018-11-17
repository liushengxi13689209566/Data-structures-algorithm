/*************************************************************************
	> File Name: Jewels_and_Stones.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月29日 星期四 21时44分34秒
 ************************************************************************/
/*题目描述：
* 你得到的字符串 J 代表的是宝石的类型，S代表你拥有的石头。S中的每个字符都是你拥有的一种石头。你想知道你有多少石头也是珠宝 ？。
j中的字母是有保证的，j和s中的字符都是字母。字母是区分大小写的，所以“A”被视为“A”的不同类型的石头。
例1：
输入：J =“aA”=“aaabbbb”
输出：3
例2：
输入：J =“Z”=“ZZ”
输出：0
注:
s和j由字母组成，长度最多为50。
j中的字符是明显的。*/
#include<iostream>
#include<string>
using namespace std ;
class Solution {
public:
    int numJewelsInStones(string J, string S) {
		int temp[10000] ={0};
		int count= 0 ; 
		for(auto i:J)
			temp[i] = 1  ;
		for(auto j:S){
			if(temp[j] == 1 )
				count++;
		}
	    return count ;
        
    }
};

int main(void){
    Solution SS ;
    string test1 ,test2 ;
    cin >> test1 >> test2 ;
    SS.numJewelsInStones(test1,test2);
    
}

