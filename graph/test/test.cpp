/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月04日 星期四 16时36分21秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include <iostream>

#include <memory.h> 

#include <vector>



using namespace std;



const int MAX = 1024;

const int INF = 2147483647;		// 设置最大权值 



int N, M;

vector<pair<int, int> > pMap[MAX];	// 邻接表 



void Prim();



int main()

{

	cin >> N >> M;

	for(int i = 1; i <= M; i++)

	{

		int u, v, w;

		cin >> u >> v >> w;

		pMap[u].push_back(make_pair(v, w));

		pMap[v].push_back(make_pair(u, w));

	}

	Prim();

	return 0;

}



void Prim()

{

	int nCost = 0;

	vector<int> pMST;	// 储存MST的结点 

	int pCost[MAX];		// 储存与集合A相邻的顶点的最小权值，0表示该结点已经在MST中

	pMST.push_back(1);	// 将结点1加入MST

	pCost[1] = 0;

	for(int i = 2; i <= N; i++)	// 初始化，切记要将除1以外的都置为INF

	{ pCost[i] = INF; }	

	for(int i = 0; i < pMap[1].size(); i++)		// 处理与结点1相连的顶点

	{ pCost[pMap[1][i].first] = pMap[1][i].second; }

	for(int i = 1; i <= N - 1; i++)		// 剩余N-1个顶点，循环N-1次

	{

		int nVertex = 0, nWeight = INF;		// 用于寻找最短的边

		for(int j = 1; j <= N; j++)

		{

			if(nWeight > pCost[j] && pCost[j] != 0)

			{

				nVertex = j;

				nWeight = pCost[j];

			}

		}



		pCost[nVertex] = 0;

		pMST.push_back(nVertex);	// 将节点nVertex加入MST



		nCost += nWeight;	// 计算MST的费用



		for(int j = 0; j < pMap[nVertex].size(); j++)	// 更新pCost数组

		{

			if(pCost[pMap[nVertex][j].first] != 0 && 

				pCost[pMap[nVertex][j].first] > pMap[nVertex][j].second)

			{

				pCost[pMap[nVertex][j].first] = pMap[nVertex][j].second;

			}

		}

	}

	cout << "MST Cost is " << nCost << endl;

	cout << "The vertexs in MST are ";

	for(int i = 0; i < pMST.size(); i++)

	{ cout << pMST[i] << " "; } 

	cout << endl;

}
