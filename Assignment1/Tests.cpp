#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Quicksort.h"
#include <iostream>

template<typename T>
std::vector<T> sortIt(std::vector<T> vec, int first, int last) {
	std::sort(vec.begin() + first, vec.begin() + last);
	return vec;
}



template<typename T>
std::vector<T> sortFullVec(std::vector<T> vec) {
	return sortIt(vec, 0, vec.size());

}

//TEST_CASE("Already sorted Data") {
//	std::vector<int> a = { -10, 9, 0, 2, 1, 3 };
//	Quicksort<int>> quicksort(a, 2, 3);
//	
//}

void printVec(std::vector<int> vec) {
	for (int i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << std::endl;
	}
}


TEST_CASE("TESTING QUICKSORT") {
	std::vector<int> a = { -10, 9, 0, 2, 1, 3 };
	auto b = sortFullVec(a);
	Quicksort<int> quicksort = Quicksort<int>(a, 0, a.size() - 1);
	REQUIRE(a == b);
}


TEST_CASE("TESTING EMPTY VECTOR") {
	std::vector<int> a = {};
	auto b = sortFullVec(a);
	Quicksort<int> quicksort = Quicksort<int>(a, 0, a.size() - 1);
	REQUIRE(a == b);
}

TEST_CASE("TESTING PARTIAL CASE") {
	std::vector<int> a = {1, 4, 6, 9};
	auto b = sortIt(a, 1,3);
	Quicksort<int> quicksort = Quicksort<int>(a, 1, 3-1);
	REQUIRE(a == b);
}






	
