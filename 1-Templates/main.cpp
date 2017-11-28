#include <iostream>
#include "Person.h"
int add(int a, int b) {
	return a + b;
}

float add(float a, float b) {
	return a + b;
}

template<typename T>
T sub(T a, T b) {
	return a - b; 
}

template<typename T>
void print(T a) {
	std::cout << a << std::endl;
	
}
template<>
void print(Person p)
{
	print(p.age);
	print(p.name);
}

template<typename T>
T min(T a, T b) {
	if (a > b) {
		std::cout << b << std::endl;
		return b;
	}
	else if (b > a){
		std::cout << a << std::endl;
		return a;
	}
}

template<typename T>
T max(T a, T b) {

	if (a > b) {
		std::cout << a << std::endl;
		return a;
	}
	else if (b > a) {
		std::cout << b << std::endl;
		return b;
	}
}

template<typename T>
T clamp(T value, T low, T high) {
	if (value < low) {
		return low;
	}
	else if (value > high) {
		return low;
	}

	else {
		std::cout << value << std::endl;
		return value;
	}
}

template<typename T>
T swap(T &a, T &b) {
	T c = a;
	a = b;
	b = c;
	return a, b;
	/*print(a);
	print(b);*/
}

template<bool b> // means you pass in a true or false for b not a variable
bool assert(bool a) {
	if (a == b) {
		print("true");
	}
	else {
		print("false");
	}
	return a;
}

template<typename T>
T Assert(T a, T b) {
	if (a == b) {
		print("true");
	}
	else {
		print("false");
	}
	return a, b;
}

int main() {
	Person a;
	a.age = 25;
	a.name = "Kobington";


	int v1 = add(5, 2);
	float v2 = add(2.1f, 3.2f);

	int s1 = sub(1, 1);
	float s2 = sub(2.5f, 1.1f);

	int s3 = sub<int>(1, 2.0f);
	bool b = true;
	print(s1);
	print(b);
	print(s2);

	min<int>(12, 2);
	max<int>(5, 2);

	clamp<float>(3, 2, 4);

	print<Person>(a);
	
	int d = 1;
	int g = 2;
	swap(d, g);
	//swap(1,2) does not work because you are passing in a reference

	min('a' , 'b');
	max('a', 'b');
	bool x = true;
	bool z = false;
	assert<false>(z);
	Assert(d, g);

	while(true){}
}