/*************************************************************************
	> File Name: 二叉搜索树的第k个结点.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  7/30 09:00:41 2019
 ************************************************************************/

#include <iostream>
using namespace std;
/*
给定一棵二叉搜索树，请找出其中的第k小的结点。例如， （5，3，7，2，4，6，8）    
中，按结点数值大小顺序第三小结点的值为4。
*/
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/

//递归
class Solution
{
public:
	int depth = 0;
	TreeNode *ret = nullptr;
	TreeNode *KthNode(TreeNode *root, int k)
	{
		if (!root)
			return nullptr;
		ret = KthNode(root->left, k);
		if (ret)
			return ret;
		depth++;
		if (depth == k)
			return root;
		ret = KthNode(root->right, k);
		if (ret)
			return ret;
		return nullptr;
	}
};
//非递归
class Solution
{
public:
	TreeNode *KthNode(TreeNode *root, int k)
	{
		if (!root || k == 0)
			return nullptr;
		stack<TreeNode *> ss;
		ss.push(root);
		TreeNode *ptr = root;
		int depth = 0;
		while (ptr || !ss.empty())
		{
			while (ptr)
			{
				ss.push(ptr);
				ptr = ptr->left;
			}
			if (!ss.empty())
			{
				ptr = ss.top();
				ss.pop();
				depth++;
				if (depth == k)
					return ptr;
				ptr = ptr->right;
			}
		}
		return nullptr;
	}
};