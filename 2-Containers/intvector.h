#pragma once

class intVector {
	// this data defaults to private, no one else needs to be modifying this
	int * data;//pointer to your dynamically allocated array
	unsigned int capacity;// total size (or rather, the capacity of the array)
	size_t size;// total number of elements stored  size_t is the same as unsigned int
	
public:
	intVector(); // constructor
	~intVector();
	int& at(size_t idx);
	int& append(int val);
	int* returnData() const;
	size_t returnCapacity() const;
	size_t returnSize() const;
	bool empty() const;
	int front() const;
	int back() const;
	int returnValue(int index) const;
	void clear();
	void erase(int index);
	int count(int value) const;
	void insert(int value, int index);
	void reserve(int capacity);
	void compact();
	void printVector();
	
private:
	bool grow(size_t minSize);

};