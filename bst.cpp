// bst.cpp
#include <iostream>
using namespace std;

struct node //node declaration
{
	int d;
	struct node *l;
	struct node *r;
};

class bst
{
public:
	struct node *root;

	node *insert(node *r, int v)
	{
		if (r == NULL)
		{
			r = new node;
			r->d = v;
			r->l = NULL;
			r->r = NULL;
		}
		else if (v < r->d)
			r->l = insert(r->l, v);
		else
			r->r = insert(r->r, v);
		return r;
	}

	node *deleteItem(node *p, int v)
	{
		if (p == NULL)
			return p;

		if (v < p->d)
			p->l = deleteItem(p->l, v);
		else
		{
			if (v > p->d)
				p->r = deleteItem(p->r, v);
			else
			{
				if (p->l == NULL && p->r == NULL)
				{
					delete p;
					p = NULL;
				}
				else if (p->l == NULL)
				{
					node *temp = p;
					p = p->r;
					delete temp;
				}
				else if (p->r == NULL)
				{
					node *temp = p;
					p = p->l;
					delete temp;
				}
				else
				{
					node *temp = p;
					p = getSuccessor(p);
					delete temp;
				}
			}
		}
		return p;
	}

	node *getSuccessor(node *p) // used in delete function
	{
		node *current = p->r;
		node *successor = p;
		while (current != NULL)
		{
			successor = current;
			current = current->l;
		}
		return successor;
	}

	node *find(node *p, int v)
	{
		if (p == NULL)
			return p;
		if (v < p->d)
			return find(p->l, v);
		else if (v > p->d)
			return find(p->r, v);
		else
			return p;
	}

	int height(node *p)
	{
		if (p == NULL)
			return 0;
		else
		{
			int lh = height(p->l);
			int rh = height(p->r);
			if (lh > rh)
				return (lh + 1);
			else
				return (rh + 1);
		}
	}

	int balanceFactor(node *p)
	{
		if (p == NULL)
			return 0;
		else
			return (height(p->l) - height(p->r));
	}

	node *balance()
	{
		int h = height(root);
		if (h > 1)
		{
			if (balanceFactor(root->l) > 0)
				root->l = leftRotate(root->l);
			root = rightRotate(root);
		}
		else if (h < -1)
		{
			if (balanceFactor(root->r) < 0)
				root->r = rightRotate(root->r);
			root = leftRotate(root);
		}
		return root;
	}

	node *leftRotate(node *p)
	{
		node *q = p->r;
		p->r = q->l;
		q->l = p;
		return q;
	}

	node *rightRotate(node *p)
	{
		node *q = p->l;
		p->l = q->r;
		q->r = p;
		return q;
	}

	node *leftRightRotate(node *p)
	{
		p->l = leftRotate(p->l);
		return rightRotate(p);
	}

	node *rightLeftRotate(node *p)
	{
		p->r = rightRotate(p->r);
		return leftRotate(p);
	}

	void inorder(node *p)
	{
		if (p != NULL)
		{
			inorder(p->l);
			cout << p->d << " ";
			inorder(p->r);
		}
	}

	void preorder(node *p)
	{
		if (p != NULL)
		{
			cout << p->d << " ";
			preorder(p->l);
			preorder(p->r);
		}
	}

	void postOrder(node *p)
	{
		if (p != NULL)
		{
			postOrder(p->l);
			postOrder(p->r);
			cout << p->d << " ";
		}
	}

	void show(node *p, int lvl)
	{
		int i;
		if (p != NULL)
		{
			if (p == root)
				cout << "Root: " << p->d << endl;
			else
			{
				cout << p->d << endl;
			}
			cout << lvl << "L: ";
			show(p->l, lvl + 1);
			cout << "\n"
				 << lvl << "R: ";
			show(p->r, lvl + 1);
		}
	}

	bst()
	{
		root = NULL;
	}
};
