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
	node* ReturnNodePrivate(int key, node* Ptr);


public:

	BST();
	void AddLeaf(int key);
	void PrintInOrder();
	node* ReturnNode(int key);
	int ReturnRootKey();
	void PrintChildren(int key);

};

#endif