#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int num = 0;

    void dfs(int m, int n, int k, int i, int j, vector<vector<bool>> &visit) {
        if (i >= m || i < 0 || j < 0 || j >= n || visit[i][j]) {
            return;
        }
//        if (i % 10 + i / 10 + j % 10 + j / 10 <= k) {
//            num++;
//            cout << "index :" << num << " i : " << i << " j: " << j << endl;
//        }
        if (i % 10 + i / 10 + j % 10 + j / 10 > k) {
            return;
        }
        visit[i][j] = true;
        num++;
        dfs(m, n, k, i + 1, j, visit);
        dfs(m, n, k, i - 1, j, visit);
        dfs(m, n, k, i, j + 1, visit);
        dfs(m, n, k, i, j - 1, visit);
    }

    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        if (m == n && n == 0) {
            return 1;
        }
        dfs(m, n, k, 0, 0, visit);
        return num;
    }
};

int main() {
    Solution solution;
    cout << solution.movingCount(16, 8, 4);
    return 0;
}
