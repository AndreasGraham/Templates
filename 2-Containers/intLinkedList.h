#pragma once
class intLinkedList
{
public:
	
	intLinkedList();
	~intLinkedList();

	void append(int value);
	int at(int index); // returns the value at that index
	size_t size() const; // size t is for readability
	bool empty() const; // checks if it is empty
	int front() const; // return value at beggining
	int back() const;
	void clear();
	void erase(int index);
	//int count() const; // same thing as size
	void insert(int index, int value);

private:
	struct intLinkedListNode {
		int value;
		intLinkedListNode* next;
		intLinkedListNode * prev;
	};
	intLinkedListNode* head;
	intLinkedListNode * tail; 

};

/*
you want to iterate, you need head. 
head allows you to start at the beggining

when making a function you want to think about the
1. input
2. the state
3. the output
and you need to use the input and the current state
to get to the output.

*/

//insert
/*input a node and an index
cycle through until you reach the node before that index
set the current node at index to variable dummy
set the next of index-1 equal to the input node
set the next of index to dummy
*/