Node *&AVL::find(int key)
{
	return find_real(key, header->left);
}

Node *AVL::loop_find(T key)
{
	Node *p = header->left; // p 指向根节点
	while (p->key != key)
	{
		if (key <= p->key)
			p = p->left;
		else
			p = p->right;
	}
	return p;
}

Node *&AVL::find_real(int key, Node *&node)
{
	if (node == nullptr)
		return node;
	if (key < node->key)
		find_real(key, node->left);
	else if (key > node->key)
		find_real(key, node->right);
	else // 只剩下相等了
		return node;
}

void AVL::erase(int key)
{
	Node *p = find_real(key, header->left);
	if (p)
	{
		Node *t = p;
		if (t->left && t->right)
		{
			/* 左右都有的情况*/
			/* 找到  x ，y */
			Node *y = t;
			Node *x = t->right;
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





void AVL::print()
{
	in_order(header->left);
}

void AVL::in_order(Node *root)
{
	if (root == nullptr)
		return;
	in_order(root->left); //先打印右子树
	cout << root->key << "  ";
	in_order(root->right);
	return;
}
