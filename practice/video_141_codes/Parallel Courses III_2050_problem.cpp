#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
    
    // Create adjacency list
    vector<vector<int>> adj(n);

    for (int i = 0; i < relations.size(); i++) {
        // Convert to 0-based indexing
        adj[relations[i][0] - 1].push_back(relations[i][1] - 1);
    }

    vector<int> indeg(n, 0);

    // Calculate indegree
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            indeg[adj[i][j]]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }

    // Maximum time needed before starting each course
    vector<int> courseTime(n, 0);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int j = 0; j < adj[node].size(); j++) {
            int next = adj[node][j];

            courseTime[next] = max(courseTime[next],
                                   courseTime[node] + time[node]);

            indeg[next]--;

            if (indeg[next] == 0) {
                q.push(next);
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        ans = max(ans, courseTime[i] + time[i]);
    }

    return ans;
}

int main() {
    int n, m;

    cout << "Enter number of courses and relations: ";
    cin >> n >> m;

    vector<vector<int>> relations(m, vector<int>(2));

    cout << "Enter relations (u v):\n";
    for (int i = 0; i < m; i++) {
        cin >> relations[i][0] >> relations[i][1];
    }

    vector<int> time(n);

    cout << "Enter time for each course:\n";
    for (int i = 0; i < n; i++) {
        cin >> time[i];
    }

    cout << "Minimum time required: "
         << minimumTime(n, relations, time) << endl;

    return 0;
}