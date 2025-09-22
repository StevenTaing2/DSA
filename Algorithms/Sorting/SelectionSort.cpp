#include "SelectionSort.h"
#include <algorithm>
#include <iostream>
using namespace std;

void SelectionSort::selectionSort(std::vector<int>& arr, int numberLoops)
{
	int i, j, min;

	for (i = 0; i < numberLoops; ++i) {
		min = i;
		for (j = i + 1; j < numberLoops; ++j) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		swap(arr[i], arr[min]);
	}
}
