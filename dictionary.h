
#ifndef _DICTIONARY_INC
#define _DICTIONARY_INC

#define MAX_WORD 50
#define MAX_DESC 200

/*
int findWord(char word[])
void printWord(int pos)
void printWordDesc(int pos)
void findWords(char word[], SinglyLL &obj2)
int printRelatedWords(char word[])
*/

int findWord(char word[]) // finds exact word
{
	char
		ch,
		tmp[MAX_WORD];

	int
		i = 0,
		found = 0,
		len = strlen2(word),
		pos = 0;

	ifstream
		obj;

	obj.open("dictionary.txt", ios::in);

	while (!obj.eof())
	{
		ch = obj.get();
		if (ch == ';')
		{
			found = 1;
			tmp[i] = '\0';

			if (!strcmp2(word, tmp))
			{
				obj.close();
				return pos;
			}
			continue;
		}
		if (ch == '\n')
		{
			found = 0;
			i = 0;

			pos = obj.tellg();
			//++pos;
			continue;
		}

		if (!found)
		{
			tmp[i] = ch;
			++i;
		}
	}

	obj.close();
	return -1;
}

void printWord(int pos)
{
	char
		ch,
		tmp[MAX_WORD];

	int
		i = 0,
		found = 0;

	ifstream
		obj;

	obj.open("dictionary.txt", ios::in);
	
	obj.seekg(pos, ios::beg);

	while (!obj.eof())
	{
		ch = obj.get();
		if (ch == ';')
		{
			found = 1;
			tmp[i] = '\0';

			cout << tmp;

			obj.close();
			return;
		}
		if (!found)
		{
			tmp[i] = ch;
			++i;
		}
	}

	obj.close();
	return;
}

void printWordDesc(int pos)
{
	char
		ch,
		tmp[MAX_DESC];

	int
		i = 0,
		found = 0;

	ifstream
		obj;

	obj.open("dictionary.txt", ios::in);

	obj.seekg(pos, ios::beg);

	while (!obj.eof())
	{
		ch = obj.get();

		if (ch == ';')
		{
			found = 1;
			continue;
		}
		if (ch == '\n')
		{
			tmp[i] = '\0';
			cout << tmp;

			obj.close();
			return;
		}
		if ((found))
		{
			tmp[i] = ch;
			++i;
		}
	}

	obj.close();
	return;
}

void findWords(char word[], SinglyLL &obj2)
{
	char
		ch,
		tmp[MAX_WORD];

	int
		i = 0,
		found = 0,
		pos = 0;

	ifstream
		obj;

	SinglyLL
		nop;

	obj.open("dictionary.txt", ios::in);

	while (!obj.eof())
	{
		ch = obj.get();
		//cout << ch;
		if (ch == ';')
		{
			found = 1;
			tmp[i] = '\0';

			if (_strfind(tmp, word) && !nop.isInList(pos))
			{
				char
					tmp2[MAX_WORD];

				int
					pos2 = 0,
					j = 0;

				obj2.addToHead(pos);
				pos = obj.tellg();

				obj.seekg(0, ios::beg);
				obj.clear();
				while (!obj.eof())
				{
					ch = obj.get();
					if (ch == ';')
					{
						found = 1;
						tmp2[j] = '\0';
						if (strfind2(tmp2, tmp) && strcmp(tmp2, tmp))
						{
							nop.addToHead(pos2);
							continue;
						}
					}
					if (ch == '\n')
					{
						found = 0;
						j = 0;

						pos2 = obj.tellg();
						//++pos2;
						continue;
					}
					if (!found)
					{
						tmp2[j] = ch;
						++j;
					}
				}
				obj.clear();
				obj.seekg(pos, ios::beg);
			}
			continue;
		}
		if (ch == '\n')
		{
			found = 0;
			i = 0;

			pos = obj.tellg();
			//++pos;
			continue;
		}

		if (!found)
		{
			tmp[i] = ch;
			++i;
		}
	}
	if (!nop.isEmpty())
	{
		int
			t;

		pos = nop.numElements();
		while ( pos != 0 )
		{
			try
			{
				t = nop.deleteFromHead();
			}
			catch (char s[])
			{
				cout << "Exception occured: " << s;
				cout << "\nExiting...";
				break;
			}
			--pos;

			if (obj2.isInList(t))
			{
				obj2.deleteElement(t);
			}
		}
	}


	obj.close();
	return;
}

int printRelatedWords(char word[])
{
	char
		ch,
		tmp[MAX_WORD];

	int
		i = 0,
		found = 0,
		count = 0,
		len = strlen2(word);

	ifstream
		obj;

	obj.open("dictionary.txt", ios::in);

	while (!obj.eof())
	{
		ch = obj.get();
		if (ch == ';')
		{
			found = 1;
			tmp[i] = '\0';

			if (strfind2(tmp, word) && strcmp(tmp, word))
			{
				++count;
				cout << tmp << " - ";
			}
			continue;
		}
		if (ch == '\n')
		{
			found = 0;
			i = 0;

			//++pos;
			continue;
		}
		if (!found)
		{
			tmp[i] = ch;
			++i;
		}
	}

	obj.close();
	return count;
}


#endif