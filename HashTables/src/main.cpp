#include <cstdlib>
#include <iostream>
#include <string>

#include "hash.h"

using namespace std;

int main(int argc, char** argv)
{
	hash Hash;

	string name = "";

	Hash.AddItem("Jonathan", "Red wine");
	Hash.AddItem("Joseph", "Coke");
	Hash.AddItem("Jotaro", "Beer");
	Hash.AddItem("Josuke", "IV fluid");
	Hash.AddItem("Giorno", "Wine");
	Hash.AddItem("Jolyne", "Water");
	Hash.AddItem("Johnny", "Water");

	Hash.PrintTable();

	// Hash.PrintItemsInIndex(14);


	while(name != "exit")
	{
		cout << "Remove ";
		cin >> name;
		if(name != "exit")
		{
			Hash.RemoveItem(name);
			Hash.PrintTable();
		}
	}

	return 0;
}