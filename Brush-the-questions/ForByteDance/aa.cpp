/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution
{
public:
    //左 根 右
    TreeNode *lastMax = nullptr;
    void ConvertNode(TreeNode *node)
    {
        if (node)
        {
            if (node->left)
                ConvertNode(node->left);

            node->left = lastMax;
            if (lastMax)
                lastMax->right = node;
            lastMax = node;

            if (node->right)
                ConvertNode(node->right);
        }
    }
    TreeNode *Convert(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;
        //先找到需要返回的节点的指针
        TreeNode *ret = root;
        while (ret->left)
            ret = ret->left;

        ConvertNode(root);

        return ret;
    }
};