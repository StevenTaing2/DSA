#include <vector>

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum { 0 };
        int highestAltitude = sum;

        for (int i : gain) {
            sum += i;
            if (sum > highestAltitude) highestAltitude = sum;
        }

        return highestAltitude;
    }
};