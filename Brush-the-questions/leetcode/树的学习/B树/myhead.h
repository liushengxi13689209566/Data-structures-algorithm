/*************************************************************************
	> File Name: myhead.h
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2018年08月20日 星期一 22时01分54秒
 ************************************************************************/

#ifndef _MYHEAD_H
#define _MYHEAD_H
struct Node
{
	bool leaf;			  //是否是叶子节点
	int count;			  //keys 数目至多2t-1
	vector<int> keys;	 //保存keys
	vector<Node *> child; //保存孩子指针，至多keys+1
	Node(int t, bool _leaf)
	{
		leaf = _leaf;
		count = 0;
		keys = vector<int> tmp1(2 * t - 1);
		child = vector<Node *> tmp2(2 * t);
	}
};
class BTree
{
  private:
	int t; //t度的B树节点最多有2t个孩子，2t-1个关键字；m 阶的B树最多有m个孩子
	Node *root;

  private:
  public:
	BTree(int tmp);
	~Btree();
};
BTree::BTree(int tmp) : t(tmp), root(nullptr) {}
void BTree::split_child(Node *parent, int i, Node *child) //i 是干嘛的呐？？ 
{
	Node *z= new Node(t,child->leaf);
	for(int j =0 ;j < t-1 ;i++)
		z->keys[j] = child->keys[j+t] ;
	if(child->leaf ==  false ){
		for(int j= 0 ;j< t ;j++)
			z->child[j] = child->child[j+t]; //存储后面的东西
	}
	for(int j= parent->n ;j >= i+1 ;j--)
		
		 
}
void BTree::insert(int key)
{
	if (!root)
	{ //空树
		root = new Node(t, true);
		root->keys.push_back(key);
		root > n = 1;
	}
	else
	{
		if (root->n == 2 * t - 1) //如果根节点满了
		{
			Node *s = new Node(t, false); //不是叶子节点
			s->child.push_back(root);
			split_child(s,0,root); //一分为二







		}
	}
}
#endif
