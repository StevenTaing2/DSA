#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> numcount;
        int numOp = 0;

        for (int i = 0; i < nums.size(); ++i) {
            int pair = k - nums[i];
            if (numcount[pair] > 0) {
                numcount[pair] -= 1;
                ++numOp;
            }
            else {
                numcount[nums[i]] += 1;
            }
        }

        return numOp;
    }
};