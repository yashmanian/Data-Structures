#include <cstdlib>
#include <iostream>

#include "List.h"

using namespace std;

List::List()
{
	head = NULL;
	curr = NULL;
	temp = NULL;
}

void List::addAtIndex(int addData, int index)
{
	nodePtr n = new node;
	n->next = NULL;
	n->data = addData;
	curr = head;
	temp = curr->next;
	if(index == 1)
	{
		List::addAtHead(addData);
	}
	else
	{
		int i = 1;
		while(i<index && curr != NULL)
		{
			curr = curr->next;
			temp = curr->next;
			i++;
		}
		if(curr == NULL)
		{
			cout << "Index was not in list\n";
			delete n;
		}
		else
		{
			curr->next = n;
			n->next = temp;
		}
	}

}

void List::addAtHead(int addData)
{
	nodePtr n = new node;
	n->data = addData;
	if (head != NULL)
	{
		n->next = head;
		head = n;
	}
	else
	{
		head = n;
	}
}


void List::addAtTail(int addData)
{
	nodePtr n = new node;
	n->data = addData;
	curr = head;
	while(curr->next != NULL)
	{
		temp = curr;
		curr = curr->next;
	}
	curr->next = n;
	n->next = NULL;
}

void List::DeleteNode(int delData)
{
	nodePtr delPtr = NULL;
	temp = head;
	curr = head;
	while(curr != NULL && curr->data != delData)
	{
		temp = curr;
		curr = curr->next;
	}
	if(curr == NULL)
	{
		cout << delData << " was not in list\n";
		delete delPtr;
	}
	else
	{
		delPtr = curr;
		curr = curr->next;
		temp->next = curr;
		if(delPtr == head)
		{
			head = head->next;
			temp = NULL;
		}
		delete delPtr;
		cout << "The value " << delData << " was deleted\n";
	}
}

void List::PrintList()
{
	curr = head;
	while(curr != NULL)
	{
		cout << curr->data << endl;
		curr = curr->next;
	}
}