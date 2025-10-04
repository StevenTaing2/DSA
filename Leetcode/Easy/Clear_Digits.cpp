#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string clearDigits(string s) {
        stack<char> track;

        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) {
                if (!track.empty()) {
                    track.pop();
                }
            }
            else {
                track.push(s[i]);
            }
        }
        string result;
        while (!track.empty()) {
            result += track.top();
            track.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};