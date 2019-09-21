
@[TOC](文章目录)

最容易记忆的方式书写，记录所有思路和拓展。分门别类书写。
确定每一个思路的时间复杂度
# 排序
# 查找
### 二分查找
### 变异的二分查找

# 数组
### 1. 二维数组中的查找

在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

思路：

- 把每一行看成有序递增的数组，
利用二分查找（logN），
通过遍历每一行得到答案，
时间复杂度是nlogn

- 利用二维数组由上到下，由左到右递增的规律，那么选取右上角或者左下角的元素与target进行比较。类似于二叉查找树的形式.复杂度是O(logN)

```cpp
class Solution
{
public:
    bool Find(int target, vector<vector<int>> array)
    {
        //二叉查找树
        int row = array.size();
        if (row <= 0)
            return false;
        int col = array[0].size();
        for (int j = col - 1, i = 0; j >= 0 && i < row;)
        //从右上角开始，注意循环结束条件
        {
            if (target == array[i][j])
            {
                return true;
            }
            else if (target < array[i][j])
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return false;
    }
};
```



# 字符串
### 1.替换空格
请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

思路：很明显，这样子的替换会**改变字符串的大小。所以一种就是使用原来字符串后面的内存，一种就是自己分配内存。**

如何替换：

1. 从前向后扫描，遇到空格就替换，需要移动元素。时间复杂度O(n^2)
2. ``从后往前遍历并替换``，一个指针指向新的，一个指向旧的。遍历旧的字符串对新指针直接赋值或者替换即可。时间复杂度O(n)

- 从前向后扫描，遇到空格就替换，需要移动元素。时间复杂度O(n^2)

```cpp
class Solution {
public:
	void replaceSpace(char *str,int length) {
        for(int i= 0 ;i< length ;)
        {
            if(str[i] == ' ')
            {
                for(int j = length-1 ;j >= i ;j--)
                {
                    str[j+2] = str[j];    
                }
                str[i++]= '%';
                str[i++] ='2';
                str[i++] ='0';
                continue;
            }
            i++;
	    }
    }
};
```
-   ``从后往前遍历并替换``，一个指针指向新的，一个指向旧的。遍历旧的字符串对新指针直接赋值或者替换即可。时间复杂度O(n)
```cpp
class Solution
{
public:
    //length 为str 的 内存capity
    void replaceSpace(char *str, int length)
    {
        if (str == nullptr || length == 0)
            return;

        int spaceNumber = 0;
        int originLength = 0;
        //统计空格和str的长度
        char *tmp = str;
        while (*tmp != '\0')
        {
            originLength++;
            if (*tmp == ' ')
                spaceNumber++;
            tmp++;
        }

        int indexOrigin = originLength; //将'\0'也直接当作非空格自负处理即可
        int indexNew = originLength + 2 * spaceNumber;
        if (indexNew > length)
            return;

        while (indexOrigin >= 0 && indexNew > indexOrigin)
        {
            if (str[indexOrigin] != ' ')
            {
                str[indexNew--] = str[indexOrigin];
            }
            else
            {
                str[indexNew--] = '0';
                str[indexNew--] = '2';
                str[indexNew--] = '%';
            }
            indexOrigin--;
        }
    }
};
```
拓展：`合并两个数组（字符串）的时候都可以使用这种方法，会减少移动的次数，提高效率`

[https://leetcode-cn.com/problems/merge-sorted-array/](https://leetcode-cn.com/problems/merge-sorted-array/)

# 链表 
### 1.链表的逆置
> `当打算修改输入的数据时，最好问清面试官是否可以！！！`

思路：

1. 使用栈的结构，时间复杂度O(n),空间复杂度O(n)
2. 递归，时间复杂度O(n),空间复杂度O(n)，由于使用递归，将会使用隐式栈空间。递归深度可能会达到 n 层。
3. 修改输入数据，逆置链表，时间复杂度O(n),空间复杂度O(1)
- 使用栈的结构
```cpp
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution
{
public:
    vector<int> printListFromTailToHead(ListNode *head)
    {
        vector<int> res;
        std::stack<ListNode *> QQ;
        ListNode *p = head;
        while (p)
        {
            QQ.push(p);
            p = p->next;
        }
        while (!QQ.empty())
        {
            res.push_back(QQ.top()->val);
            QQ.pop();
        }
        return res;
    }
};
```
- 递归的方式

```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // 0 node || at the end of list
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* HEAD = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return HEAD;
    }
};
```
- 迭代的方式(头插法嘛)
```cpp
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
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *nextTemp = nullptr;
        while (curr)
        {
            nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
};
```
### 2.在O(1)时间内删除链表节点
请编写一个函数，使其可以删除某个链表中给定的（非末尾）节点，你将只被给定要求被删除的节点。
输入: head = [4,5,1,9], node = 5
输出: [4,1,9]
解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.

思路：OK。`我们现在知道了需要删除的节点。那么我们把后面节点的内容覆盖到前面需要删除的节点，然后把后面的节点删除掉就行了呗。`

时间复杂度O(1)
 
注意有几大坑点：

- 只有一个节点，删除节点位于头节点（也是尾节点） 
- 删除节点位于尾节点
- 需要调用者确保要删除的节点在该链表中。


```cpp
void DeleteNode(ListNode *head, ListNode *deListNode)
{
    if (deListNode == nullptr || head == nullptr)
        return;
    //1.普通情况
    if (deListNode->next)
    {
        ListNode *p = deListNode->next;

        deListNode->val = deListNode->next->val;
        deListNode->next = deListNode->next->next;
        delete p;
        p = nullptr;
    }
    //2.只有一个节点
    else if (head == deListNode)
    {
        delete deListNode;
        deListNode = nullptr;
        head = nullptr;
    }
    //3.删除的节点是尾节点
    else
    {
        ListNode *p = head;
        while (p->next != deListNode)
        {
            p = p->next;
        }
        p->next = nullptr;
        delete deListNode;
        deListNode = nullptr;
    }
}
```

### 3.链表中的倒数第k个节点
输入一个链表，输出该链表中倒数第k个结点。

思路：双指针思路。时间复杂度 O(n)

```cpp

```
### 2.

