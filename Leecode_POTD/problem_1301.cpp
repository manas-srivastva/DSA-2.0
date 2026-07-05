#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
    int MOD = 1e9 + 7;
    vector<vector<pair<int, int>>> t;

    bool isValid(int i, int j, int n, vector<string>& board) {
        return (i >= 0 && i < n && j >= 0 && j < n && board[i][j] != 'X');
    }

    int getIntFromChar(char ch) {
        if (ch == 'S' || ch == 'E') return 0;
        return ch - '0';
    }

    pair<int, int> solve(int i, int j, int n, vector<string>& board) {
        // Base case: Reached the Destination 'E'
        if (board[i][j] == 'E') {
            return {0, 1}; // {Score, PathCount}
        }
        
        // Memoization check
        if (t[i][j].first != -1) {
            return t[i][j];
        }

        int upScore = 0, upPaths = 0;
        int leftScore = 0, leftPaths = 0;
        int diagScore = 0, diagPaths = 0;

        char ch = board[i][j];

        // 1. Explore UP
        if (isValid(i - 1, j, n, board)) {
            auto [score, paths] = solve(i - 1, j, n, board);
            upScore = score;
            upPaths = paths;
            if (upPaths > 0) {
                upScore += getIntFromChar(ch);
            }
        }

        // 2. Explore LEFT
        if (isValid(i, j - 1, n, board)) {
            auto [score, paths] = solve(i, j - 1, n, board);
            leftScore = score;
            leftPaths = paths;
            if (leftPaths > 0) {
                leftScore += getIntFromChar(ch);
            }
        }

        // 3. Explore DIAGONALLY (Up-Left)
        if (isValid(i - 1, j - 1, n, board)) {
            auto [score, paths] = solve(i - 1, j - 1, n, board);
            diagScore = score;
            diagPaths = paths;
            if (diagPaths > 0) {
                diagScore += getIntFromChar(ch);
            }
        }

        // Find the best score among all options and combine paths
        int bestScore = 0;
        int bestPaths = 0;

        // Condition 1: All scores are equal
        if (upScore == leftScore && leftScore == diagScore) {
            bestScore = upScore;
            bestPaths = (upPaths + leftPaths + diagPaths) % MOD;
        }
        // Condition 2: Up and Left are equal
        else if (upScore == leftScore) {
            bestScore = upScore;
            bestPaths = (upPaths + leftPaths) % MOD;
            if (diagScore > bestScore) {
                bestScore = diagScore;
                bestPaths = diagPaths;
            } else if (diagScore == bestScore) {
                bestPaths = (bestPaths + diagPaths) % MOD;
            }
        }
        // Condition 3: Left and Diagonal are equal
        else if (leftScore == diagScore) {
            bestScore = leftScore;
            bestPaths = (leftPaths + diagPaths) % MOD;
            if (upScore > bestScore) {
                bestScore = upScore;
                bestPaths = upPaths;
            } else if (upScore == bestScore) {
                bestPaths = (bestPaths + upPaths) % MOD;
            }
        }
        // Condition 4: Up and Diagonal are equal
        else if (upScore == diagScore) {
            bestScore = upScore;
            bestPaths = (upPaths + diagPaths) % MOD;
            if (leftScore > bestScore) {
                bestScore = leftScore;
                bestPaths = leftPaths;
            } else if (leftScore == bestScore) {
                bestPaths = (bestPaths + leftPaths) % MOD;
            }
        }
        // Condition 5: None are equal
        else {
            bestScore = max({upScore, leftScore, diagScore});
            if (bestScore == upScore) bestPaths = upPaths;
            else if (bestScore == leftScore) bestPaths = leftPaths;
            else bestPaths = diagPaths;
        }

        return t[i][j] = {bestScore, bestPaths % MOD};
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        t.assign(n, vector<pair<int, int>>(n, {-1, -1}));

        pair<int, int> result = solve(n - 1, n - 1, n, board);
        return {result.first, result.second};
    }
};

// Main function to run local verification inside VS Code
int main() {
    Solution sol;
    vector<string> board = {"E23", "2X2", "12S"};
    
    vector<int> ans = sol.pathsWithMaxScore(board);
    cout << "Max Score: " << ans[0] << ", Total Paths: " << ans[1] << endl;
    
    return 0;
}