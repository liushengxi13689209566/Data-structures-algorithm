/*************************************************************************
	> File Name: 两个节点的最低公共祖先.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2019年02月02日 星期六 16时05分30秒
 ************************************************************************/
#include <vector>
#include <iostream>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <vector>
using namespace std;
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
		int idx = 0 ;
		while(paths[0][idx] == paths[1][idx])
			idx++;
		return paths[0][idx];
 	}

  private:
	void dfs(TreeNode *root, TreeNode *p, TreeNode *q)
	{
		if (!root)
			return;
		path.push_back(root);

		if (root == p)
			paths.push_back(path);
		if (root == q)
			paths.push_back(path);

		if (root->left)
			dfs(root->left, p, q);
		if (root->right)
			dfs(root->left, p, q);

		path.pop_back();
	}
	vector<vector<TreeNode *>> paths;
	vector<TreeNode *> path;
};