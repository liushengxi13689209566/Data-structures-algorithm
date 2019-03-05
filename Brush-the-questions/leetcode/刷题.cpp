#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <cmath>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;
/*
给定一个Excel表格中的列名称，返回其相应的列序号。

例如，

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...
示例 1:

输入: "A"
输出: 1
示例 2:

输入: "AB"
输出: 28
示例 3:

输入: "ZY"
输出: 701
范例：
class Solution {
public:
    int titleToNumber(string s) {
        long sum = 0;
        for (int i = 0; i < s.size() - 1; i++) 
            sum = (sum + s[i] - 64) * 26;
        sum += s[s.size() - 1] - 64;
        return sum;
    }
};
*/
class Solution
{
  public:
    int titleToNumber(string s)
    {
        unordered_map<int, int> mmap;

        for (int i = 1; i < 27; i++)
        {
            mmap.insert({64 + i, i});
        }
        int len = s.size();
        int result = 0;
        for (int i = 0; i < s.size(); i++)
        {
            result += mmap[s[i]] * pow(26, --len);
        }
        return result;
    }
};
class Solution
{
  public:
    int titleToNumber(string s)
    {
        int len = s.size();
        int result = 0;

        for (int i = 0; i < s.size(); i++)
        {
            result += (s[i] - 64) * pow(26, --len);
        }
        return result;
    }
};
/*
给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。

为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -228 到 228 - 1 之间，最终结果不会超过 231 - 1 。

例如:

输入:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

输出:
2

解释:
两个元组如下:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
*/
//这个绝对是可以的，但是肯定会超时

class Solution
{
  public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
    {
        int len = A.size();
        int result = 0;
        int i, j, k, l;
        for (i = 0; i < len; i++)
        {
            for (j = 0; j < len; j++)
            {
                for (k = 0; k < len; k++)
                {
                    for (l = 0; l < len; l++)
                    {
                        if (A[i] + B[j] + C[k] + D[l] == 0)
                            result++;
                    }
                }
            }
        }
        return result;
    }
};
//先保存a+b的所有取值，然后遍历所有c+d的组合，分成两部分算起来更快

class Solution
{
  public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
    {
        int len = A.size();

        unordered_map<int, int> mmap;

        for (auto i : A)
        {
            for (auto j : B)
            {
                mmap[i + j]++;
            }
        }
        int res = 0;
        int temp = 0;
        for (auto k : C)
        {
            for (auto l : D)
            {
                temp = -(k + l);
                if (mmap.find(temp) != mmap.end())
                    res += mmap[temp];
            }
        }
        return res;
    }
};
/*
给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。

说明：
你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。

示例 1:

输入: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
输出: 1
示例 2:

输入: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
输出: 3
进阶：
如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化 kthSmallest 函数？
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 [3,1,4,null,2]
1
[5,3,6,2,4,null,null,1] 
3
 */
class Solution
{
  public:
    int kthSmallest(TreeNode *root, int k)
    {
        //迭代
        //中序遍历
        stack<TreeNode *> SS;
        TreeNode *p = root;
        int count = 0;

        while (p != NULL || !SS.empty())
        {
            while (p)
            {
                // cout << "push" << endl;
                SS.push(p);
                p = p->left;
            }
            if (!SS.empty())
            {
                p = SS.top();
                SS.pop();
                count++;
                // cout << count << endl;
                if (count == k)
                    break;
                p = p->right;
            }
        }
        return p->val;
    }
};
/*
179. 最大数
给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。

示例 1:

输入: [10,2]
输出: 210
示例 2:

输入: [3,30,34,5,9]
输出: 9534330
说明: 输出结果可能非常大，所以你需要返回一个字符串而不是整数。
*/
/*思路：这种解法对于两个数字a和b来说，如果将其都转为字符串，如果ab > ba，则a排在前面，比如9和34，由于934>349，
所以9排在前面，再比如说30和3，由于303<330，所以3排在30的前面。
按照这种规则对原数组进行排序后，将每个数字转化为字符串再连接起来就是最终结果。代码如下：*/

class Solution
{
  public:
    string largestNumber(vector<int> &nums)
    {
        //插入排序
        string res;
        sort(nums.begin(), nums.end(), [](int &a, int &b) {
            return to_string(a) + to_string(b) > to_string(b) + to_string(a);
        });
        for (auto i : nums)
            res += to_string(i);
        /*[0,0]的情况*/
        return res[0] == '0' ? "0" : res;
    }
};
/*
摆动排序 II
给定一个无序的数组 nums，将它重新排列成 nums[0] < nums[1] > nums[2] < nums[3]... 的顺序。

示例 1:

输入: nums = [1, 5, 1, 1, 6, 4]
输出: 一个可能的答案是 [1, 4, 1, 5, 1, 6]
示例 2:

输入: nums = [1, 3, 2, 2, 3, 1]
输出: 一个可能的答案是 [2, 3, 1, 3, 1, 2]
说明:
你可以假设所有输入都会得到有效的结果。

进阶:
你能用 O(n) 时间复杂度和 / 或原地 O(1) 额外空间来实现吗？
*/
class Solution
{
  public:
    void wiggleSort(vector<int> &nums)
    {
    }
};
/*
寻找重复数
给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。

示例 1:

输入: [1,3,4,2,2]
输出: 2
示例 2:

输入: [3,1,3,4,2]
输出: 3
说明：

不能更改原数组（假设数组是只读的）。
只能使用额外的 O(1) 的空间。
时间复杂度小于 O(n2) 。
数组中只有一个重复的数字，但它可能不止重复出现一次。

//鸽巢原理
区别[1, n]中搜索，首先求出中点mid，然后遍历整个数组，统计所有小于等于mid的数的个数，
如果个数大于mid，则说明重复值在[mid+1, n]之间，反之，重复值应在[1, mid-1]之间，然后依次类推，
直到搜索完成，此时的low就是我们要求的重复值，参见代码如下：
*/
class Solution
{
  public:
    int findDuplicate(vector<int> &nums)
    {
        int len = nums.size();

        int low = 1, high = len - 1;
        int count = 0;
        int mid = low + ((high - low) >> 1);

        while (low <= high)
        {
            count = 0;
            for (auto i : nums)
            {
                if (i <= mid)
                    count++;
            }
            if (count <= mid)
                low = mid + 1;
            else
                high = mid - 1;
            mid = low + ((high - low) >> 1);
        }
        return low;
    }
};
/*
打家劫舍
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

示例 1:

输入: [1,2,3,1]
输出: 4
解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。
示例 2:

输入: [2,7,9,3,1]
输出: 12
解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
     偷窃到的最高金额 = 2 + 9 + 1 = 12 。
*/
class Solution
{
  public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];

        vector<int> money(nums.size());
        money[0] = nums[0];
        money[1] = nums[1];
        int result = money[0] > money[1] ? money[0] : money[1];
        int max = 0;
        for (int i = 2; i < nums.size(); i++)
        {
            //维护前 i-2 个数字的最大值
            if (money[i - 2] > max)
                max = money[i - 2];
            money[i] += (max + nums[i]);
            //维护最大值
            if (money[i] > result)
                result = money[i];
        }
        return result;
    }
};
/*
岛屿的个数
给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。

示例 1:

输入:
11110
11010
11000
00000

输出: 1
示例 2:

输入:
11000
11000
00100
00011

输出: 3
// dfs 
*/
class Solution
{
  public:
    int numIslands(vector<vector<char>> &grid)
    {
        auto row = grid.size();
        if (row <= 0)
            return 0;
        auto col = grid[0].size();

        vector<vector<bool>> temp_visted(row, vector<bool>(col, false));
        visted = temp_visted;

        int result = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (visted[i][j] == false && grid[i][j] == '1')
                {
                    visted[i][j] = true;
                    dfs(grid, i, j);
                    result++;
                }
            }
        }
        return result;
    }

  private:
    int dir[4][2] = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}};

    vector<vector<bool>> visted;

    bool check(vector<vector<char>> &grid, int i, int j)
    {
        //i 行　  j 列
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return false;
        if (visted[i][j] == true)
            return false;
        if (grid[i][j] == '0') //注意是字符，我就坑在了这里
            return false;
        return true;
    }
    void dfs(vector<vector<char>> &grid, int x, int y)
    {
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            if (check(grid, xx, yy))
            {
                visted[xx][yy] = true;
                dfs(grid, xx, yy);
            }
        }
    }
};