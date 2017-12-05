#include "intvector.h"
#include "test.h"
#include "intLinkedList.h"
#include <iostream>
int main() {
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

	// try and find start, middle and end using at
	while (true) {}
}