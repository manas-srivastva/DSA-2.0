#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>
using namespace std;

vector<int>ShortestDistance(vector<vector<int>>&edges,int N,int M,int src,int dest)
{
    // adjajency list
    vector<int>adj[N];
    for(int i=0;i<M;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    
    vector<bool>visited(N,0);

    queue<int>q;
    q.push(src);
  vector<int>parent(N,-1);
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
            parent[adj[node][j]]=node;

        }
    }

 vector<int>path;
 while(dest!=-1){
    path.push_back(dest);
    dest=parent[dest];
 }
 reverse(path.begin(),path.end());
 return path;
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

    int src, dest;
    cout << "Enter source and destination: ";
    cin >> src >> dest;

    vector<int> path = ShortestDistance(edges, N, M, src, dest);

    cout << "Shortest Path: ";

    for(int i = 0; i < path.size(); i++)
    {
        cout << path[i];

        if(i != path.size() - 1)
            cout << " -> ";
    }

    cout << endl;
return 0;
}