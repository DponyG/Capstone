#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>
#include <algorithm>

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
	int pivot = vec[low];
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