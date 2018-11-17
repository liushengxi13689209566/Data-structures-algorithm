/*************************************************************************
	> File Name: Merge_Two_Sorted_Lists.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月17日 星期六 17时48分31秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*题目描述：
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if( !l1 && !l2  )
            return NULL ;
		ListNode *temp1,*temp2 ;
        
		temp1 = l1 ;
		temp2 = l2 ;
		ListNode *tmp ,*head ;
        if( l1 || l2  ){
            if( !l1 )    head = l2 ;
            else if( !l2 )  head = l1 ;
		    else  head = (l1->val <= l2->val )? l1 : l2 ;
        }
        // cout << "head->val == " << head->val << endl;
        while( temp1->next && temp2->next ){
			if(temp1->val <= temp2->val ){
				tmp = temp1->next ;
                if(tmp->val > temp2->val ){
				    temp1->next = temp2 ;
                }
				temp1= tmp ;
			}
			else if(temp2->val < temp1->val){
				tmp = temp2->next ;
                if(tmp->val > temp1->val ){
				    temp2->next = temp1 ;
                }
				temp2= tmp   ;
			}
		}
		// while(temp1){
		// 	temp2->next = temp1;
		// }
		// while( temp2){
		// 	temp1->next = temp2 ;
		// }
		return head;
    }
};

