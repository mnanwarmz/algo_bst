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
		{
			r->l = insert(r->l, v);
		}
		else if (v >= r->d)
		{
			r->r = insert(r->r, v);
		}
		return r;
	}

	node *deleteItem(node *p, int v)
	{
		if (p == NULL)
			return p;

		if (v < p->d) //to find the value whether less or more
			p->l = deleteItem(p->l, v);
		else
		{
			if (v > p->d)
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
		}
		return p;
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
