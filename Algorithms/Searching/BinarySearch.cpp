#include "BinarySearch.h"

using namespace std; 

bool BinarySearch::calcResult(int target, int n, std::vector<int>& arr)
{
    int min = 0, max = n - 1;
    int mid = min + (max - min) / 2;

    while (min <= max) {
        mid = min + (max - min) / 2;

        //check if target is the centre value
        if (arr[mid] == target) {
            return true;
        }

        //if the target is greater than the middle then we ignore the left half of the vector
        if (arr[mid] < target) {
            min = mid + 1;
        }
        //else we ignore the right half of the vector
        else {
            max = mid - 1;
        }
    }
    if (arr[mid] == target) return true;
    return false;
}
