#include<iostream>
#include<vector>
using namespace std;

vector<int> bellmanford(int V, vector<vector<int>>& edges, int S)
{
    vector<int> dist(V, 1e8);
    dist[S] = 0;

    int e = edges.size();

    // Relax all edges V-1 times
    for(int i = 0; i < V - 1; i++)
    {
        bool flag = 0;

        for(int j = 0; j < e; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if(dist[u] == 1e8)
                continue;

            if(dist[u] + wt < dist[v])
            {
                flag = 1;
                dist[v] = dist[u] + wt;
            }
        }

        // Optimization: stop if no update occurs
        if(flag == 0)
            break;
    }

    // Check for negative weight cycle
    for(int j = 0; j < e; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if(dist[u] == 1e8)
            continue;

        if(dist[u] + wt < dist[v])
        {
            return {-1};
        }
    }

    return dist;
}

int main()
{
    int V = 5;

    vector<vector<int>> edges = {
        {0, 1, 6},
        {0, 2, 7},
        {1, 2, 8},
        {1, 3, 5},
        {1, 4, -4},
        {2, 3, -3},
        {2, 4, 9},
        {3, 1, -2},
        {4, 0, 2},
        {4, 3, 7}
    };

    int source = 0;

    vector<int> ans = bellmanford(V, edges, source);

    if(ans.size() == 1 && ans[0] == -1)
    {
        cout << "Negative Weight Cycle Detected" << endl;
    }
    else
    {
        cout << "Shortest distances from source " << source << ":\n";

        for(int i = 0; i < V; i++)
        {
            cout << "Vertex " << i << " : " << ans[i] << endl;
        }
    }

    return 0;
}