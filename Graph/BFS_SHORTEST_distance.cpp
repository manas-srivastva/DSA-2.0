#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int>ShortestDistance(vector<vector<int>>&edges,int N,int M,int src)
{
    // adjajency list
    vector<int>adj[N];
    for(int i=0;i<M;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    vector<int>dist(N,-1);
    vector<bool>visited(N,0);

    queue<int>q;
    q.push(src);
    dist[src]=0;
    visited[src]=1;

    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(int j=0;j<adj[node].size();j++){
            if(visited[adj[node][j]])
            continue;

            visited[adj[node][j]]=1;
            q.push(adj[node][j]);
            dist[adj[node][j]]=dist[node]+1;

        }
    }

    return dist;
}
int main(){
int N, M;

    cout << "Enter number of vertices and edges: ";
    cin >> N >> M;

    vector<vector<int>> edges(M, vector<int>(2));

    cout << "Enter edges:\n";
    for(int i = 0; i < M; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }

    int src;
    cout << "Enter source node: ";
    cin >> src;

    vector<int> dist = ShortestDistance(edges, N, M, src);

    cout << "\nShortest distance from source " << src << ":\n";

    for(int i = 0; i < N; i++)
    {
        cout << "Node " << i << " -> " << dist[i] << endl;
    }
return 0;
}