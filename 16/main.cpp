#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        bool negative = false;
        if (n < 0) {
            negative = true;
        }
        double ans = 1;
        double base = x;
        while (n != 0) {
            if (n & 1 != 0)
                ans *= base;
            base *= base;
            n /= 2;
        }
        return negative ? 1 / ans : ans;
    }
};

int main() {
    Solution solution;
    cout << solution.myPow(2, -2);
}
