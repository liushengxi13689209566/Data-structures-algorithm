/*************************************************************************
	> File Name: 二叉树的锯齿形层次遍历.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2018年08月21日 星期二 00时13分27秒
 ************************************************************************/
/*
给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层次遍历如下：

[
  [3],
  [20,9],
  [15,7]
]
*/
#include <iostream>
using namespace std;
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
	vector<vector<int>> zigzagLevelOrder(TreeNode *root)
	{
		vector<vector<int>> result;
		if (!root)
			return result;
		queue<TreeNode *> QQ;
		QQ.push(root);
		bool tag = false; //直接来翻转vector<int>既可
		while (!QQ.empty())
		{
			int len = QQ.size();
			vector<int> tt;
			for (int i = 0; i < len; i++) //一次性出一层
			{
				TreeNode *temp = QQ.front();
				QQ.pop();
				tt.push_back(temp->val);
				if (temp->left) //这里的顺序就是左右
					QQ.push(temp->left);
				if (temp->right)
					QQ.push(temp->right);
			}
			if (tag)
				reverse(tt.begin(), tt.end());
			tag = !tag;
			result.push_back(tt);
		}
		return result;
	}
};
