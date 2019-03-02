/*
136. 只出现一次的数字
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度O(n)。 你可以不使用额外空间来实现吗？O(1)

示例 1:

输入: [2,2,1]
输出: 1
示例 2:

输入: [4,1,2,1,2]
输出: 4

*/
#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>

using namespace std;

class Solution
{
  public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, short> mmp;

        for (auto t : nums)
        {
            if (mmp.find(t) == mmp.end())
                mmp.insert({t, 1});
            else
                mmp.erase(t);
        }
        return mmp.begin()->first;
    }
};
/*
//先排序，再比较的方法
static auto x = []() {
		std::ios::sync_with_stdio( false );
		std::cin.tie( 0 );
		return 0;
}( );
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 1)
        {
            return nums[0];
        }
        
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() -1; i+=2)
        {
            if(nums[i] != nums[i+1])
            {
                return nums[i];
            }
        }
        return nums[nums.size() -1];
    }
};
//位运算的方法
class Solution {
public:
    int singleNumber(vector<int>& nums) {
 return accumulate(nums.begin(), nums.end(),0,bit_xor<int>());
    }
};
*/
/*
217. 存在重复元素
*/

class Solution
{
  public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, short> mmp;

        for (auto t : nums)
        {
            if (mmp.find(t) == mmp.end())
                mmp.insert({t, 1});
            else
                return true;
        }
        return false;
    }
};
/*
                78. 子集
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
说明：解集不能包含重复的子集。
示例:
输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
//  某位大神的思路，但是实在是不想写了，留给以后吧
*/
class Solution
{
  public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        result.push_back(path);

        dfs(0, nums);

        return result;
    }

  private:
    vector<vector<int>> result;
    vector<int> path;

    void dfs(int index, const vector<int> &nums)
    {
        for (int i = index; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            result.push_back(path);
            dfs(i + 1, nums);
            path.pop_back();
        }
    }
};
/*还有另外两种思路：

- 可以直接从后遍历，遇到一个数就把所有子集加上该数组成新的子集，遍历完毕即是所有子集
- 位运算*/

/*DFS*/
/*
104. 二叉树的最大深度
给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
   
返回它的最大深度 3 。
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
  public:
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        int leftdepth = maxDepth(root->left);
        int rightdepth = maxDepth(root->right);

        return leftdepth > rightdepth ? leftdepth + 1 : rightdepth + 1;
    }
};

/*
111. 二叉树的最小深度
给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明: 叶子节点是指没有子节点的节点。

示例:

给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回它的最小深度  2 
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
  public:
    int minDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return 1;

        int leftdepth = INT_MAX, rightdepth = INT_MAX;

        if (root->left)
            leftdepth = minDepth(root->left); // 1
        if (root->right)
            rightdepth = minDepth(root->right); // 0

        return leftdepth < rightdepth ? leftdepth + 1 : rightdepth + 1;
    }
};
class Solution
{
  public:
    int minDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int left = minDepth(root->left), right = minDepth(root->right);

        if (root->left && root->right)
            return 1 + min(left, right);
        else //只要有一方　左边或者右边　为空
            return 1 + left + right;
        /*
        1.左空：1+0+右
        2.右空：1+左+0
        3.左右都空的：1+0+0
        */
    }
};
/*
124. 二叉树中的最大路径和
给定一个非空二叉树，返回其最大路径和。

本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。

示例 1:

输入: [1,2,3]

       1
      / \
     2   3

输出: 6
示例 2:

输入: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

输出: 42
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
  public:
    int maxPathSum(TreeNode *root)
    {
    }
};
/*
148. 排序链表
在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

示例 1:

输入: 4->2->1->3
输出: 1->2->3->4
示例 2:

输入: -1->5->3->4->0
输出: -1->0->3->4->5
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
    ListNode *sortList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *mid = findMid(head);

        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);

        return mergeTwoLists(left, right);
    }

    ListNode *findMid(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *slow = head;
        ListNode *fast = head->next->next;

        while (fast)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast)
                fast = fast->next;
        }
        ListNode *mid = slow->next;
        slow->next = NULL;
        return mid;
    }
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode result = ListNode(-100);
        ListNode *test = &result;

        while (l1 && l2)
        {
            //注意这里判断了相等的情况
            //l1->val == l2->val
            if (l1->val <= l2->val)
            {
                test->next = l1;
                l1 = l1->next;
            }
            else
            {
                test->next = l2;
                l2 = l2->next;
            }
            test = test->next;
        }
        if (l1)
            test->next = l1;
        if (l2)
            test->next = l2;
        return result.next;
    }
};
/*
26. 删除排序数组中的重复项
给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

示例 1:

给定数组 nums = [1,1,2], 

函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。 

你不需要考虑数组中超出新长度后面的元素。
示例 2:

给定 nums = [0,0,1,1,1,2,2,3,3,4],

函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。

你不需要考虑数组中超出新长度后面的元素。

*/
class Solution
{
  public:
    int removeDuplicates(vector<int> &nums)
    {
        int tag = 1;
        if (nums.size() == 0)
            return 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1])
                nums[tag++] = nums[i];
        }
        return tag;
    }
};
class Solution
{
  public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string result;
        if (strs.size() <= 0)
            return result;

        auto len = strs[0].size();
        for (auto i : strs)
        {
            if (i.size() < len)
                len = i.size();
        }
        for (int i = 0; i < len; i++)
        {
            for (int j = 1; j < strs.size(); j++)
            {
                if (strs[j][i] != strs[0][i])
                    return result;
            }
            result += strs[0][i];
        }
        return result;
    }
};
/*
292. Nim游戏
你和你的朋友，两个人一起玩 Nim游戏：桌子上有一堆石头，每次你们轮流拿掉 1 - 3 块石头。 拿掉最后一块石头的人就是获胜者。你作为先手。

你们是聪明人，每一步都是最优解。 编写一个函数，来判断你是否可以在给定石头数量的情况下赢得游戏。

示例:

输入: 4
输出: false 
解释: 如果堆中有 4 块石头，那么你永远不会赢得比赛；
     因为无论你拿走 1 块、2 块 还是 3 块石头，最后一块石头总是会被你的朋友拿走。
class Solution
{
  public:
    bool canWinNim(int n)
    {

    }
};
*/

class Solution
{
  public:
    //排除各项特殊选项后，对剩余的 偶数做除以2处理，最终==1的即为2的幂
    bool isPowerOfTwo(int n)
    {
        while (n > 1 && n % 2 == 0)
            n /= 2;
        if (n == 1)
            return true;
        return false;
    }
};
