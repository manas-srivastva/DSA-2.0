#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void DFS(int node, int parent,
             vector<vector<int>>& adj,
             vector<int>& disc,
             vector<int>& low,
             vector<bool>& visited,
             vector<vector<int>>& Bridges,
             int& count)
    {
        disc[node] = low[node] = count;
        visited[node] = true;

        for (int j = 0; j < adj[node].size(); j++)
        {
            int neib = adj[node][j];

            if (neib == parent)
                continue;

            else if (visited[neib])
            {
                low[node] = min(low[node], disc[neib]);
            }
            else
            {
                count++;

                DFS(neib, node, adj, disc, low, visited, Bridges, count);

                low[node] = min(low[node], low[neib]);

                // Bridge condition
                if (low[neib] > disc[node])
                {
                    Bridges.push_back({node, neib});
                }
            }
        }
    }

    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections)
    {
        vector<vector<int>> adj(n);

        for (int i = 0; i < connections.size(); i++)
        {
            int u = connections[i][0];
            int v = connections[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<int>> Bridges;
        vector<int> disc(n);
        vector<int> low(n);
        vector<bool> visited(n, false);

        int count = 0;

        // Handle disconnected graphs
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                DFS(i, -1, adj, disc, low, visited, Bridges, count);
            }
        }

        return Bridges;
    }
};

int main()
{
    int n, m;

    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> connections;

    cout << "Enter edges:\n";

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        connections.push_back({u, v});
    }

    Solution obj;

    vector<vector<int>> bridges =
        obj.criticalConnections(n, connections);

    cout << "\nBridges in the graph are:\n";

    if (bridges.empty())
    {
        cout << "No bridges found.\n";
    }
    else
    {
        for (auto &edge : bridges)
        {
            cout << edge[0] << " - " << edge[1] << endl;
        }
    }

    return 0;
}