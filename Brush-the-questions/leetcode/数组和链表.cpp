/*************************************************************************
	> File Name: 求众数.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2019年02月20日 星期三 17时11分12秒
 ************************************************************************/

#include <iostream>
/*
定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在众数。

示例 1:

输入: [3,2,3]
输出: 3
示例 2:

输入: [2,2,1,1,1,2,2]
输出: 2*/
#include <unordered_map>
#include <vector>
using namespace std;
/*
class Solution
{
  public:
	int majorityElement(vector<int> &nums)
	{
		int len = nums.size();
		if (len == 1)
			return nums[0];
		unordered_map<int, int> mmp;
		unordered_map<int, int>::iterator iter;
		int result = 0;
		for (int t : nums)
		{
			iter = mmp.find(t);
			if (iter != mmp.end())
			{
				mmp[t]++;
				if (mmp[t] > len / 2)
				{
					result = t;
					break;
				}
			}
			else
			{
				mmp.insert({t, 1});
			}
		}
		return result;
	}
};*/
class Solution
{
  public:
    int majorityElement(vector<int> &nums)
    {
        int count = 1, result = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            if (count == 0)
                result = nums[i];

            if (nums[i] == result)
                count++;
            else
                count--;
            // if (count > nums.size() / 2)
            // 	return nums[i];
        }
        return result;
    }
};
int main(void)
{
    vector<int> vv({2, 2, 1, 1, 1, 2, 2});
    Solution s1;
    std::cout << s1.majorityElement(vv) << std::endl;
}
/*
		41. 缺失的第一个正数
给定一个未排序的整数数组，找出其中没有出现的最小的正整数。

示例 1:

输入: [1,2,0]
输出: 3
示例 2:

输入: [3,4,-1,1]
输出: 2
示例 3:

输入: [7,8,9,11,12]
输出: 1
说明:

你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。
*/
class Solution
{
  public:
    int firstMissingPositive(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 1;
        sort(nums.begin(), nums.end());
        int index = 0;
        //考虑　[0] [] [-4,-3,-2,-1,0] 的几种情况
        while (index < nums.size() - 1 && nums[index] <= 0)
        {
            index++;
        }
        int count = nums[index];
        if (count != 1)
            return 1;

        for (int i = index + 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1])
            {
                if (nums[i] != count + 1)
                    break;
                else
                    count++;
            }
        }
        return count + 1;
    }
};
/*
			141. 环形链表
		给定一个链表，判断链表中是否有环。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

 

示例 1：

输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。


示例 2：

输入：head = [1,2], pos = 0
输出：true
解释：链表中有一个环，其尾部连接到第一个节点。


示例 3：

输入：head = [1], pos = -1
输出：false
解释：链表中没有环。	
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
  public:
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};

/*将两个按升序排列的数组仍按升序合并存放到另一个数组中，要求每个
数都一次到位，不得在新数组中重新排序。*/
#include <stdio.h>
int main(void)
{
    int b[5] = {1, 6, 17, 56, 72};
    int a[5] = {7, 23, 32, 33, 82};
    int c[10], i, j, k, p;
    i = j = k = 0;         //i 对应 a 数组，j 对应 b 数组，k 对应 c 数组；
    while (i < 5 && j < 5) //判断 a,b 两数组是否比较完毕；
    {
        if (a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }
    if (i > 4) //把 b 赋给 c
    {
        for (p = j; p < 5; p++)
            c[k++] = b[p];
    }
    if (j > 4) //把 a 赋给 c
    {
        for (p = i; p < 5; p++)
            c[k++] = a[p];
    }
    for (i = 0; i < 10; i++) //输出 c
        printf("%4d", c[i]);
    printf("\n");
}
/*
21. 合并两个有序链表
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//遍历解法
class Solution
{
  public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode result = ListNode(-100);
        ListNode *test = &result;

        ListNode *temp1 = l1;
        ListNode *temp2 = l2;

        while (temp1 && temp2)
        {
            //注意这里判断了相等的情况
            //temp1->val == temp2->val
            if (temp1->val <= temp2->val)
            {
                test->next = temp1;
                temp1 = temp1->next;
                test = test->next;
            }
            else
            {
                test->next = temp2;
                temp2 = temp2->next;
                test = test->next;
            }
        }
        if (temp1)
            test->next = temp1;
        if (temp2)
            test->next = temp2;
        return result.next;
    }
};
//递归解法
class Solution
{
  public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        if (l1->val <= l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
/*
			23. 合并K个排序链表
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *result = new (-100);
        int len = lists.size();
        while (len > 1)
        {
            for (int i = 0; i < ; i++)
            {
                mergeTwoLists(lists[i],lists[i+k]);
            }
        }
        return result->next;
    }

  private:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        if (l1->val <= l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};