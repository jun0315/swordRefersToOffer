#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            for (int k = 1; k < i; k++) {
                dp[i] = max(dp[i], max(i * k, i * dp[i - k]));
            }
        }
        return dp[n];
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
