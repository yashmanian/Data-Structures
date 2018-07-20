#include "hash.h"

hash::hash()
{
	for(int i = 0; i < tableSize; i++)
	{
		HashTable[i] = new item;
		HashTable[i]->name = "empty";
		HashTable[i]->drink = "empty";
		HashTable[i]->next = NULL;
	}
}


int hash::Hash(string key)
{
	int hash = 0;
	int index;

	for(int i = 0; i < key.length(); i++)
	{
		hash = (hash + (int)key[i]) * 17; 
	}

	index = hash % tableSize;
	
	return index;
}

void hash::AddItem(string name, string drink)
{
	int index = Hash(name);

	if(HashTable[index]->name == "empty")
	{
		HashTable[index]->name = name;
		HashTable[index]->drink = drink;
	}
	else
	{
		item* Ptr = HashTable[index];
		item* n = new item;
		n->name = name;
		n->drink = drink;
		n->next = NULL;

		while(Ptr->next != NULL)
		{
			Ptr = Ptr->next;
		}

		Ptr->next = n;
	}
}

int hash::NumberOfItemsInIndex(int index)
{
	int count = 0;
	if(HashTable[index]->name == "empty")
	{
		return count;
	}
	else
	{
		count++;
		item* Ptr = HashTable[index];
		while(Ptr->next != NULL)
		{
			Ptr = Ptr->next;
			count++;
		}
		return count;
	}
}

void hash::PrintTable()
{
	int number;

	for(int i = 0; i < tableSize; i++)
	{
		number = NumberOfItemsInIndex(i);
		cout << "---------------------\n";
		cout << "index = " << i << endl;
		cout << HashTable[i]->name << endl;
		cout << HashTable[i]->drink << endl;
		cout << "Number of Items = " << number << endl;
		cout << "---------------------\n";

	}
}

void hash::PrintItemsInIndex(int index)
{
	item* Ptr = HashTable[index];
	if(Ptr->name == "empty")
	{
		cout << "Bucket " << index << " is empty" << endl;
	}
	else
	{
		cout << "Bucket " << index << " contains the following items\n";

		 while(Ptr != NULL)
		 {
		 	cout << "---------------------\n";
		 	cout << Ptr->name << endl;
		 	cout << Ptr->drink << endl;
		 	cout << "---------------------\n";
		 	Ptr = Ptr->next;
		 }
	}
}


void hash::FindDrink(string name)
{
	int index = Hash(name);

	bool foundName = false;
	string drink;

	item* Ptr = HashTable[index];
	while(Ptr != NULL)
	{
		if(Ptr->name == name)
		{
			foundName = true;
			drink = Ptr->drink;
		}
		Ptr = Ptr->next;
	}

	if (foundName == true)
	{
		cout << "Favorite drink = " << drink << endl;
	}
	else
	{
		cout << name << "'s was not found in the Hash Table\n";
	}
}


void hash::RemoveItem(string name)
{
	int index = Hash(name);
	
	item* delPtr;
	item* P1;
	item* P2;

	// Case 0 - Bucket is empty
	if(HashTable[index]->name == "empty" && HashTable[index]->drink == "empty")
	{
		cout << name << " was not found in the Hash table\n";
	}

	// Case 1 - Only one item contained in Bucket with Matching name
	else if(HashTable[index]->name == name && HashTable[index]->next == NULL)
	{
		HashTable[index]->name = "empty";
		HashTable[index]->drink = "empty";
		cout << name << " was removed from Hash Table\n";
	}

	// Case 2 - There is a match in the very first item in the bucket, but there are additional items in the bucket
	else if(HashTable[index]->name == name && HashTable[index]->next != NULL)	
	{
		delPtr = HashTable[index];
		HashTable[index] = HashTable[index]->next;
		delete delPtr;

		cout << name << " was removed from Hash Table\n";
	}

	// Case 3 - Bucket contains items, but the first item isn't a match
	else
	{
		P1 = HashTable[index]->next;
		P2 = HashTable[index];

		while(P1 != NULL && P1->name != name)
		{
			P2 = P1;
			P1 = P1->next;
		}

		// Case 3.1 - There isn't a match in all the items in the bucket
		if(P1 == NULL)
		{
			cout << name << " was not found in the Hash table\n";
		}

		// Case 3.2 - There is a match in one of the items in the bucket
		else
		{
			delPtr = P1;
			P1 = P1->next;
			P2->next = P1;
			delete delPtr;
			cout << name << " was removed from Hash Table\n";
		}
	}
}