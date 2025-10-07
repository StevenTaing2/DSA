#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stac;
        unordered_map<char, char> check{ {'}', '{'}, {']', '['}, {')', '('} };

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '{' || s[i] == '(' || s[i] == '[') {
                stac.push(s[i]);
            }
            else {
                if (stac.size() > 0 && check[s[i]] == stac.top()) {
                    stac.pop();
                }
                else return false;
            }
        }
        if (stac.size() == 0) {
            return true;
        }
        return false;
    }
};