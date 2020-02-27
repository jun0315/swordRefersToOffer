#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int rows, cowl;

    bool dfs(vector<vector<char>> &board, string word, int k, vector<vector<bool>> &visit, int i, int j) {
        visit[i][j] = true;
        if (k == word.size() - 1) {
            return true;
        }
        //上左下右
        if (i > 0 && !visit[i - 1][j] && board[i - 1][j] == word.at(k + 1)) {
            bool flag1 = dfs(board, word, k + 1, visit, i - 1, j);
            if (flag1) {
                return true;
            }
        }
        //左
        if (j > 0 && !visit[i][j - 1] && board[i][j - 1] == word.at(k + 1)) {
            bool flag2 = dfs(board, word, k + 1, visit, i, j - 1);
            if (flag2) {
                return true;
            }
        }
        //下
        if (i < rows - 1 && !visit[i + 1][j] && board[i + 1][j] == word.at(k + 1)) {
            bool flag3 = dfs(board, word, k + 1, visit, i + 1, j);
            if (flag3) {
                return true;
            }
        }
        //右
        if (j < cowl - 1 && !visit[i][j + 1] && board[i][j + 1] == word.at(k + 1)) {
            bool flag4 = dfs(board, word, k + 1, visit, i, j + 1);
            if (flag4) {
                return true;
            }
        }
        visit[i][j] = false;
        return false;
    }

    bool exist(vector<vector<char>> &board, string word) {
        rows = board.size();
        cowl = board[0].size();
        vector<vector<bool>> visit(rows, vector<bool>(cowl, false));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cowl; j++) {
                if (board[i][j] == word.at(0) && dfs(board, word, 0, visit, i, j)) {
                    return true;
                }
            }
        }
        return false;

    }

};

int main() {
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                  {'S', 'F', 'E', 'S'},
                                  {'A', 'D', 'E', 'E'}};
    string word = "ABCESEEEFS";
    Solution solution;
    if (solution.exist(board, word)) {
        cout << "true";
    } else {
        cout << "false";
    }
}
