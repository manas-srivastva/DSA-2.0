#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> djkstra(int V, vector<vector<int>> adj[], int s,
                    vector<int>& parent)
{
    vector<bool> Explored(V, 0);
    vector<int> dist(V, INT_MAX);

    dist[s] = 0;

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > p;

    p.push({0, s});

    while(!p.empty())
    {
        int node = p.top().second;
        p.pop();

        if(Explored[node])
            continue;

        Explored[node] = 1;

        for(int j = 0; j < adj[node].size(); j++)
        {
            int neighbour = adj[node][j][0];
            int weight = adj[node][j][1];

            if(!Explored[neighbour] &&
               dist[node] + weight < dist[neighbour])
            {
                dist[neighbour] = dist[node] + weight;
                parent[neighbour] = node;     // store predecessor
                p.push({dist[neighbour], neighbour});
            }
        }
    }

    return dist;
}

int main()
{
    int V = 5;

    vector<vector<int>> adj[V];

    adj[0].push_back({1,2});
    adj[0].push_back({2,4});

    adj[1].push_back({2,1});
    adj[1].push_back({3,7});

    adj[2].push_back({4,3});

    adj[3].push_back({4,1});

    vector<int> parent(V, -1);

    vector<int> dist = djkstra(V, adj, 0, parent);

    int destination = 4;

    cout << "Shortest Distance = "
         << dist[destination] << endl;

    vector<int> path;

    for(int v = destination; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());

    cout << "Path: ";

    for(int i = 0; i < path.size(); i++)
    {
        cout << path[i];

        if(i + 1 < path.size())
            cout << " -> ";
    }

    cout << endl;

    return 0;
} 