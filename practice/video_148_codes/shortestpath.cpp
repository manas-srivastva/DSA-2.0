#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int shortestDistance(vector<vector<int>>& mat, vector<int>& src, vector<int>& dest) {
    int n = mat.size();
    int m = mat[0].size();

    int sx = src[0];
    int sy = src[1];
    int dx = dest[0];
    int dy = dest[1];

    if (mat[sx][sy] == 0 || mat[dx][dy] == 0)
        return -1;

    if (sx == dx && sy == dy)
        return 0;

    vector<vector<int>> vis(n, vector<int>(m, 0));

    queue<pair<pair<int,int>, int>> q;
    q.push({{sx, sy}, 0});
    vis[sx][sy] = 1;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int dist = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if (nr >= 0 && nr < n &&
                nc >= 0 && nc < m &&
                mat[nr][nc] == 1 &&
                !vis[nr][nc]) {

                if (nr == dx && nc == dy)
                    return dist + 1;

                vis[nr][nc] = 1;
                q.push({{nr, nc}, dist + 1});
            }
        }
    }

    return -1;
}

int main() {
    vector<vector<int>> mat = {
        {1,1,1,1},
        {1,1,0,1},
        {1,1,1,1},
        {1,1,0,0},
        {1,0,0,1}
    };

    vector<int> src = {0,1};
    vector<int> dest = {2,2};

    cout << shortestDistance(mat, src, dest);

    return 0;
}