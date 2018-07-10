#ifndef LIST_H
#define LIST_H

class List
{
private:
	typedef struct node
	{
		int data;
		node* next;
	}* nodePtr;

	nodePtr head;
	nodePtr curr;
	nodePtr temp;

public:
	List();
	//void addAtHead(int addData);
	void addAtIndex(int addData, int index);
	void addAtHead(int addData);
	void addAtTail(int addData);
	void DeleteNode(int delData);
	void PrintList();
};

#endif