/*************************************************************************
	> File Name: test.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2018年08月01日 星期三 09时39分31秒
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
class Node
{
  public:
	int x, y;
	bool operator=(Node temp)
	{
		return x == temp.x && y == temp.y;
	}
	Node() = default;
	Node(int _x, int _y) : x(_x), y(_y) {}
};
int main(void) {
	Node start(0,0);
	Node end(4,4);
	queue<Node> QQ ;
	QQ.push(start);
	Node temp = QQ.front();
	cout<< temp.x << temp.y <<  endl;
}

