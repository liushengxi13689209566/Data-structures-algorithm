/*************************************************************************
	> File Name: Trie.cpp
	> Author: Liu Shengxi 
	> Mail: 136892a9566@163.com
	> Created Time: 2a19年a1月25日 星期五 21时51分15秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <new>
#include <vector>
using namespace std;
class TrieNode
{
  public:
	explicit TrieNode(char data_t, bool end) : data_(data_t)
	{
		children_[26] = {nullptr};
		isEndingChar_ = end;
	}

  public:
	char data_;
	TrieNode *children_[26]; // a－z
	bool isEndingChar_;
};
class TrieTree
{
  public:
	TrieTree()
	{
		root = new TrieNode('/', false);
	}
	~TrieTree()
	{
		destroy(root);
	}
	void insertString(const string &str)
	{
		TrieNode *tmp = root;
		int num = str.size();
		for (int i = 0; i < num; i++)
		{
			int index = str[i] - 'a';
			if (!tmp->children_[index])
			{
				if (i != num - 1)
					tmp->children_[index] = new TrieNode(str[i], false);
				else
					tmp->children_[index] = new TrieNode(str[i], true);

			} // not null
			tmp = tmp->children_[index];
		}
	}
	int searchString(string str)
	{
		TrieNode *tmp = root;
		int index = 0;
		for (auto i : str)
		{
			index = i - 'a';
			if (!tmp->children_[index])
				return -1;
			tmp = tmp->children_[index];
		}
		if (tmp->isEndingChar_)
			return 0;
		else
			return 666;
	}

  private:
	class TrieNode *root;
	void destroy(TrieNode *root)
	{
		if (!root)
			return;
		for (int i = 0; i < 26; i++)
		{
			destroy(root->children_[i]);
		}
		delete root;
		root = nullptr;
	}
};
int main(void)
{

	TrieTree tree;
	string insertstrings[5] = {"how", "hi", "hello", "so", "see"};
	for (auto t : insertstrings)
	{
		tree.insertString(t);
	}

	cout << "Please input the strings :" << endl;
	string t1;

	// while (1)
	// {
	cin >> t1;
	switch (tree.searchString(t1))
	{
	case 0:
		cout << "success find " << endl;
		break;
	case -1:
		cout << "not find " << endl;
		break;
	case 666:
		cout << "is public substr " << endl;
		break;
	}
	// }
	return 0;
}
