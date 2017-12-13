#pragma once
#include "tvector.h"





template<typename T>
class HashMap {
	tVector<T> arr;
	

public:
	HashMap();
	//~HashMap();
	size_t Hash(size_t key);
	void addHash(size_t hash, T value);
	void DeleteHash(size_t hash);
	void clearMap();
	T atHash(size_t hash);

};

// the key is the value you want, 
//

//template<typename T>
//HashMap<T>::~HashMap() {
//	//delete arr.returnData();
//	/*for (int i = 0; i < arr.getSize();i++) {
//		arr.erase(i);
//	}*/
//}

template<typename T>
HashMap<T>::HashMap() {
	arr.Reserve(11);
	arr.setSize(10);
	//arr.capacity = 50;
	//arr.data = new T[arr.capacity];
	//arr.size = arr.capacity;
}

template<typename T>
size_t HashMap<T>::Hash(size_t key) {
	size_t hash = key % arr.getCapacity() ; 
	return hash;
}

template<typename T>
void HashMap<T>::addHash(size_t key, T value) {
	size_t hash = Hash(key);
	//int thing = arr[hash];
	arr[hash] = value;
	//arr.insert(value, hash); // adds it to list
	std::cout << arr[hash] << std::endl;
}

template<typename T>
void HashMap<T>::DeleteHash(size_t key) {
	size_t hash = Hash(key);
	arr.erase(hash);
	// pass in key3
	//hash key
	// get index
}

template<typename T>
void HashMap<T>::clearMap() {
	arr.clear();
}

template<typename T>
T HashMap<T>::atHash(size_t hash) {
	std::cout << arr.at(Hash(hash)) << std::endl;
	return arr.at(Hash(hash));
}




//find
// turn hash() returns the index 
// add fucntion, delete function



