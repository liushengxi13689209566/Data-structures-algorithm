/*************************************************************************
	> File Name: myhead.h
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2018年07月26日 星期四 22时59分58秒
 ************************************************************************/

#ifndef _MYHEAD_H
#define _MYHEAD_H
int test = 0; //用来测试destory()函数
template <class T>
class Node
{
public:
	int key = 0;
	Node *left = nullptr;
	Node *right = nullptr;
	Node(int key_t) : key(key_t), left(nullptr), right(nullptr) {}
};
template <typename T>
class BST
{
private:
	Node<T> *header; //header结点并非根结点，header->left指向的才是根结点。

	Node<T> *insert_real(int key, Node<T> *&node);
	Node<T> *&find_real(int key, Node<T> *&node);
	void in_order(Node<T> *node);
	int destory(Node<T> *p);
public:
	BST();
	~BST();
	Node<T> *insert(int key);
	// (递归实现)查找"二叉树"中键值为key的节点
	Node<T> *&find(int key);
	//(非递归实现)查找"二叉树"中键值为key的节点
	Node<T> *loop_find(T key);

	// 查找最小结点：返回最小结点的键值。
	T minimum();
	// 查找最大结点：返回最大结点的键值。
	// T maximum(); 思路同上

	void erase(int key);
	void print();
};
#endif
