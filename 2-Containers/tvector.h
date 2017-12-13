#pragma once
#include <cassert>
#include <cstring>
#include "iterator.h"
template<typename T>
class tVector {
	T * data;
	size_t capacity; 
	size_t size;

public:
	/*T * data;
	size_t capacity;
	size_t size;*/
	tVector() {
		capacity = 2;
		data = new T[capacity];
		size = 0;
	}
	~tVector();
	iterator<tVector<T>> begin() {
		return iterator<tVector<T>>(*this, 0);
	}

	iterator<tVector<T>> end() {
		return iterator<tVector<T>>(*this, size); // goes one past final location 
	}

	
	T & operator[](const size_t idx) {
		return data[idx];
	};

	T operator[](const size_t idx) const{
		return data[idx];
	};

	T& at(size_t idx);
	T& append(T val);
	T* returnData();
	bool grow(size_t minSize);
	size_t getSize() const;
	size_t getCapacity() const;
	bool empty() const;
	T front() const;
	T back() const;
	void pop();
	T returnIndex(size_t index);
	void clear();
	void erase(size_t Idx);
	int count(size_t val);
	void insert(size_t val, size_t idx);
	void Reserve(size_t newCapacity);
	void Compact();
	void EraseRange(size_t start, size_t end);
	void setSize(size_t newSize);
};

//template<typename T>
//tVector<T>::tVector() {
//	capacity = 2;
//	data = new T[capacity];
//	size = 0;
//}

template<typename T>
tVector<T>::~tVector() {
	delete[] data;
}

template<typename T>
T& tVector<T>::at(size_t idx) {
	return data[idx];
}


template<typename T>
T* tVector<T>::returnData() {
	return *data;
}

template<typename T>
T& tVector<T>::append(T val) {
	if (size == capacity) {
		bool didGrow = grow(size + 1);
		assert(didGrow);
	}
	data[size] = val;
	++size;
	return val;
}

template<typename T>
bool tVector<T>::grow(size_t minSize) {
	assert(minSize <= 640000);
	if (minSize <= capacity) {
		return true;
	}
	while (capacity < minSize) {
		capacity *= 2;
	}

	T* newData = new T[capacity];
	memcpy(newData, data, sizeof(T) * size);
	delete[] data;
	data = newData;
	
	return true;
}

template<typename T>
size_t tVector<T>::getCapacity() const{
	return capacity;
}

template<typename T>
size_t tVector<T>::getSize() const {
	return size;
}

template<typename T>
bool tVector<T>::empty() const {
	return size == 0;
}

template<typename T>
T tVector<T>::front() const {
	return data[0];
}

template<typename T>
T tVector<T>::back() const {
	return data[size];
}

template<typename T>
void tVector<T>::pop() {
	size -= 1;
}

template<typename T>
T tVector<T>::returnIndex(size_t index) {
	return data[index];
}

template<typename T>
void tVector<T>::clear() {
	size = 0;
}

template<typename T>
void tVector<T>::erase(size_t Idx) {
	for (int i = Idx; i < size; i++) {
		int temp = data[i];
		data[i] = data[i + 1];
		data[i + 1] = temp;
	}
	size -= 1;
}

template<typename T>
int tVector<T>::count(size_t val) {
	int count;
	for (int i = 0; i < size; i++) {
		if (data[i] == val) {
			count++;
		}
	} 
}

template<typename T>
void tVector<T>::insert(size_t val, size_t idx) {
	append(val);
	for (int i = size; i >= idx; i--) {
		int temp = data[i];
		data[i] = data[i - 1];
		data[i - 1] = temp;
	}
}

template<typename T>
void tVector<T>::Reserve(size_t newCapacity) {
	if (newCapacity < capacity) {
		T* newData = new T[newCapacity];
		memcpy(newData, data, sizeof(T) * size);
		delete[] data;
		data = newData;
		capacity = newCapacity;
	}
}

template<typename T>
void tVector<T>::Compact() {
	T* newData = new T[size];
	memcpy(newData, data, sizeof(T) * size);
	delete[] data;
	data = newData;
	capacity = size;
}

template<typename T>
void tVector<T>::EraseRange(size_t start, size_t end) {
	for (int i = end; i > start; i--) {
		data[i] = data[i + 1];
	}
	size = size - (end - start);
}

template<typename T>
void tVector<T>::setSize(size_t newSize) {
	size = newSize;
}
