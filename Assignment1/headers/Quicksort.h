// Quicksort.h
// Grenon Samuel
// 6 September 2018
// Assignment1.h
// Header file used for a quicksort implementation

// The algorithim Implementation for quicksort is 
// 1. Pick the lowest element as the pivot
// 2. Partitions the vector with values less than the
//	  pivot coming before the pivot, while all values greater
//    come after. (Note I am using Hoare's parition scheme not Lomutos)
// 3. Recursivley apply the above steps to the sub-array of elements 
//	  with smaller values and separately to the sub-array of elements
//    with greater values.

#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <stdint.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <random>
#include <cfloat>

template<typename T>
class RandGenerator
{
public:
	//Overloaded function that will populate a vector<int> with random ints.
	T generate()
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(INT_MIN, INT_MAX);
		return dis(gen);
	}

	
};


template <>
class RandGenerator<double>
{
public:
	//Overloaded function that will populate a vector<double> with random doubles.
	double generate()
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<> dis(DBL_MIN, DBL_MAX);
		return dis(gen);
	}
};


template<typename T>
class Quicksort{

public:
	Quicksort();
	Quicksort(std::vector<T> &, int, int);

	int partition(std::vector<T> &, int, int);

};

template<typename T>
Quicksort<T>::Quicksort() = default;

template<typename T>
Quicksort<T>::Quicksort(std::vector<T> &vec, int low, int high) {
	if (low < high)
	{
		int p = partition(vec, low, high);
		Quicksort(vec, low, p);
		Quicksort(vec, p + 1, high);

	}
}

template<typename T>
int Quicksort<T>::partition(std::vector<T> &vec, int low, int high) {
	T pivot = vec[low];
	int i = low - 1;

	int j = high + 1;

	while (true) {

		do
		{
			i = i + 1;
		} while (vec[i] < pivot);

		do
		{
			j = j - 1;
		} while (vec[j] > pivot);

		if (i >= j)
		{
			return j;
		}

		std::swap(vec[j], vec[i]);
	}

}

#endif