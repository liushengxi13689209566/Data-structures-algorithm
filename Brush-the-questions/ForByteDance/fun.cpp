#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <bitset>
#include <algorithm>
#include <utility>
#include <queue>
#include <bitset>
#include <stack>
#include <list>
#include <unordered_map>
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (!root)
            return res;

        std::queue<TreeNode *> QQ;
        QQ.push(root);

        while (!QQ.empty())
        {
            int count = QQ.size();
            vector<int> vv;
            for (int i = 0; i < count; i++)
            {
                auto tmp = QQ.front();
                vv.push_back(tmp->val);
                QQ.pop();

                if (tmp->left)
                    QQ.push(tmp->left);
                if (tmp->right)
                    QQ.push(tmp->right);
            }
            res.push_back(vv);
        }
        return res;
    }
};