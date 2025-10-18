#include <vector>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        vector<int> ans;

        int i = 0;

        while (i < asteroids.size()) {
            while (!ans.empty() && asteroids[i] < 0 && ans.back() > 0) {
                int sum = asteroids[i] + ans.back();
                if (sum < 0) {
                    ans.pop_back();
                }
                else if (sum > 0) {
                    asteroids[i] = 0;
                }
                else {
                    asteroids[i] = 0;
                    ans.pop_back();
                }
            }

            if (asteroids[i] != 0) {
                ans.push_back(asteroids[i]);
            }

            ++i;
        }


        return ans;
    }
};