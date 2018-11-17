/*************************************************************************
	> File Name: Reverse_Vowels_of_a_String.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年04月03日 星期二 17时31分38秒
 ************************************************************************/
#include<iostream>
#include<vector>
#include<string>
using namespace std ;
/*题目描述：
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Note:
The vowels does not include the letter "y".
*/
class Solution {
public:
    string reverseVowels( string s){
		int temp = s.size() ; 
		char tt ; //leetcode 
        for(int i = 0 ,j = temp-1 ;  i <  j  ;  ){    // i 在前，j 在后面	
			if( s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'||
			s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' ) {
				while(1){
					if( s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u' ||
					s[j] == 'A' || s[j] == 'E' || s[j] == 'I' || s[j] == 'O' || s[j] == 'U' ) {
						tt = s[i];
						s[i] = s[j] ;
						s[j] = tt ;
                        j-- ;
						i++ ;
                        break ;
					}
					else 
                        j-- ; 
				}
			}
			else 
				i++ ;
    	}
		return s ;
    }
};
int main(void){
	Solution ss ;
	string test ;
	cin >> test ;
	cout << ss.reverseVowels(test)<< endl ; 
	return  0;
}

