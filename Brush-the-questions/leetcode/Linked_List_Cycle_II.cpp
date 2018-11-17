/*************************************************************************
	> File Name: Linked_List_Cycle_II.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月14日 星期三 21时55分45秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*题目描述：
* 给定一个链表，返回循环开始的节点。如果没有循环，则返回null。

注意：不要修改链接列表。

跟进：
你可以解决它没有使用额外的空间？*/
/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?*/




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
    ListNode *detectCycle(ListNode *head) { 
		if(head == NULL )
			return NULL ;
		ListNode *quick ,*slow;
		quick = head ;
        slow =  head ;
		bool  tag = false ;
		while(quick && quick->next ){ //注意判断条件
			slow = slow->next;
			quick = quick->next->next ; //考虑quick->next 为 NULL 的情况

			if(slow == quick ){
				tag = true ;
				break ;
			}
		}
		if(tag == false )
			return NULL ; 
		for(ListNode *fast = head ; ;){
			if(fast == slow )
				return fast ;
			fast = fast->next  ;
			slow = slow->next ;
		}
    }
};


