/*************************************************************************
	> File Name: 链表中倒数第k个结点.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  7/31 08:59:56 2019
 ************************************************************************/

#include <iostream>
using namespace std;
/*
输入一个链表，输出该链表中倒数第k个结点。
*/
/*
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution
{
public:
	ListNode *FindKthToTail(ListNode *pListHead, unsigned int k)
	{
		if (!pListHead)
			return nullptr;
		unsigned int count = 0;
		ListNode *ptr = pListHead;
		while (ptr)
		{
			count++;
			ptr = ptr->next;
		}
		ListNode *p = pListHead;
		int len = count - k;
		// count  =10  k =10000
		if (len < 0)
			return nullptr;
		for (int i = 0; i < len; i++)
		{
			p = p->next;
		}
		return p;
	}
};