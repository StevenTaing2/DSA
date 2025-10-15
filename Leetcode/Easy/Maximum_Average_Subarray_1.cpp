#include <vector>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i = 0, j = i + k - 1;
        double current = 0.0;

        for (int idx = i; idx < j + 1; ++idx) {
            current += nums[idx];
        }
        double average = current;
        ++j;
        while (j < nums.size()) {
            current += nums[j];
            current -= nums[i];
            if (current > average) {
                average = current;
            }
            ++i;
            ++j;
        }

        return average / k;
    }
};