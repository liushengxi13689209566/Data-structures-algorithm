/*************************************************************************
	> File Name: 　重建二叉树.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: Thu 13 Dec 2018 12:25:39 PM CST
 ************************************************************************/
#include <stream>
#include <vector>

// struct TreeNode
// {
// 	int val;
// 	TreeNode *left;
// 	TreeNode *right;
// 	TreeNode(int x) : val(x), left(NULL), right(NULL){}
// };
/*题意：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回

思路：前序遍历的第一个节点就是根节点，于是我们在中序遍历中找到该节点，于是该节点就把树划分成了左子树和右子树，之后递归求解即可
*/
class Solution
{
  public:
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
	{
		auto pre_size = preorder.size();
		auto in_size = inorder.size();

		if (pre_size != in_size || pre_size == 0 || in_size == 0)
			return nullptr;

		return fun(preorder, 0, pre_size - 1, inorder, 0, in_size - 1);
	}
	TreeNode *fun(vector<int> &preorder, int preL, int preR, vector<int> &inorder, int inderL, int inderR)
	{
		if (preL > preR)
			　 //　找完所有的节点
				return nullptr;

		TreeNode *root = new TreeNode(preorder[preL]);

		int i = inderL;
		for (; i <= inderR; i++)
		{
			if (inorder[i] == preorder[preL])
				break;
		}

		int left_size = i - inderL;
		int right_size = inderR - i;

		root->left = fun(preorder, preL + 1, preL + left_size, inorder, inderL, i - 1);

		root->right = fun(preorder, preL + left_size + 1, preR, inorder, i + 1, inderR);

		return root;
	}
};
