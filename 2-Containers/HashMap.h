#pragma once
#include "tvector.h"
template<typename T>
class HashMap {
	HashMap();
	~HashMap();
	size_t Hash(size_t key);
	void addHash(size_t hash);
	void DeleteHash(size_t hash);
public:
	tVector arr;



};

// the key is the value you want, 
//

template<typename T>
HashMap::HashMap() {
	capacity = 50;
	data = new T[cpacity];
	size = capacity;
}

template<typename T>
size_t HashMap<T>::Hash(size_t key) {
	size_t hash = key / 2; 
	return hash;
}

template<typename T>
void HashMap<T>::addHash(size_t key) {
	size_t hash = Hash(key);
	arr[hash] = key;
}

template<typename T>
void HashMap<T>::DeleteHash(size_t key) {
	size_t hash = Hash(key);
	arr[hash] = null;
	// pass in key
	//hash key
	// get index
}

template<typename T>
void HashMap<T>::clearMap() {
	arr.clear();
}

//find
// turn hash() returns the index 
// add fucntion, delete function



