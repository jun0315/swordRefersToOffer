#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        string replaceStr;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                replaceStr.push_back(s[i]);
            } else {
                replaceStr.push_back('%');
                replaceStr.push_back('2');
                replaceStr.push_back('0');
            }
        }
        return replaceStr;
    }
};

int main() {
    Solution solution;
    cout << solution.replaceSpace("we are happy");
}
