#include <iostream>
#include <cstdlib>

#include "List.h"

using namespace std;
// struct SinglyListNode
// {
// 	int val;
// 	SinglyListNode *next;
// 	SinglyListNode(int x) : val(x), next(NULL){}
// };

int main(int argc, char** argv)
{
	List Test;
	Test.addAtHead(8);
	Test.addAtIndex(3,1);
	Test.addAtIndex(5,2);
	Test.addAtIndex(6,3);
	Test.addAtIndex(6,0);
	Test.addAtIndex(12,2);

	Test.PrintList();

	cout << "---------------------------" << endl;
	Test.DeleteNode(5);
	Test.PrintList();
	// cout << "Test........\n";
	// Test.addAtHead(8);
	// Test.addAtHead(9);
	// Test.addAtTail(7);
	// Test.addAtTail(0);
	// Test.addAtTail(1);
	// Test.PrintList();

	// int get = Test.get(12);
	// cout << "Data found at index = " << get << endl;
}