#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> key;
        unordered_map<string, char> revKey;
        string temp;
        int j = 0;

        s += ' ';

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                if (j >= pattern.size()) return false;

                char c = pattern[j];

                if (key.count(c)) {
                    if (key[c] != temp) return false;
                }
                else {
                    key[c] = temp;
                }

                if (revKey.count(temp)) {
                    if (revKey[temp] != c) return false;
                }
                else {
                    revKey[temp] = c;
                }

                temp = "";
                ++j;
            }
            else {
                temp += s[i];
            }
        }

        return j == pattern.size();
    }
};