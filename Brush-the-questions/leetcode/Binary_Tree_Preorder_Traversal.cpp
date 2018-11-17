/*************************************************************************
	> File Name: Binary_Tree_Preorder_Traversal.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年02月10日 星期六 19时17分06秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*题目描述：

给定一个二叉树，返回其节点值的前序遍历。

例如：
给定二叉树[1,null,2,3]，
   1
    \
     2
    /
   3
返回[1,2,3]。

注意：递归解决方案是微不足道的，你可以迭代地做？*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {  //递归
    vector<int> intVec ;
public:
    vector<int> preorderTraversal(TreeNode* root) {
		if(root){
			intVec.push_back(root->val);
			preorderTraversal(root->left);
			preorderTraversal(root->right) ;
		}
        return intVec ;
    }
};

class Solution {  //迭代
    vector<int> intVec ;
public:
    vector<int> preorderTraversal(TreeNode* root) {
		stack<TreeNode *>  ST ;
		TreeNode *temp = root ;
		while(temp  != NULL ||  !ST.empty() )
    	{
			while(temp  != NULL )
			{
				//入栈
				intVec.push_back(temp->val);
				ST.push(temp) ;
				temp=temp->left;
			}
			if( !ST.empty())
			{
				temp = ST.top();
				ST.pop();
				temp=temp->right ;
			}
    	}
		return intVec ;    
    }
};
