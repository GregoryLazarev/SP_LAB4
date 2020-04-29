#include "List.h"
#include <iostream>
using namespace std;

Node::Node(char tr[3])
{
	for (int i = 0; i < 3; i++)
	{
		trgrm[i] = tr[i];
	}
	count = 1;
	next = NULL;
}

List::List()
{
	head = NULL;
	count = 0;
}

void List::check(char tr[3])
{
	Node* node = head;
	bool equal = false;
	while (node != NULL && !equal)
	{
		equal = true;
		for (int i = 0; i < 3; i++)
		{
			if (tr[i] != node->trgrm[i])
				equal = false;
		}
		if (equal)
			node->count++;
		node = node->next;
	}
	if (!equal)
		add(tr);
}

void List::add(char tr[3])
{
	if (head)
	{
		Node* node = new Node(tr);
		node->next = head;
		head = node;
	}
	else
	{
		Node* node = new Node(tr);
		head = node;
	}
	count++;
}

void List::Print()
{
	Node* p = head;
	while (p)
	{
		for (int i = 0; i < 3; i++)
			cout << p->trgrm[i];
		cout << "\t"<< p->getCount() << endl;
		p = p->Next();
	}
}

