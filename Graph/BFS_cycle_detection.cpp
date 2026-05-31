#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool DetectCycle(int start, vector<int> adj[], vector<bool>& visited)
{
    queue<pair<int,int>> q;

    visited[start] = true;
    q.push({start, -1});

    while(!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(int j = 0; j < adj[node].size(); j++)
        {
            if(parent == adj[node][j])
                continue;

            if(visited[adj[node][j]])
                return true;

            visited[adj[node][j]] = true;
            q.push({adj[node][j], node});
        }
    }

    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);

    for(int i = 0; i < V; i++)
    {
        if(!visited[i])
        {
            if(DetectCycle(i, adj, visited))
                return true;
        }
    }

    return false;
}

int main()
{
    int V, E;

    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<int> adj[V];

    cout << "Enter edges:\n";

    for(int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);   // Undirected Graph
    }

    if(isCycle(V, adj))
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle Found\n";

    return 0;
}