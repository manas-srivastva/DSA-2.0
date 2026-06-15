#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    int timer = 0;

    void dfs(int node, int parent,
             vector<vector<int>>& adj,
             vector<int>& vis,
             vector<int>& tin,
             vector<int>& low,
             vector<int>& mark) {

        vis[node] = 1;
        tin[node] = low[node] = timer++;

        int child = 0;

        for (int neigh : adj[node]) {

            if (neigh == parent)
                continue;

            if (!vis[neigh]) {

                dfs(neigh, node, adj, vis, tin, low, mark);

                low[node] = min(low[node], low[neigh]);

                // Articulation Point Condition
                if (low[neigh] >= tin[node] && parent != -1) {
                    mark[node] = 1;
                }

                child++;
            }
            else {
                // Back Edge
                low[node] = min(low[node], tin[neigh]);
            }
        }

        // Root Node Condition
        if (parent == -1 && child > 1) {
            mark[node] = 1;
        }
    }

public:
    vector<int> articulationPoints(int V, vector<vector<int>>& adj) {

        vector<int> vis(V, 0);
        vector<int> tin(V);
        vector<int> low(V);
        vector<int> mark(V, 0);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, -1, adj, vis, tin, low, mark);
            }
        }

        vector<int> ans;

        for (int i = 0; i < V; i++) {
            if (mark[i])
                ans.push_back(i);
        }

        if (ans.empty())
            return {-1};

        return ans;
    }
};

int main() {

    int V = 5;

    vector<vector<int>> adj(V);

    // Example Graph
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[3].push_back(4);
    adj[4].push_back(3);

    Solution obj;

    vector<int> ans = obj.articulationPoints(V, adj);

    cout << "Articulation Points: ";
    for (int x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}