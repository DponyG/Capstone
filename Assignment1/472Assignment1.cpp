
#include <iostream>
#include <algorithm>
#include <vector>

int partition(std::vector<int> &vec, int low, int high)
{
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

void quicksort(std::vector<int> &vec, int low, int high)
{
	if (low < high)
	{
		int p = partition(vec, low, high);
		quicksort(vec, low, p);
		quicksort(vec, p + 1, high);

	}

	
}

void printArray(std::vector<int> &vec)
{
	
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << std::endl;
	}

	

}

int main()
{
	std::vector<int> vec = { 3, 5, 7, 9, 10, 6, 100, 20, 9, 40, 60, 2, 5 };
	quicksort(vec, 0, vec.size()-1);
	printArray(vec);

}

