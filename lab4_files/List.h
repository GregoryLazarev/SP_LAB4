#ifndef LIST_H
#define LIST_H

class Node
{
private:
	char trgrm[3];
	int count;
	Node* next;
	friend class List;
public:
	Node(char tr[3]);
	int getCount(){ return count; }
	Node* Next(){ return next; }
};

class List
{
private:
	Node* head;
	int count;

public:
	List();	
	int getCount() { return count; }

	void check(char tr[3]);
	void add(char tr[3]);
	Node* getHead() { return head; }
	void Print();
};
#endif
