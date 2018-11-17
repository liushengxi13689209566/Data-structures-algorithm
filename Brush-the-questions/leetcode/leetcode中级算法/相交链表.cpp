/*************************************************************************
	> File Name: 相交链表.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2018年08月20日 星期一 23时29分19秒
 ************************************************************************/
/*编写一个程序，找到两个单链表相交的起始节点。

 

例如，下面的两个链表：

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
在节点 c1 开始相交。

注意：

1.如果两个链表没有交点，返回 null
2.在返回结果后，两个链表仍须保持原有的结构。
3.可假定整个链表结构中没有循环。
4.程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
*/
#include <iostream>
using namespace std;
/**
Definition for singly-linked list.*/
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
  public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
		int num1 = 0, num2 = 0;
		ListNode *p1, *p2;
		int i;
		for (p1 = headA; p1; p1 = p1->next)
			num1++;
		for (p2 = headB; p2; p2 = p2->next)
			num2++;
		if (num1 == 0 || num2 == 0)
			return nullptr;
		p1 = headA;
		p2 = headB;
		if (num1 > num2)
		{
			for (i = 0; i < num1 - num2; p1 = p1->next, i++)
				;
		}
		else if (num1 < num2)
		{
			for (i = 0; i < num2 - num1; p2 = p2->next, i++)
				;
		}

		for (; p1 && p2; p1 = p1->next, p2 = p2->next)
		{
			if (p1->val == p2->val)
				return p1;
		}
		return nullptr;
	}
};
