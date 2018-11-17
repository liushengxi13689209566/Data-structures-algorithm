/*************************************************************************
	> File Name: frist.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2018年07月25日 星期三 20时53分30秒
 ************************************************************************/

#include <iostream>
#include "myhead.h"
using namespace std;
/*
线索二叉树也是在树的头节点上面补上一个指引节点之后就变得简单了，
可能就跟链表带头接点一样，会简化大部分的树的问题，需要总结哦 
*/
template <typename T>
BST<T>::BST()
{
	header = new Node<T>(-100);
}
template <typename T>
BST<T>::~BST()
{
	destory(header);
}
template <typename T>
int BST<T>::destory(Node<T> *p)
{
	if (p == nullptr)
		return 0;
	test++;
	cout << "test ==  " << test << endl; //顺带吧多申请的那个节点也释放了 
	destory(p->left); //注意先后次序，如果先把p销毁，那么就会找不到p->left,p->right
	destory(p->right);
	delete p;
	p = nullptr;
}
template <typename T>
Node<T> *BST<T>::insert(int key)
{
	return insert_real(key, header->left);
}
template <typename T>
Node<T> *BST<T>::insert_real(int key, Node<T> *&node)
{
	if (node == nullptr)
		return node = new Node<T>(key);
	if (key <= node->key)
		insert_real(key, node->left);
	else if (key > node->key)
		insert_real(key, node->right);
	else
		return nullptr;
}
template <typename T>
void BST<T>::print()
{
	in_order(header->left);
}
template <typename T>
void BST<T>::in_order(Node<T> *root)
{
	if (root == nullptr)
		return;
	in_order(root->left);
	cout << root->key << "  ";
	in_order(root->right);
}
template <typename T>
Node<T> *&BST<T>::find(int key)
{
	return find_real(key, header->left);
}
template <typename T>
Node<T> *BST<T>::loop_find(T key)
{
	Node<T> *p = header->left; // p 指向根节点
	while (p->key != key)
	{
		if (key <= p->key)
			p = p->left;
		else
			p = p->right;
	}
	return p;
}
template <typename T>
Node<T> *&BST<T>::find_real(int key, Node<T> *&node)
{
	if (node == nullptr)
		return node;
	if (key <  node->key)
		find_real(key, node->left);
	else if (key > node->key)
		find_real(key, node->right);
	else // 只剩下相等了
		return node;
}
template <typename T>
void BST<T>::erase(int key)
{
	Node<T> *&p = find_real(key, header->left);
	if (p)
	{
		Node<T> *t = p;
		if (t->left && t->right)
		{
			/* 左右都有的情况*/
			/* 找到  x ，y */
			Node<T> *y = t;
			Node<T> *x = t->right;
			while (x->left)
			{
				y = x;
				x = x->left;
			}
			/*改变 y 的指向*/
			if (y == t) // y 与 t 重合的情况
				y->right = x->right;
			else
				y->left = x->right;
			/* 将 x 给 t */
			p = x;
			/* 改变 x 的 left 和  right */
			x->left = t->left;
			x->right = t->right;
		}
		else
		{
			p = t->left ? t->left : t->right;
		}
		delete t;
	}
	else
	{
		cout << key << "不存在二叉查找树中 !!!" << endl;
	}
	return;
}
template <class T>
T BST<T>::minimum()
{
	Node<T> *p = header->left;
	if (p)
	{
		while (p->left)
		{
			p = p->left;
		}
		return p->key;
	}
	else
	{
		cout << "这是一个空的二叉查找树 ！！" << endl;
		return T(-100);
	}
}
int main(void)
{
	BST<int> bst;
	bst.insert(3);
	bst.insert(9);
	bst.insert(8);
	bst.insert(7);
	bst.insert(16);
	bst.insert(15);
	bst.insert(19);
	bst.insert(14);
	bst.insert(10);
	bst.insert(11);

	bst.insert(8); //测试重复数字

	bst.print(); //中序遍历
	cout << endl;

	// test "find"
	Node<int> *p = nullptr;
	cout << ((p = bst.find(9)) ? p->key : -1) << endl;	 //   9 
	cout << ((p = bst.find(100)) ? p->key : -666) << endl; // -666

	cout << ((p = bst.loop_find(14)) ? p->key : -1) << endl; // 14

	cout << "min number == " << bst.minimum() << endl; // 3

	// test "erase"
	bst.erase(16); // 测试 y 与 t 重合的情况
	bst.print(); 
	cout << endl;


	bst.erase(9);
	bst.print();  
	cout << endl;

	bst.erase(1000);
	bst.erase(7);
	bst.print();  
	cout << endl;


	return 0;
}
