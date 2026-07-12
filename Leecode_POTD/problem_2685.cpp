#include <iostream>
#include <vector>

using namespace std;

// DFS helper function to count nodes and total degrees in a component
void dfs(int node, const vector<vector<int>>& adj, vector<bool>& vis, int& nodeCount, int& edgeCount) {
    vis[node] = true; // Mark as visited
    nodeCount++;
    edgeCount += adj[node].size(); // Accumulate the degree of the node

    for (int neighbor : adj[node]) {
        if (!vis[neighbor]) {
            dfs(neighbor, adj, vis, nodeCount, edgeCount);
        }
    }
}

// Function to count the number of complete connected components
int countCompleteComponents(int n, const vector<vector<int>>& edges) {
    // Build the adjacency list
    vector<vector<int>> adj(n);
    for (const auto& e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    
    vector<bool> vis(n, false);
    int completeComponents = 0;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            int nodeCount = 0;
            int edgeCount = 0;

            // Traverse the entire component and accumulate counts
            dfs(i, adj, vis, nodeCount, edgeCount);

            // Total undirected edges = accumulated degrees / 2
            // For a component to be complete, edges must equal: V * (V - 1) / 2
            if (edgeCount / 2 == (nodeCount * (nodeCount - 1)) / 2) {
                completeComponents++;
            }
        }
    }
    return completeComponents;
}

int main() {
    // Example test case:
    // 6 nodes, edges forming two components:
    // Component 1: {0, 1, 2} (Complete graph K3)
    // Component 2: {3, 4, 5} (Missing edge between 3 and 5, not complete)
    int n = 6;
    vector<vector<int>> edges = {
        {0, 1}, {1, 2}, {2, 0}, // Complete K3 component
        {3, 4}, {4, 5}          // Linear path component (not complete)
    };

    int result = countCompleteComponents(n, edges);
    
    cout << "Number of complete components: " << result << endl; 

    return 0;
}