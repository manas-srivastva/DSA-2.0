#include<iostream>
#include<vector>
using namespace std;

bool DetectCycle(int node,int parent,vector<int>adj[],vector<bool>&visited)
{
    visited[node]=1;
    for(int j=0;j<adj[node].size();j++){
        if(parent==adj[node][j])
        continue;

        if(visited[adj[node][j]]==1)
        return 1;

        if(DetectCycle(adj[node][j],node,adj,visited))
        return 1;
    }
    return 0;
}

bool isCycle(int V,vector<int>adj[]){
    vector<bool>visited(V,0);
    for(int i=0;i<V;i++){
    if(!visited[i] && DetectCycle(i,-1,adj,visited)){
    return 1;
    }
    }
    return 0;
}
int main(){
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
        adj[v].push_back(u); // Undirected graph
    }

    if(isCycle(V, adj))
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle Found\n";
return 0;
}