#pragma once
template<typename T, typename S>
static S addRange(T start, T end) {
	S total = 0;
	T iter = start;
	while (iter != end) { // while not pointing at end
		total += *iter;
		++iter; // moves iterator one memory address accorss
	}
	return total;
}

template<typename T, typename S>
static S addRangeFinished(T start, T end) {
	S total = 0;
	T iter = start;
	while (iter != end) {
		total += *iter;
		++iter;
	}
	return total;
}