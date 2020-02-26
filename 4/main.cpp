#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>> matrix, int target) {
        if (matrix.size() == 0) {
            return false;
        }
        int row = matrix.size();
        int column = matrix[0].size();
        // 从右上角开始计数
        for (int i = 0, j = column - 1; i < row && j >= 0;) {
            int tmp = matrix[i][j];
            if (tmp == target) {
                return matrix[i][j];
            } else if (tmp < target) {
                i++;
            } else {
                j--;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<vector<int>>
            matrix =
            {
                    {1,  4,  7,  11, 15},
                    {2,  5,  8,  12, 19},
                    {3,  6,  9,  16, 22},
                    {10, 13, 14, 17, 24},
                    {18, 21, 23, 26, 30}
            };
    if (solution.findNumberIn2DArray(matrix, 5)) {
        cout << "true";
    } else cout << "false";

}
