/*************************************************************************
	> File Name: 拓扑排序.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2019年01月04日 星期五 18时42分05秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>

// 如果点的表示还需要插入等操作的话，就将vector 改为　std::list
using namespace std;

class Graph
{
  public:
    Graph(int v)
    {
        this->v = v;
        for (int i = 0; i < v; i++)
            adj.push_back(std::list<int>());
    }
    void AddEdge(int s, int t) //s->t
    {
        adj[s].push_back(t);
    }
    void TopSortByKahn()
    {
        vector<int> inDegree(v, 0); //统计每个顶点的入度
        for (int i = 0; i < v; i++)
        {
            for (auto t : adj[i])
            {
                inDegree[t]++;
            }
        }
        queue<int> que;
        for (int i = 0; i < v; i++)
        {
            if (inDegree[i] == 0)
                que.push(i);
        }
        while (!que.empty())
        {
            int head = que.front();
            que.pop();
            cout << "->" << head;
            for (auto t : adj[head])
            {
                inDegree[t]--;
                if (inDegree[t] == 0)
                    que.push(t);
            }
        }
    }
    void TopSortByDFS()
    {
        // 先构建逆邻接表
        std::vector<std::list<int>> inverseadj(v, std::list<int>());
        for (int i = 0; i < v; i++) // 通过邻接表生成逆邻接表
        {
            for (auto t : adj[i])
            {
                inverseadj[t].push_back(i);
            }
        }
        bool visted[v] = {false};
        for (int i = 0; i < v; i++) //dfs
        {
            if (visted[i] == false)
            {
                visted[i] = true;
                dfs(i, inverseadj, visted);
            }
        }
    }

  private:
    void dfs(int vertex, const std::vector<std::list<int>> &inverseadj,
             bool visted[])
    {
        // cout << vertex << endl;
        for (auto t : inverseadj[vertex])
        {
            if (visted[t] == true)
                continue;
            else
            {
                visted[t] = true;
                dfs(t, inverseadj, visted);
            }
        } // 先把 vertex ＂这个顶点依赖的所有顶点＂都打印出来之后，再打印它自己(核心)
        cout << "->" << vertex;
    }

  private:
    int v;                           //顶点个数
    std::vector<std::list<int>> adj; //邻接表　
};
int main(void)
{
    Graph g(6);
    g.AddEdge(5, 2);
    g.AddEdge(5, 0);
    g.AddEdge(4, 0);
    g.AddEdge(4, 1);
    g.AddEdge(2, 3);
    g.AddEdge(3, 1);

    g.TopSortByKahn();
    cout << endl;
    g.TopSortByDFS();
    cout << endl;
    return 0;
}
