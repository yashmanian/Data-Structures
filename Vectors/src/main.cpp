#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	// Format: vector<DataType> nameOfVector
	vector<int> myVector;

	myVector.push_back(1);
	myVector.push_back(2);
	myVector.push_back(3);
	myVector.push_back(4);
	myVector.push_back(5);
	myVector.push_back(6);
	myVector.push_back(7);
	myVector.push_back(8);

	cout << "Vector: " << endl;

	for(unsigned int i = 0; i<myVector.size(); i++)
	{
		cout << myVector[i] << " ";
	}

	cout << endl;

	// Rotated Vector
	cout << "Rotated Vector: ";
	vector<int> RotVector;
	int d = 3;
	for(unsigned int i = 0; i<myVector.size(); i++)
	{
		unsigned int idx = (i + d) % myVector.size();
		RotVector.push_back(myVector[idx]);
		cout << RotVector[i] << " " << "Index: " << idx << endl;
	}

	// Char subtraction

	// char a = 'a';
	// char b = 'z';

	// cout << "Char subtract: " << endl;
	// cout << a-b << endl; 

	// Comparison
	vector<int> string1(26,0);
	vector<int> string2(26,0);
	
	// String compare
	string str1 = "fcrxzwscanmligyxyvym";
	string str2 = "jxwtrhvujlmrpdoqbisbwhmgpmeoke";
	cout << "String 1: " << str1 << endl;
	cout << "String 2: " << str2 << endl;

	cout << "String 1 idx: " << endl;
	for(unsigned int i = 0; i< str1.size(); i++)
	{
		int freqPtr = str1[i] - 'a';
		cout << freqPtr << endl;
		string1[freqPtr]++;
	}

	cout << "String 2 idx: " << endl;
	for(unsigned int i = 0; i< str2.size(); i++)
	{
		int freqPtr = str2[i] - 'a';
		cout << freqPtr << endl;
		string2[freqPtr]++;
	}

	int count = 0;
	for (unsigned int i = 0; i<string1.size(); i++)
	{
		if (string1[i] != 0 && string2[i] != 0)
		{
			int diff = 0;
			if(string1[i] != string2[i])
			{
				if(string1[i] < string2[i])
				{
					diff = string1[i];
				}
				else
				{
					diff = string2[i];
				}
			}
			else 
			{
				diff = string1[i];
			}
			count = count + diff;
			cout << "compare: " << i << endl;
		}
	}

	cout << "Vector compare: " << endl;
	for(int i = 0; i < string1.size(); i++)
	{
		cout << "Idx: " << i << " String : " <<  string1[i] << " " << string2[i] << endl; 	
	}

	cout << "Compared value: " << count << endl;
}