#include "intvector.h"
#include "test.h"
#include "intLinkedList.h"
#include <iostream>
#include "algorithms.h"
#include "iterator.h"
#include "tvector.h"
#include "algorithms.h"
int main() {


	tVector<int> nums;
	nums.append(0);
	nums.append(1);

	auto begin = nums.begin();
	auto end = nums.end();

	int total = addRange<iterator<tVector<int>>, int>(begin, end);

	int arraOfNums[] = { 1, 3, 5, 7, 9 };
	int total2 = addRange<int*, int>(arrayOfNums, arrayOfNums + 5);

	// can check if memory addres is the same. if they point to the same memory address you know they are equal. can also check index. if index is same and they point to the same address they are the same 

	/*std::vector<int> exampleNums = { 1, 3, 5, 7, 9 };
	int bla = addRange(exampleNums.begin(), exampleNums.end());

	std::aligned_storage<int> exampleNumsInList = { 1, 3, 5, 7, 9 };
	int blah = addRange(exampleNumsInList.begin(), exampleNumsInList.end()); */

	int nums[] = { 1, 3, 5, 7, 9 };
	addRange(nums, nums + 5); // Pointer arithmatic here nums is a pointer to the start of the array, nums+4 jumps four memory adreses to the end, which houses "9". +5 would take us one off the memory address
	//each int is one bite of like 4 bites or something, and each number is housed by 4 zeroes
	





	intLinkedList list;
	intLinkedList dummy;
	list.append(5);
	int b = 4;
	b = list.at(0);
	int g = 1;
	int h = 4;
	//std::cout << b << std::endl;
	list.append(7);
	list.append(9);
	g = list.at(1);
	h = list.at(2);
	/*std::cout << g << std::endl;
	std::cout << h << std::endl;
	std::cout << list.size() << std::endl;
	std::cout << list.front() << std::endl;
	std::cout << list.back() << std::endl;
	std::cout << dummy.empty() << std::endl;
	std::cout << list.empty() << std::endl;*/
	list.insert(2, 3);
	std::cout << list.at(0) << std::endl;
	std::cout << list.at(1) << std::endl;
	std::cout << list.at(2) << std::endl;
	std::cout << list.at(3) << std::endl;
	list.erase(2);
	std::cout << list.at(2) << std::endl;
	list.clear();
	std::cout << list.at(0) << std::endl;
	intLinkedList newList;
	newList.append(1);
	newList.append(2);
	newList.append(3);
	newList.insert(3, 4);
	iterator<int> iter = list.start();
	iter++;


	// try and find start, middle and end using at
	while (true) {}
}