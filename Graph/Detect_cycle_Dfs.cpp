#include<iostream>
#include<vector>
using namespace std;

bool detectCycle(int node,vector<int>adj[],vector<bool>&path,vector<bool>&visited){
    path[node]=1;
    for(int j=0;j<adj[node].size();j++)
    {
        if(path[adj[node][j]])
        return 1;

        if(visited[adj[node][j]])
        continue;

        if(detectCycle(adj[node][j],adj,path,visited))
        return 1;
    }
    path[node]=0;
    return 0;
}

bool isCycle(int V,vector<int>adj[]){
    vector<bool>path(V,0);
    vector<bool>visited(V,0);

    for(int i=0;i<V;i++)
    {
        if(!visited[i] && detectCycle(i,adj,path,visited))
        return 1;
    }
}
int main(){
    int V = 4;

    vector<int> adj[V];

    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1);   

    if(isCycle(V, adj))
        cout << "Cycle Found";
    else
        cout << "No Cycle";
return 0;
}