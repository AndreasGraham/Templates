#pragma once
#include "tLinkedList.h"
template<typename T>
class Queue
{
private:
	tLinkedList<T>list;
public:
	
	T front(); //is your head
	bool empty();
	size_t size();
	void push(T val, int size);
	T pop();  //return the thing that was popped

};

template<typename T>
T Queue<T>::front() {
	return list.front();
}

template<typename T>
bool Queue<T>::empty() {
	return list.empty();
}

template<typename T>
size_t Queue<T>::size() {
	return list.size();
}

template<typename T>
void Queue<T>::push(T val, int idx) {
	list.append(val, idx);
}