#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int squaresum = 0;
        string newn = to_string(n);
        unordered_set<int> visited;
        while (squaresum != 1) {
            for (int i = 0; i < newn.size(); ++i) {
                int current = newn[i] - '0';
                current *= current;
                squaresum += current;
            }

            if (squaresum == 1) {
                return true;
            }
            else if (visited.find(squaresum) != visited.end()) {
                return false;
            }
            else {
                newn = to_string(squaresum);
                visited.insert(squaresum);
                squaresum = 0;
            }
        }
        return false;
    }
};