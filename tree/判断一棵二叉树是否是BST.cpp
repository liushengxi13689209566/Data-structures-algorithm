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
    int data = -100;
    bool isValidBST(TreeNode *root)
    {
        if (!root)
            return true;
        else
        {
            bool ret = false;
            ret = isValidBST(root->left);
            if (-100 != data) /*跳过第一次*/
                ret = ret && (root->val > data);
            data = root->val;
            ret = ret && isValidBST(root->right); //保证前面的全都是ＢＳＴ
            return ret;
        }
    }
};