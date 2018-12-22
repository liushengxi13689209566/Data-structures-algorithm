
struct TreeLinkNode
{
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr)
    {
    }
};
/*
题目描述
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。

*/
class Solution
{
  public:
    TreeLinkNode *GetNext(TreeLinkNode *pNode)
    {
        if (!pNode)
            return nullptr;
        if (pNode->right) /*如果右节点没空，就去找右节点的最左边的节点即可*/
        {
            TreeLinkNode *temp1 = pNode->right;
            while (temp1->left)
            {
                temp1 = temp1->left;
            }
            return temp1;
        }
        else /*右节点是空的*/
        {
            TreeLinkNode *temp2 = pNode;
            while (temp2->next && (temp2 != temp2->next->left))
            {
                temp2 = temp2->next;
            }
            if (!temp2->next)
                return nullptr;
            else
                return temp2->next;
        }
    }
};