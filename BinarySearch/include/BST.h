#ifndef BST_H
#define BST_H

class BST
{
private:
	struct node
	{
		int key;
		node* left;
		node* right;
	};

	node* root;
	node* CreateLeaf(int key);
	void AddLeafPrivate(int key, node* Ptr);
	void PrintInOrderPrivate(node* Ptr);

public:

	BST();
	void AddLeaf(int key);
	void PrintInOrder();

};

#endif