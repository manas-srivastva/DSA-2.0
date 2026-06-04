#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;

vector<int> djkstra(int V, vector<vector<int>> adj[], int s)
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
                p.push({dist[neighbour], neighbour});
            }
        }
    }

    return dist;
}

int main(){

    int V = 5;

    vector<vector<int>> adj[V];

    adj[0].push_back({1,2});
    adj[0].push_back({2,4});

    adj[1].push_back({2,1});
    adj[1].push_back({3,7});

    adj[2].push_back({4,3});

    adj[3].push_back({4,1});

    vector<int> dist = djkstra(V, adj, 0);

    for(int i = 0; i < V; i++)
        cout << i << " -> " << dist[i] << endl;


    return 0;
}