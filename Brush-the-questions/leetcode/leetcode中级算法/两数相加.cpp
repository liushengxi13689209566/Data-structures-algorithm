/* 
给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。
你可以假设除了数字 0 之外，这两个数字都不会以零开头。
示例：
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807 */
/***/
#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <vector>
#include <sstream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *p1, *p2;
        int tag = 0;
        ListNode *head = new ListNode(-100);
        ListNode *rear = head ;
        rear->next = l1;
        for (p1 = l1, p2 = l2; p1 && p2; p1 = p1->next, p2 = p2->next)
        {
            p1->val = p1->val + p2->val + tag; //直接在某一个链表上进行操作既可
            rear = p1;
            if ((p1->val) >= 10)
                tag = 1;
            else
                tag = 0;
            p1->val = p1->val % 10;
        }
        if (!p1 && !p2 && tag)
        {
            pp = new ListNode(tag);
            Behindinsert(rear, pp);
            return head->next;
        }
        ListNode *tmp = p1 != nullptr ? p1 : p2; //因为是链表，所以直接让其指向剩余的就行
        rear->next = tmp;
        for (; tmp; tmp = tmp->next)
        {
            rear = tmp;
            tmp->val += tag;
            if ((tmp->val) >= 10)
                tag = 1;
            else
                tag = 0;
            tmp->val = tmp->val % 10;
        }
        if (tag)
        {
            ListNode *tt = new ListNode(tag);
            Behindinsert(rear, tt);
        }
        return head->next;
    }

  private:
    void Behindinsert(ListNode *&p, ListNode *key) //在p的后面插入key
    {
        int temp = key->val;
        key->val = temp % 10;
        p->next = key;
        p = key;
        p->next = nullptr;
    }
};