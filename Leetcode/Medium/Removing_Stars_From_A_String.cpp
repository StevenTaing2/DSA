#include <string>

using namespace std;

class Solution {
public:
    string removeStars(string s) {
        string ans;
        int i = 0;
        while (i < s.size()) {
            if (s[i] != '*') {
                ans += s[i];
            }
            else {
                ans.pop_back();
            }
            ++i;
        }

        return ans;
    }
};