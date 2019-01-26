/*************************************************************************
	> File Name: Trie.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2019年01月25日 星期五 21时51分15秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <new>
using namespace std;
class TrieNode
{
  public:
	TrieNode(char data_t) : data_(data_t), isEndingChar_(false)
	{
		children_[26] = {0};
	}

  public:
	char data_ = 0;
	TrieNode *children_[26] = {0}; // a－z
	bool isEndingChar_ = false;
};
class TrieTree
{
  public:
	TrieTree()
	{
		root = new TrieNode('/');
	}
	void insertString(string str)
	{
		for (auto i : str)
		{
			if (root->children_[i - '0'])
				root->children_[i - '0'] = new TrieNode('i');
		}
	}
	void searchString(string str)
	{
	}

  private:
	class TrieNode *root;
};
int main(void)
{

	TrieTree tree;
	string insertstring[100] = {"how", "hi", "hello", "so", "see"};
	for (auto t : insertstring)
	{
		tree.insertString(t);
	}

	cout << "Please input the string :" << endl;
	string t1;
	cin >> t1;
	tree.searchString(t1);
}
