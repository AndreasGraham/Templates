#pragma once

template<typename T>
class tLinkedList {
	tLinkedList();
	~tLinkedList();

	T at(size_t idx);
	T append(T val, size_t idx);
	bool empty() const;
	T front() const;
	T back() const;
	void clear();
	void erase(size_t index);
	void insert(size_t index, T value);
	size_t size();
	
private:
	struct tLinkedListNode {
		T value;
		tLinkedListNode * next
	};

	tLinkedListNode * head;
	tLinkedListNode * tail;
};

template<typename T>
tLinkedList<T>::tLinkedList()
	:(nullptr)
{
	clear();
}

template<typename T>
size_t tLinkedList<T>::size() {
	int count = 0;
	tLinkedListNode * iter = head;
	if (head == nullptr) {
		return 1;
	}
	while (iter != nullptr) {
		count++;
		iter = iter->next;
	}
	return count;
}

template<typename T>
void tLinkedList<T>::clear() {
	tLinkedListNode* iter = head;
	while (iter != nullptr) {
		tLinkedListNode* next = iter->next;
		delete iter;
		iter = next;
	}
}

template<typename T>
T tLinkedList<T>::at(size_t idx) {
	tLinkedListNode * iter = head;
	inter counter = 0;
	while (while counter != idx && iter != nullptr) {
		counter++;
		iter = iter->next;
	}
	assert(counter == idx);
	return iter->value;
}

template<typename T>
void tLinkedList<T>::append(T val, size_t idx) {
	tLinkedListNode * newNode = new tLinkedListNode;
	newNode->value = val;
	newNode->next = nullptr;
	tLinkedListNode * iter = head;
	int counter = 0;
	
	if (head == nullptr) {
		head = newNode;
	}
	else {
		while (iter != nullptr && counter != idx) {
			counter++;
			iter = iter->next;
		}
		iter->next = newNode;
	}
}

template<typename T>
bool tLinkedList<T>::empty() {
	return head == nullptr;
}

template<typename T>
T tLinkedList<T>::front() {
	assert(!empty());
	return head->value;
}

template<typename T>
T tLinkedList<T>::back() {
	assert(!empty());
	tLinkedListNode * iter = head;
	while (iter != nullptr) {
		iter = iter->next;
	}
	assert(iter != nullptr);
	return iter->value;
}

template<typename T>
void tLinkeddList<T>::insert(size_t index, T val) {
	int count = 0;
	tLinkedListNode * newNode = new tLinkedListNode;
	newNode->value = val;
	tLinkedListNode * iter = head;
	tLinkedListNode * prev = iter;
	while (count != index && iter->next != nullptr) {
		prev = iter;
		iter = iter->next;
	}
	assert(index == count);
	prev->next = newNode;
	newNode->next = iter;

}

template<typename T>
void tLinkedList<T>::erase(size_t index) {
	int counter = 0;
	tLinkedListNode * iter = head;
	tLinkedListNode * prev = iter;
	while (counter != index) {
		prev = iter
		iter = iter->next;
	}
	assert(ind == counter);
	if (iter->next == nullptr) {
		prev->next = nullptr;
	}
	else{
		prev->next = iter->next;
	}
	delete iter;

}