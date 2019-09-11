/*************************************************************************
	> File Name: 最近公共祖先问题.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  8/25 11:19:33 2019
 ************************************************************************/

#include <iostream>
using namespace std;
//1.BST
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
	TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
	{
		if (!root || !p || !q)
		{
			return nullptr;
		}
		if (p->val > root->val && q->val > root->val)
			return lowestCommonAncestor(root->right, p, q);

		if (p->val < root->val && q->val < root->val)
			return lowestCommonAncestor(root->left, p, q);

		return root;
	}
};
//2.带有父节点指针
//3. 最普通的树
//（解法一）
/**
        注意p,q必然存在树内, 且所有节点的值唯一!!!
        递归思想, 对以root为根的(子)树进行查找p和q, 如果root == null || p || q 直接返回root
        表示对于当前树的查找已经完毕, 否则对左右子树进行查找, 根据左右子树的返回值判断:
        1. 左右子树的返回值都不为null, 由于值唯一左右子树的返回值就是p和q, 此时root为LCA
        2. 如果左右子树返回值只有一个不为null, 说明只有p和q存在与左或右子树中, 最先找到的那个节点为LCA
        3. 左右子树返回值均为null, p和q均不在树中, 返回null
 */
class Solution
{
public:
	TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
	{
		if (!root || p == root || q == root)
			return root;
		TreeNode *left_lca = lowestCommonAncestor(root->left, p, q);
		TreeNode *right_lca = lowestCommonAncestor(root->right, p, q);
		if (left_lca && right_lca)
			return root;
		return left_lca ? left_lca : right_lca;
	}
};
//（解法二）
/*
用两个链表，保存从根节点到输入的两个节点的路径，然后把问题转换成求两个链表的最后最后公共节点
 */
class Solution
{
public:
	TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
	{
		if (!root || !p || !q)
			return NULL;
		if (p == q)
			return p;

		dfs(root, p, q);
		// 去找最后相同的第一个数字即可
		// ....
		if (paths.size() != 2)
			return NULL;
		int idx = 0;
		while (paths[0][idx] == paths[1][idx])
			idx++;
		return paths[0][idx - 1];
	}

private:
	void dfs(TreeNode *root, TreeNode *p, TreeNode *q)
	{
		if (!root)
			return;
		path.push_back(root);

		if (root == p || root == q)
			paths.push_back(path);

		if (root->left)
			dfs(root->left, p, q);
		if (root->right)
			dfs(root->right, p, q);

		path.pop_back();
	}
	vector<vector<TreeNode *>> paths;
	vector<TreeNode *> path;
};
int *p = new int();