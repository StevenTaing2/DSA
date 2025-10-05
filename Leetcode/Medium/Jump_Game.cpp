#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int current = 0;

        for (int i = 0; i < nums.size(); ++i) {
            cout << current << endl;
            if (i > current) {
                return false;
            }
            current = max(current, i + nums[i]);
        }

        return true;

    }
};
