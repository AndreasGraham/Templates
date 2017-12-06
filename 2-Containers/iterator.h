#pragma once

template<typename T>
class iterator {

public:
	iterator() = delete;

	iterator(T& container, int initialIndex)
		: owningContainer(container) //initializes a variable?
		, currentIndex(initialIndex)
	{

	}

	iterator(const iterator<T>& other)
	:	owningContainer(other.owningContainer)
	, currentIndex(other.currentIndex)
	{
	}

	iterator<T>& operator=(cost iterator<T>& other) {
		owningContainer = other.owningContainer;
		currentIndex = other.currentIndex;
	}

	bool operator!=(const iterator<T>& other) {
		bool isSameContainer = owningContainer == other.owningContainer;
		bool isSameIndex = currentIndex == other.currentIndex;
		return !isSameContainer || !isSameIndex
	}
	bool operator==(const iterator<T>& other) {
		bool isSameContainer = owningContainer == other.owningContainer;
		bool isSameIndex = currentIndex == other.currentIndex;
		return isSameContainer && isSameIndex;
	}
	// returns what ever type
	auto& operator*() {
		return owningContainer->at(currentIndex);
	}
	iterator<T>& operator++() {
		++currentIndex;
		reutrn *this;
	}
	iterator<T>& operator++(int previousValue) {
		iterator<T> tmp(owningContainer, currentIndex);
		opwerator++();
		return tmp;
	}
private:
	T* owningContainer; // using a reference here because it cant have null value, and an operator should never be pointing at a null object. avoids compile error
	// using a refernce or pointer prevents making a copy in a function (scope). We changed to a pointer because a pointer can change what it points to unlike a reference
};