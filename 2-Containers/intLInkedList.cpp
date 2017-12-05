#include "intLinkedList.h"
#include <cassert>

intLinkedList::intLinkedList()
	:head(nullptr) 
{

}

intLinkedList::~intLinkedList() {
	clear();
}

void intLinkedList::append(int value) {
	intLinkedListNode * newNode = new intLinkedListNode;
	newNode->value = value;
	newNode->next = nullptr;
	if (head == nullptr) {
		head = newNode;
	}
	else
	{
		intLinkedListNode* iter = head;
		while (iter->next != nullptr) {
			iter = iter->next;
		}
		iter->next = newNode;
	}
}
// head = start
int intLinkedList::at(int index) {
	intLinkedListNode * FindIndex = head;
	int counter = 0;
	while (FindIndex != nullptr && counter != index) {
		intLinkedListNode* next = FindIndex->next;
		counter++;
		FindIndex = next;
	}
	assert(index == counter);

	return FindIndex->value;
}

size_t intLinkedList::size() const {
	intLinkedListNode * index = head;
	int counter = 0;
	while (index != nullptr) {
		index = index->next;
		counter++;
	}
	return counter;
}

bool intLinkedList::empty() const {
	return head == nullptr;
}

int intLinkedList::front() const {
	assert(!empty());
	return head->value;
}

int intLinkedList::back() const {
	intLinkedListNode * iter = head;
	while (iter->next != nullptr) {
		iter = iter->next;
	}
	return iter->value;
}

void intLinkedList::insert(int index, int value) {
	//assert(!empty());
	int counter = 0;
	intLinkedListNode *newNode = new intLinkedListNode;
	newNode->value = value;
	intLinkedListNode * iter = head;
	intLinkedListNode * prevIndex = iter;
	while (index != counter && iter->next != nullptr) {
		counter++;
		prevIndex = iter;
		iter = iter->next;
	}
	assert(index == counter);
	
	//assert(iter != nullptr);
	newNode->next = iter;
	prevIndex->next = newNode;

}

void intLinkedList::erase(int ind) {
	int counter = 0;
	intLinkedListNode * iter = head;
	intLinkedListNode * prev = iter;
	
	while (counter != ind) {
		counter++;
		prev = iter;
		iter = iter->next;
	}

	assert(ind == counter);
	if(iter->next != nullptr){ 
		prev->next = iter->next; 
	}
	else {
		prev->next = nullptr;
	}
	delete iter;
}

void intLinkedList::clear() {
	intLinkedListNode* iter = head;
	while (iter != nullptr) {
		intLinkedListNode* next = iter->next;
		delete iter;
		iter = next;
	}
}