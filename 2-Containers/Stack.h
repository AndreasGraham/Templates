#pragma once
#include "tvector.h"


template<typename T>
class Stack {
private:
	tVector<T> vector;

	public;
	//top is size -1
	bool empty(); //checks to see if anything is in it or not
	size_t size();
	T pop();
	// - return a what was popped
	void push(T a); //-add element to the top of he stack
	T top(); //-access the top of the stack
};

//template <typename T>

template<typename T>
bool Stack<T>::empty() {
	return vector.empty();
}

template<typename T>
size_t Stack<T>::size() {
	return vector.getSize();
}

template<typename T>
T Stack<T>::pop() {
	T t = vector[size];
	size -= 1;
	return t;
}

template<typename T>
void Stack<T>::push(T a){
	vector.append(a);
}

template<typename T>
T Stack<T>::top() {
	return vector[size];
}