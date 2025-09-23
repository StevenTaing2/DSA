#include "InsertionSort.h"
#include <iostream>

using namespace std;

void InsertionSort::insertionSort(std::vector<int>& arr, int n)
{
	int i, j;

	for (i = 1; i < n; ++i) {
		j = i;
		while ((j > 0) && (arr[j] < arr[j - 1])) {
			swap(arr[j], arr[j - 1]);
			j = j - 1;
		}
	}
}
