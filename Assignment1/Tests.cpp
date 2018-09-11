// Tests.cpp
// Grenon Samuel
// 6 September 2018
//
// CS 471
// Unit Testing for Quicksort

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Quicksort.h"
#include<time.h>

// ******************************************************
// * Helper Functions
// ******************************************************


// ******************************************************
// * void sortAndTestPartial
// * Takes one vector and two forward iterators and 
// * sorts the vector in that range
// ******************************************************
template<typename T,typename u>
void sortAndTestPartial(std::vector<T> & vec, u first, u last) {
	Quicksort<T> quicksort = Quicksort<T>(vec, first, last);
	REQUIRE(is_sorted(vec.begin() + first, vec.begin() + last));
}

// ******************************************************
// * void sortAndTestFull
// * Takes one vector and sorts it from 0 to size-1
// ******************************************************
template<typename T>
void sortAndTestFull(std::vector<T> & vec) {
	Quicksort<T> quicksort = Quicksort<T>(vec, 0, vec.size()-1);
	REQUIRE(is_sorted(vec.begin(), vec.end()));
}


// ******************************************************
// * void initVec
// * Takes ones vector and size. Pushes the vector back
// * until i < size with either random ints or doubles.
// ******************************************************
template<typename T> 
void initVec(std::vector<T> & vec, int size) {
	RandGenerator<T> myGenerator;
	for (auto i = 0; i < size; ++i) {
		vec.push_back(myGenerator.generate());
	}
}


// ******************************************************
// * void orderValues
// * Takes two ints, one first and one last.
// * returns a pair with the lower value first, and the
// * higher value second.
// ******************************************************
std::pair<int, int> orderValues(int first, int last) {
	if (first > last)
		return std::make_pair(last, first);
	else
		return std::make_pair(first, last);
}


// ******************************************************
// * Unit Test Cases
// ******************************************************
TEST_CASE("TESTING EMPTY VECTOR") {
	std::vector<int> a = {};
	sortAndTestFull(a);
}

TEST_CASE("Sorted array remains sorted") {
	SECTION("Positive Int Values") {
		std::vector<int> a = { 10, 11, 12, 13, 14, 15, 16 };
		sortAndTestFull(a);
	}
	SECTION("Negative Int Values") {
		std::vector<int> a = { -10, -9, -8, -7, -6, -5, -4 };
		sortAndTestFull(a);
	}

	SECTION("Positive Double Values") {
		std::vector<double> a = { 1.2, 3.4, 76.4, 100 };
		sortAndTestFull(a);
	}
	SECTION("Negative Double Values") {
		std::vector<double> a = { -100.5, - 50.0, -20, - 10};
		sortAndTestFull(a);
	}
	SECTION("Single Int Values") {
		std::vector<double> a = { 10 };
		sortAndTestFull(a);
	}
	SECTION("Single Double Value") {
		std::vector<double> a = { 1009475.4567 };
		sortAndTestFull(a);
	}
}


TEST_CASE("Unsorted  Int Values") {
	SECTION("Size 10 ") {
		std::vector<int> a {};
		initVec(a, 10);
		sortAndTestFull(a);
	}
	SECTION("Size 100 ") {
		std::vector<int> a{};
		initVec(a, 100);
		sortAndTestFull(a);
	}
	SECTION("Size 1000 ") {
		std::vector<int> a{};
		initVec(a, 1000);
		sortAndTestFull(a);
	}
	SECTION("Size 10000 ") {
		std::vector<int> a{};
		initVec(a, 10000);
		sortAndTestFull(a);
	}
}

TEST_CASE("Unsorted Double Values") {
	SECTION("Size 10 ") {
		std::vector<double> a{};
		initVec(a, 10);
		sortAndTestFull(a);
	}
	SECTION("Size 100 ") {
		std::vector<double> a{};
		initVec(a, 100);
		sortAndTestFull(a);
	}
	SECTION("Size 1000 ") {
		std::vector<double> a{};
		initVec(a, 1000);
		sortAndTestFull(a);
	}
	SECTION("Size 10000 ") {
		std::vector<double> a{};
		initVec(a, 10000);
		sortAndTestFull(a);
	}
}

TEST_CASE("Partial Sort Int Values") {
	SECTION("Size 10 ") {
		srand((unsigned int)time(NULL));
		int first = rand() % 10;
		int last = rand() % 10;
		std::pair<int, int> p = orderValues(first, last);
		std::vector<int> a{};
		initVec(a, 10);
		sortAndTestPartial(a, p.first, p.second);
	}
	SECTION("Size 100 ") {
		srand((unsigned int)time(NULL));
		int first = rand() % 100;
		int last = rand() % 100;
		std::pair<int, int> p = orderValues(first, last);
		std::vector<int> a{};
		initVec(a, 100);
		sortAndTestPartial(a, p.first, p.second);
	}

	SECTION("Size 1000 ") {
		srand((unsigned int)time(NULL));
		int first = rand() % 1000;
		int last = rand() % 1000;
		std::pair<int, int> p = orderValues(first, last);
		std::vector<int> a{};
		initVec(a, 1000);
		sortAndTestPartial(a, p.first, p.second);
	}
	SECTION("Size 10000 ") {
		srand((unsigned int)time(NULL));
		int first = rand() % 10000;
		int last = rand() % 10000;
		std::pair<int, int> p = orderValues(first, last);
		std::vector<int> a{};
		initVec(a, 10000);
		sortAndTestPartial(a, p.first, p.second);
	}
}

TEST_CASE("Partial Sort Double Values") {
	SECTION("Size 10 ") {
		srand((unsigned int)time(NULL));
		int first = rand() % 10;
		int last = rand() % 10;
		std::pair<int, int> p = orderValues(first, last);
		std::vector<double> a{};
		initVec(a, 10);
		sortAndTestPartial(a, p.first, p.second);
	}
	SECTION("Size 100 ") {
		srand((unsigned int)time(NULL));
		int first = rand() % 100;
		int last = rand() % 100;
		std::pair<int, int> p = orderValues(first, last);
		std::vector<double> a{};
		initVec(a, 100);
		sortAndTestPartial(a, p.first, p.second);
	}

	SECTION("Size 1000 ") {
		srand((unsigned int)time(NULL));
		int first = rand() % 1000;
		int last = rand() % 1000;
		std::pair<int, int> p = orderValues(first, last);
		std::vector<double> a{};
		initVec(a, 1000);
		sortAndTestPartial(a, p.first, p.second);
	}
	SECTION("Size 10000 ") {
		srand((unsigned int)time(NULL));
		int first = rand() % 10000;
		int last = rand() % 10000;
		std::pair<int, int> p = orderValues(first, last);
		std::vector<double> a{};
		initVec(a, 10000);
		sortAndTestPartial(a, p.first, p.second);
	}

}

TEST_CASE("Mostly Same Data") {
	srand((unsigned int)time(NULL));
	int range = rand() % 50 + 9000;
	int ranNum = rand() % 10000;
	std::vector<int> a(10000);
	for (auto i : a) {
		a[i] = ranNum;
	}
	sortAndTestFull(a);

}



	










