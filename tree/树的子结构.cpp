/*************************************************************************
	> File Name: 树的子结构.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2018年12月22日 星期六 21时49分42秒
 ************************************************************************/

#include <iostream>
using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL)
	{
	}
};

class Solution
{
  public:
	bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2)
	{
		if (!pRoot1 || !pRoot2)
			return false;

		bool ret = false;
		if (pRoot1->val == pRoot2->val) //如果暂时相等，就尝试着去判断下面的结构是否相等，如果下面的结构不相等，就得回溯重新去判断他的左和右
		{
			ret = (sametree(pRoot1->left, pRoot2->left) && sametree(pRoot1->right, pRoot2->right));
			if (ret)
				return true;
		}
		return (HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2));
	}
	bool sametree(TreeNode *t1, TreeNode *t2)
	{
		if (!t2) //即使是有一节点，也是子结构啊
		{
			return true;
		}
		else
		{
			if (!t1)
				return false;
		}
		if (t1->val == t2->val)
			return (sametree(t1->left, t2->left) && sametree(t1->right, t2->right));
		else
			return false;
	}
};