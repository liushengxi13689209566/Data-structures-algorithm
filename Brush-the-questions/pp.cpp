/*************************************************************************
	> File Name: pp.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2019年02月27日 星期三 18时28分49秒
 ************************************************************************/

#include <iostream>
using namespace std;
#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>

// 删除数组中重复的元素

// 例如：

// arr = [2, 3, 4, 5, 2, 2, 4]

// 程序运行后

// arr = [2, 3, 4, 5]

/*void deleteDupValue(std::vector<int> &arr)
{
    vector<int> result;
    unordered_map<int, short> mmp;
    for (auto i : arr)
    {
        if (mmp.find(i) == mmp.end())
        {
            mmp.insert({i,1});
            result.push_back(i);
        }
    }
    arr = result;
}*/

/*int fibonacci(const int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}*/

// root 是一个二叉搜索树的根

//root → 5

///   \

//	3	8
//	/
//	2

// 在以 root 为根的二叉搜索树中插入值为 val 的新节点

/* struct Node
{
    int val;

    Node *left;

    Node *right;
};

void insert(Node *root, int val)
{
    if (root == nullptr)
    {
        root = new Node;
        root->val = val;
        return;
    }
    if (val <= root->val)
        insert(root->left, val);
    else if (val > root->val)
        insert(root->right, val);
    else
        return;
} */

int dir[4][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1},
}; //方向数组,代表 4 个方向

int visted[120][120]; //  1  代表访问过  0 代表没有访问过

bool check(int x, int y) //检查下一步是否越界和是否已经走过
{
    if (x < 0 || y < 0 || x >= 5 || y >= 5)
        return false;
    if (visted[x][y])
        return false;
    return true;
}
struct node
{
    int x;
    int y;
    node(int i, int j) : x(i), y(j) {}
};
vector<node> path;

int dfs(const vector<vector<char>> &maze, const int i, const int j)
{
    if (i == 5 && j == 5)
    {
        path.push_back(node(5, 5));
        return 0;
    }

    for (int i = 0; i < 4; i++) // 4 个方向
    {
        int xx = i + dir[i][0];
        int yy = j + dir[i][1];
        if (check(xx, yy) && maze[xx][yy] != '*') //xx ,yy 可踏上去
        {
            visted[xx][yy] = 1;
            path.push_back(node(xx, yy));
            dfs(maze, xx, yy);
            visted[xx][yy] = 0; //回溯
            path.pop_back();
        }
    }
}

void findPath(const vector<vector<char>> &maze, const int i, const int j)
{
    dfs(maze, i, j);
    for (auto i : path)
        cout << i.x << " , " << i.y << endl;
    cout << endl;
}

int main(void)
{
    vector<vector<char>> maze = {
        {},
        {},
        {}

    }
}
