#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }
        int fromleft = 0;

        for (int i = 0; i < nums.size(); ++i) {
            sum -= nums[i];
            if (fromleft == sum) {
                return i;
            }
            fromleft += nums[i];
        }

        return -1;
    }
};