#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:

    struct Node {
        int cost;
        int x;
        int y;
    };

    struct cmp {
        bool operator()(Node &a, Node &b) {
            return a.cost > b.cost;
        }
    };

    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        priority_queue<Node, vector<Node>, cmp> pq;

        dist[0][0] = grid[0][0];

        pq.push({dist[0][0], 0, 0});

        int dir[4][2] = {
            {1,0},
            {-1,0},
            {0,1},
            {0,-1}
        };

        while (!pq.empty()) {

            Node cur = pq.top();
            pq.pop();

            int cost = cur.cost;
            int x = cur.x;
            int y = cur.y;

            if (cost > dist[x][y])
                continue;

            if (x == m - 1 && y == n - 1)
                return cost < health;

            for (int i = 0; i < 4; i++) {

                int nx = x + dir[i][0];
                int ny = y + dir[i][1];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;

                int newCost = cost + grid[nx][ny];

                if (newCost < dist[nx][ny]) {

                    dist[nx][ny] = newCost;

                    pq.push({newCost, nx, ny});
                }
            }
        }

        return false;
    }
};

int main() {

    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int health;
    cin >> health;

    Solution obj;

    if (obj.findSafeWalk(grid, health))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}