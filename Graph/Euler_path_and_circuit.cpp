#include<iostream>
#include<vector>
using namespace std;

void DFS(int node,vector<int>adj[],vector<bool>&visited)
{
    visited[node]=1;
    for(int j=0;j<adj[node].size();j++)
    {
        if(!visited[adj[node][j]]){
            DFS(adj[node][j],adj,visited);
        }
    }
}

    int isEulerCircuit(int V,vector<int>adj[])
    {
        vector<int>Deg(V,0);
        int odd_deg=0; // no of nodes having odd edges
        for(int i=0;i<V;i++)
        {
            Deg[i]=adj[i].size();
            if(Deg[i]%2)
            odd_deg++;
        }
        if(odd_deg!=2 && odd_deg!=0)

        return 0;

        vector<bool>visited(V,0);
        for(int i=0;i<V;i++){
            if(Deg[i])
            {
                DFS(i,adj,visited);
                break;
            }
        }
        for(int i=0;i<V;i++){
            if(Deg[i]&& !visited[i])
            return 0;
        }
        if(odd_deg==0)
        return 2;
        else
        return 1;
    }

int main(){
int V = 5;
    vector<int> adj[V];

    // Undirected graph edges
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[3].push_back(0);
    adj[0].push_back(3);

    adj[3].push_back(4);
    adj[4].push_back(3);

    int ans = isEulerCircuit(V, adj);

    if(ans == 2)
        cout << "Euler Circuit Exists";
    else if(ans == 1)
        cout << "Euler Path Exists but not Euler Circuit";
    else
        cout << "Neither Euler Path nor Euler Circuit Exists";
return 0;
}