#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int>djkstra(int V,vector<vector<int>>adj[],int s)
{
    vector<bool>Explored(V,0);
    vector<int>dist(V,INT_MAX);
    dist[s]=0;

// select a node which is not explored yet and its distance value is min
    int count=V;
    while(count--){
    int node=-1,value=INT_MAX;

    for(int i=0;i<V;i++){
        if(!Explored[i]&& value>dist[i])
        {
            node=i;
            value=dist[i];
        }
    }
    Explored[node]=1;


    // relax the edges
    for(int j=0;j<adj[node].size();j++)
    {
        int neighbour=adj[node][j][0];
        int weight=adj[node][j][1];

        if(!Explored[neighbour]&& (dist[node]+weight<dist[neighbour]))
        dist[neighbour]=dist[node]+weight;
    }
    }
return dist;
}
int main(){

  int V = 5;

    vector<vector<int>> adj[V];

    // u -> v (weight)

    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});

    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});

    adj[2].push_back({4, 3});

    adj[3].push_back({4, 1});

    int source = 0;

    vector<int> dist = djkstra(V, adj, source);

    cout << "Shortest distances from source " << source << ":\n";

    for(int i = 0; i < V; i++)
    {
        cout << i << " -> " << dist[i] << endl;
    }

    return 0;
}