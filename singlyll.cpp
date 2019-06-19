#include "stdafx.h"
#include "SinglyLL.h"

/*
bool isEmpty();
bool isInList(int _ele);
void addToHead();
int deleteFromHead();
int deleteFromTail();
bool truncateList();
int numElements();
*/

bool SinglyLL::isEmpty()
{
	if (head == NULL)
	{
		return 1;
	}
	return 0;
}

bool SinglyLL::isInList(int _ele)
{
	if (isEmpty())
	{
		return 0;
	}

	Node
		*temp = head;

	while (temp != 0)
	{
		if (temp->ele == _ele)
		{
			return 1;
		}
		temp = temp->next;
	}
	return 0;
}

void SinglyLL::addToHead(int _ele)
{
	Node
		*temp = new Node(_ele);

	if (isEmpty())
	{
		head = tail = temp;
		return;
	}

	temp->next = head;
	head = temp;
	return;
}



int SinglyLL::deleteFromHead()
{
	if (isEmpty())
	{
		char 
			s[] = "List is empty";

		throw s;
	}

	Node
		*tmp = head;
	int
		del = tmp->ele;

	head = head->next;

	delete tmp;

	if (isEmpty())
	{
		tail = 0;
	}

	return del;
}

 void SinglyLL::truncateList()
{
	if (isEmpty())
	{
		head = tail = 0;
		return;
	}

	Node
		*tmp = head,
		*tmp2;

	do
	{
		tmp2 = tmp;
		tmp = tmp->next;
		delete tmp2;

	} while (tmp != 0);
	
	head = tail = 0;
	return;
}


int SinglyLL::numElements()
{
	if (isEmpty())
	{
		return 0;
	}
	int
		i = 0;

	Node
		*temp = head;

	do
	{
		++i;
		temp = temp->next;
	} while (temp != 0);
	return i;
}

bool SinglyLL::deleteElement(int _ele)
{
	if (isEmpty())
	{
		char
			s[] = "List is empty";

		throw s;
	}
	if (numElements() == 1)
	{
		if (head->ele == _ele)
		{
			delete head;
			head = tail = 0;
			return 1;
		}
		return 0;
	}

	Node
		*temp = head;

	do
	{
		if ((temp->next)->ele == _ele)
		{
			Node *tmp2 = temp->next;
			temp->next = tmp2->next;
			delete tmp2;
			return 1;
		}
		temp = temp->next;
	} while (temp != 0);
	return 0;
}

int SinglyLL::getElement(int index)
{
	int
		t = numElements(),
		tmp = 0;

	if ( !(( index >= 0 ) && ( index <= t )) )
	{
		char
			s[] = "Index out of range";

		throw s;
	}

	Node 
		*temp = head;

	do
	{
		if (tmp == index)
		{
			tmp = temp->ele;
			break;
		}
		temp = temp->next;
	} while (temp != 0);
	return tmp;
}