#include "intvector.h"
#include <cassert>
#include <cstring>
intVector::intVector() {
	capacity = 2;
	data = new int[capacity];
	size = 0;
}

intVector::~intVector() { // deconstructor, instantly called when we go out of scope (like global, or in a funciton or if statement, 
	//scope examples, gloabal, if statement, funciton, so when funciton ends this is instantly called and destroys the arry to free ram
	delete[] data; // delets the memeory allocated to data on line 5

}

int & intVector::at(size_t idx) // returns the element at the array
{
	//programmer errors (programmer needs to see) use assert
	assert(idx > 0);
	assert(idx < size);
	return data[idx];

}

int & intVector::append(int val)
{
	//defensive programming
	if (size == capacity) {
		bool didGrow = grow(size + 1);
		assert(didGrow);
	}
	data[size] = val;
	++size;
	//asserts and what not protect yourself from when you code at 3 am and make bad mistakes
}

int * intVector::returnData() const
{
	int* a = data;
	return a;
}

size_t intVector::returnCapacity() const
{
	return capacity;
}

size_t intVector::returnSize() const
{
	return size;
}

bool intVector::empty() const
{
	/*assert(size >= 0);
	if (size == 0) {
		return true;
	}
	else {
		return false;
	}*/
	
	//simpler but same
	return size == 0;
}

int intVector::front() const
{
	return data[0];
}

int intVector::back() const
{
	return data[size];
}

int intVector::returnValue(int index) const
{
	assert(index < size);
	
	return data[index];
}

void intVector::clear()
{
	size = 0;
}

void intVector::erase(int index) {
	for (int i = 0; i < size; i++) {
		data[index] = data[index + 1];
	}
	size -= 1;
}

int intVector::count(int value) const
{
	int count = 0;
	for (int i = 0; i <= size; i++) {
		if (data[i] == value) {
			count++;
		}
	}
	return count;
}

void intVector::insert(int value, int index)
{
	assert(index >= 0);
	assert(index <= size);
	if (capacity == size) {
		capacity++;
	}
	size++;
	for (int i = 0; i < size; i++) {
		data[index] = data[index + 1];
	}
	data[index] == value;
}

bool intVector::grow(size_t minSize) {
	assert(minSize <= 64000); // anytime you think about large numbers think about overflow and underflow
	if (minSize <= capacity)
	{
		return true;
	}

	while (capacity < minSize) {
		capacity *= 2;
	}
	//int oldCapacity = capacity;
	

	int* newData = new int[capacity];
	memcpy(newData, data, sizeof(int) * size);

	delete[] data;
	data = newData;
	return true;
}


