#include <unordered_map>

using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> um;
        int numberOfPairs = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (um.count(nums[i]) > 0) {
                um[nums[i]] += 1;
                numberOfPairs += um[nums[i]];
            }
            else {
                um[nums[i]] = 0;
            }
        }
        return numberOfPairs;
    }
};