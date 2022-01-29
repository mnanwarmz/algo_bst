// avl.cpp
#include <iostream>
using namespace std;

struct node //node declaration
{
	int d;
	struct node *l;
	struct node *r;
};

class avl
{
public:
	struct node *root;

	node *rightrotate(node *p)
	{
		node *temp = p->l;
		p->l = temp->r;
		temp->r = p;

		return temp;
	}

	node *leftrotate(node *p)
	{
		node *temp = p->r;
		p->r = temp->l;
		temp->l = p;

		return temp;
	}

	node *leftrightrotate(node *p)
	{
		node *temp = p->l;
		p->l = leftrotate(temp);

		return rightrotate(p);
	}

	node *rightleftrotate(node *p)
	{
		node *temp = p->r;
		p->r = rightrotate(temp);

		return leftrotate(p);
	}

	int height(node *p)
	{
		int h = 0;
		if (p != NULL)
		{
			int l_height = height(p->l);
			int r_height = height(p->r);
			h = max(l_height, r_height) + 1; //plus 1 to include the current height
		}
		return h;
	}

	int balance_factor(node *p)
	{
		int l_height = height(p->l);
		int r_height = height(p->r);

		return (r_height - l_height);
	}

	node *balance(node *p)
	{
		int bf = balance_factor(p);
		if (bf < -1)
		{
			if (balance_factor(p->l) < 0)
				p = rightrotate(p);
			else
				p = leftrightrotate(p);
		}
		else if (bf > 1)
		{
			if (balance_factor(p->r) < 0)
				p = rightleftrotate(p);
			else
				p = leftrotate(p);
		}
		return p;
	}

	node *insert(node *r, int v)
	{
		// recursively call the insert function – refer to algorithm
		if (r == NULL)
		{
			r = new node;
			r->d = v;
			r->l = NULL;
			r->r = NULL;
			return r;
		}
		else if (v < r->d)
			r->l = insert(r->l, v);
		else if (v >= r->d)
			r->r = insert(r->r, v);
		r = balance(r);
		return r;
	}

	node *deleteItem(node *p, int v)
	{
		if (p == NULL)
			return p;

		if (v < p->d) //to find the value whether less or more
			p->l = deleteItem(p->l, v);
		else if (v > p->d)
			p->r = deleteItem(p->r, v);
		else
		{
			if ((p->l == NULL) && (p->r == NULL)) // no child
				p = NULL;
			else if ((p->l == NULL) || (p->r == NULL)) // one child
			{
				node *temp;
				if (p->r != NULL)
					temp = p->r;
				else
					temp = p->l;
				p = temp;
			}
			else // two child nodes
			{
				// use getSuccessor() here
				node *temp = getSuccessor(p->l);
				p->d = temp->d;					  //delete old node replace data
				p->l = deleteItem(p->l, temp->d); //find the data that replaced the old one and remove it
			}
		}

		if (p != NULL)
			p = balance(p);
	}

	node *getSuccessor(node *p) // used in delete function
	{
		if (p->r == NULL)
			return p;
		else
			return (getSuccessor(p->r));
	}

	void show(node *p, int lvl)
	{
		int i;
		if (p != NULL)
		{
			if (p == root)
				cout << "Root: " << p->d << endl;
			else
				cout << p->d << endl;
			cout << lvl << "L: ";
			show(p->l, lvl + 1);
			cout << "\n"
				 << lvl << "R: ";
			show(p->r, lvl + 1);
		}
	}

	void showOrder(node *p)
	{
		cout << "\nInorder: ";
		inOrder(p);
		cout << "\nPreorder: ";
		preOrder(p);
		cout << "\nPostorder: ";
		postOrder(p);
		cout << endl;
	}

	void preOrder(node *p)
	{
		if (p != NULL)
		{
			cout << p->d << " ";
			preOrder(p->l);
			preOrder(p->r);
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

	void inOrder(node *p)
	{
		if (p != NULL)
		{
			inOrder(p->l);
			cout << p->d << " ";
			inOrder(p->r);
		}
	}

	avl()
	{
		root = NULL;
	}
};
