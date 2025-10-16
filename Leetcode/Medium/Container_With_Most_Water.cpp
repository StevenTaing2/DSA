#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int maxWater = 0;

        while (l < r) {
            if (height[l] > height[r]) {
                if (maxWater < height[r] * (r - l)) {
                    maxWater = height[r] * (r - l);
                }
                --r;
            }
            else {
                if (maxWater < height[l] * (r - l)) {
                    maxWater = height[l] * (r - l);
                }
                ++l;
            }
        }

        return maxWater;
    }
};