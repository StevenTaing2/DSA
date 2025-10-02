#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string res;
        for (string i : words) {
            res += i;
            if (res == s) return true;
        }
        return false;
    }
};