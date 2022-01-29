#include <iostream>

#include "bst.cpp"

using namespace std;

int main()
{
	int c, i;
	bst tree;
	while (1)
	{
		cout << "1.Insert Element into the tree" << endl;
		cout << "2.Delete Element" << endl;
		cout << "3.Show Binary Search Tree" << endl;
		cout << "4.Exit" << endl;
		cout << "Enter your Choice: ";
		cin >> c;
		switch (c) //perform switch operation
		{
		case 1:
			cout << "Enter value to be inserted: ";
			cin >> i;
			tree.root = tree.insert(tree.root, i);
			break;
		case 2:
			cout << "Enter value to be deleted: ";
			cin >> i;
			tree.root = tree.deleteItem(tree.root, i);
			break;
		case 3:
			if (tree.root == NULL)
			{
				cout << "Tree is Empty" << endl;
				continue;
			}
			cout << "Tree:" << endl;
			tree.show(tree.root, 1);
			cout << endl;
			break;
		case 4:
			exit(1);
			break;
		default:
			cout << "Wrong Choice" << endl;
		}
	}
	return 0;
}
