#ifndef _SINGLYLL_INC
#define _SINGLYLL_INC

using namespace std;

class Node
{
public:
	int ele;
	Node *next;
	Node(int _ele)
	{
		ele = _ele;
		next = 0;
	}
};

class SinglyLL
{
	Node
		*head,
		*tail;

public:
	SinglyLL()
	{
		head = tail = 0;
	}
	bool isEmpty();
	bool isInList(int _ele);
	void addToHead(int _ele);
	int deleteFromHead();
	void truncateList();
	int numElements();
	bool deleteElement(int _ele);
	int getElement(int index);
};

#endif