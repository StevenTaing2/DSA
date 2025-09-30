#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> letterString;
        int maxVowel = 0;
        int maxCon = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (letterString.count(s[i]) > 0) {
                letterString[s[i]] += 1;
            }
            else {
                letterString[s[i]] = 1;
            }

            if (letterString[s[i]] > maxVowel && (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')) {
                maxVowel = letterString[s[i]];
            }
            else if (letterString[s[i]] > maxCon && (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u')) {
                cout << s[i] << endl;
                maxCon = letterString[s[i]];
            }
        }
        return maxCon + maxVowel;
    }
};