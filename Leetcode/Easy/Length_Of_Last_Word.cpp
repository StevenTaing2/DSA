#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        bool check{ false };
        string ans = "";
        int n = s.size() - 1;

        while (n > -1 && !isalpha(s[n])) {
            --n;
        }
        while (n > -1 && isalpha(s[n])) {
            ans += s[n];
            --n;
        }
        return ans.size();
    }
};