#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> lookup;
        unordered_set<int> check;

        for (int i = 0; i < arr.size(); ++i) {
            if (lookup.count(arr[i]) > 0) {
                lookup[arr[i]] += 1;
            }
            else {
                lookup[arr[i]] = 1;
            }
        }

        for (auto i : lookup) {
            if (check.find(i.second) != check.end()) {
                return false;
            }
            check.insert(i.second);
        }

        return true;
    }
};