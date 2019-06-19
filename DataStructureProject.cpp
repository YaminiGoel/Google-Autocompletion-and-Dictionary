// DataStructureProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "fstream"
#include "string.h"
#include "singlyll.h"
#include "dictionary.h"


using namespace std;


int main()
{
	char
		choice[50];

	int
		found;

	ifstream
		obj;

	SinglyLL
		print;

	cout << "To exit program, please type exit.\n";

	do
	{
		print.truncateList();

		cout << "\n\n\nEnter a word to be searched: ";
		cin.getline(choice, 50);

		cout << "\n";

		if (!strcmp(choice, "exit"))
		{
			return 0;
		}

		if (!strcmp(choice, "\0"))
		{ 
			continue;
		}

		found = findWord(choice);

		if (found != -1)
		{
			cout << "Match found!\n" << choice << " - ";
			printWordDesc(found);
			cout << "\n\nRelated searches: ";
			found = printRelatedWords(choice);
			if (!found)
			{
				cout << "None\n";
			}
			continue;
		}
		else
		{
			findWords(choice, print);

			found = print.numElements();

			if (!print.isEmpty())
			{
				int
					tmp;

				cout << "\nNo exact match found... Did you mean\n\n";
				for (int i = 0; i < found; ++i)
				{
					tmp = print.deleteFromHead();
					printWord(tmp);
					//cout << " - ";
					//printworddesc(tmp);
					cout << "\n";
				}
			}
			else
			{
				cout << "No match found....\n";
			}
		}


	} while (1);
	return 0;
}