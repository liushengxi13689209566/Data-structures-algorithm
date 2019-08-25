#include <iostream>
#include <string>
using namespace std;
template <typename T>
struct Node
{
    T data;
    Node *next;
    Node(T x) : data(x), next(nullptr) {}
};

template <typename T>
struct Queue
{
    Queue() : head(nullptr), tail(nullptr) {}
    void Inqueue(const T x)
    {
        Node<T> *node = new Node<T>(x);
        Node<T> *old_tail;
        do
        {
            old_tail = tail.load();
        } while (old_tail->next->compare_exchange_strong(nullptr, node) != true);

        tail.compare_exchange_strong(old_tail, node);
    }
    T Outqueue()
    {
        //空
        Node<T> *old_head;
        do
        {
            old_head = head.load();
            if (old_head->next)
            {
                cout << "the queue is empty " << endl;
                return T();
            }
        } while (head.compare_exchange_strong(old_head, old_head->next) != true);
        return old_head->next->data;
    }
    std::atomic<Node<T> *> head;
    std::atomic<Node<T> *> tail;
};

int main()
{
    Queue<int> qq;
    qq.Inqueue(6);
    qq.Inqueue(8);
    qq.Inqueue(9);
    qq.Inqueue(4);
    qq.Inqueue(0);
    qq.Inqueue(3);
    qq.Inqueue(4);
    qq.Inqueue(1);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int partition(vector<int> &input, const int &l, const int &r)
    {
        int k = l, pivot = r;
        for (int i = l; i < r; i++)
        {
            if (input[i] < pivot)
                std::swap(input[i], input[k++]);
        }
        std::swap(input[k], input[r]);
        return k;
    }
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        vector<int> ret;
        if (input.size() <= 0 || k <= 0 || k > input.size())
            return ret;
        int l = 0, r = input.size() - 1;
        int q = partition(input, l, r);
        while (q != k - 1)
        {
            if (q > k - 1)
            {
                r = q - 1;
                q = partition(input, l, r);
            }
            else
            {
                l = q + 1;
                q = partition(input, l, r);
            }
        }

        for (int i = 0; i < k; i++)
        {
            ret.push_back(input[i]);
        }
        return ret;
    }
};
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        int len = nums.size();
        if (len < 3)
            return result;
        sort(nums.begin(), nums.end()); //先转换成有序向量
        for (int i = 0; i < len - 2; ++i)
        {
            int j = i + 1;
            int k = len - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k]; //转换成两数之和的问题
                if (sum == 0)
                {
                    result.push_back({nums[i], nums[j++], nums[k--]});
                    while (j < k && nums[j] == nums[j - 1])
                        j++; //j跳过重复元素
                    while (j < k && nums[k] == nums[k + 1])
                        k--; //k跳过重复元素
                }
                else if (sum > 0)
                    k--; //sum(两数和)较大时，k左移
                else
                    j++; //sum较小时，j右移
            }
            while (i < len - 2 && nums[i] == nums[i + 1])
                i++; //i跳过重复元素
        }
        return result;
    }
};
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
//说明：路径一定是从根节点到叶子节点的
class Solution
{
public:
    vector<vector<int>> res;
    void fun(TreeNode *root, int expectNumber, int curSum, vector<int> &onepath)
    {
        curSum += root->val;
        onepath.push_back(root->val);
        bool isleaf = (root->left == nullptr) && (root->right == nullptr);
        if (isleaf && curSum == expectNumber)
        {
            res.push_back(onepath);
        }
        if (root->left)
            fun(root->left, expectNumber, curSum, onepath);
        if (root->right)
            fun(root->right, expectNumber, curSum, onepath);

        onepath.pop_back(); //注意回溯
        curSum -= root->val;
    }
    vector<vector<int>> FindPath(TreeNode *root, int expectNumber)
    {
        if (!root)
            return res;
        vector<int> onepath;
        fun(root, expectNumber, 0, onepath);
        return res;
    }
};
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution
{
public:
    int getlen(ListNode *pHead)
    {
        ListNode *p = pHead;
        int len = 0;
        while (p)
        {
            p = p->next;
            len++;
        }
        return len;
    }
    ListNode *fun(ListNode *pHead1, ListNode *pHead2, int k) //  左长右短
    {
        ListNode *p1 = pHead1;
        for (int i = 0; i < k; i++)
            p1 = p1->next;
        ListNode *p2 = pHead2;
        while (p1->val != p2->val)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
    {
        if (!pHead1 || !pHead2)
            return nullptr;
        int len1 = getlen(pHead1);
        int len2 = getlen(pHead2);

        if (len1 > len2)
        {
            return fun(pHead1, pHead2, len1 - len2);
        }
        else
        {
            return fun(pHead2, pHead1, len2 - len1);
        }
    }
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
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root || !p || !q)
        {
            return nullptr;
        }
        if (p->val < root->val && q->val > root->val)
            return root;

        if (p->val > root->val && q->val > root->val)
            lowestCommonAncestor(root->right,p,q);
        if (p->val > root->val && q->val > root->val)
            lowestCommonAncestor(root->left,p,q);
    }
};