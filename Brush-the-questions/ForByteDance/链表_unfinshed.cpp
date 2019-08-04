/*************************************************************************
	> File Name: 链表.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  8/ 2 09:27:11 2019
 ************************************************************************/

#include <iostream>
using namespace std;
/*
删除链表中重复的结点
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重
复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
*/
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution
{
public:
    ListNode *deleteDuplication(ListNode *pHead)
    {
        if (!pHead)
            return nullptr;
        if (!pHead->next)
            return pHead;

        ListNode *p = pHead;
        ListNode *ret = new ListNode(-100);
        ListNode *ptr = ret;

        while (p)
        {
            if (p->next && p->next->val == p->val)
            {
                p = p->next;
                p = p->next;
            }
            else if (p->val !=)
            {
                ret->next = p;
                ret = p;
                p = p->next;
            }
        }
        return ptr->next;
    }
};
/*
翻转链表通过
*/
class Solution
{
public:
    ListNode *ReverseList(ListNode *pHead)
    {
        if (!pHead)
            return nullptr;
        if (!pHead->next)
            return pHead;
        //逐一尾节点置空
        ListNode *p = pHead->next;
        ListNode *nn = p->next;
        p->next = pHead;
        pHead->next = nullptr;
        pHead = p;
        p = nn;

        while (p)
        {
            nn = p->next;
            p->next = pHead;
            pHead = p;
            p = nn;
        }
        return pHead;
    }
};

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, a, b;
    vector<int> vv;
    while (n--)
    {
        cin >> a >> b;
        if (a == 1)
            vv.push_back(b);
        else
        {
            int ret = vv[0];
            for (int i = 1; i < vv.size(); i++)
            {
                ret |= vv[i];
            }
            if (ret == b)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}

#include <vector>
#include <iostream>
using namespace std;
int main()
{
    int n;
    int tmp, max = -100;
    while (n--)
    {
        cin >> tmp;
        if (max < tmp)
            max = tmp;
        cout << max << endl;
    }
}
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, a, b;
    vector<int> vv;
    cin >> n;
    while (n--)
    {
        cin >> a >> b;
        if (a == 1)
            vv.push_back(b);
        else
        {
            for (auto i : vv)
                cout << i << " ";
            cout << endl;
            int len = vv.size();
            if (len <= 0)
                cout << "NO" << endl;

            int ret = vv[0];
            for (int i = 1; i < len; i++)
            {
                ret |= vv[i];
            }
            if (ret == b)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}