#include <cstdlib>
#include <iostream>

#include "List.h"

using namespace std;

List::List()
{
	head = NULL;
	curr = NULL;
	temp = NULL;
	length = 0;
}

void List::addAtIndex(int addData, int index)
{
	nodePtr n = new node;
	n->next = NULL;
	n->data = addData;
	curr = head;
	temp = curr;
	int count = 0;

	while(curr != NULL)
	{
		if(index == 0)
		{
			addAtHead(addData);
			//length = length + 1;
			break;
		}
		else if(index == length)
		{
			addAtTail(addData);
			//length = length + 1;
			
			break;
		}
		else if(index > length)
		{
			cout << "Index greater than List length!" << endl;
			break; 
		}
		else if(count == index)
		{
			temp->next = n;
			n->next = curr;
			length = length + 1;
			cout << "Node added at index = " << count << ", List length = " << length << endl;
			break;
		}
		temp = curr;
		curr = curr->next;
		count++;
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
	length = length + 1;
	cout << "Node added at head, List length = " << length << endl;
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
	length = length + 1;
	cout << "Node added at tail, List length = " << length << endl;
}

void List::DeleteNode(int index)
{
	nodePtr delPtr = NULL;
	curr = head;
	temp = curr;
	int count = 0;
	while(curr != NULL)
	{
		if(index == 0)
		{
			delPtr = head;
			head = head->next;
			delete delPtr;
			length--;
			break;
		}
		else if(index > length - 1)
		{
			cout << "Index greater than List length!" << endl;
			break; 
		}
		else if(count == index)
		{
			delPtr = curr;
			temp->next = curr->next;
			delete delPtr;
			break;
		}
		temp = curr;
		curr = curr->next;
		count++;
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

int List::get(int index)
{
	curr = head;
	int data = 0;
	int count = 0;
	while(curr != NULL)
	{
		if(count == index)
		{
			data = curr->data;
			break;
		}
		curr = curr->next;
		count++;
	}

	if(curr == NULL)
	{
		data = -1;
	}
	return data;
}
