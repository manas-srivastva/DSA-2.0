#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    int m = grid.size();
    int n = grid[0].size();
    int total = m * n;

    k %= total;

    vector<vector<int>> ans(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int idx = i * n + j;
            int newIdx = (idx + k) % total;

            int row = newIdx / n;
            int col = newIdx % n;

            ans[row][col] = grid[i][j];
        }
    }

    return ans;
}

int main() {
    int m, n, k;

    cout << "Enter number of rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    cout << "Enter grid elements:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cout << "Enter number of shifts (k): ";
    cin >> k;

    vector<vector<int>> result = shiftGrid(grid, k);

    cout << "\nShifted Grid:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}