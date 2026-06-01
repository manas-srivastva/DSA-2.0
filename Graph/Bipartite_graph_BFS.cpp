#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool isBipartite(int V,vector<int>adj[]){
    vector<int>color(V,-1);
    queue<int>q;
    for(int i=0;i<V;i++){
        if(color[i]==-1)
        {
            q.push(i);
            color[i]=0;
            while(!q.empty())
            {
                int node=q.front();
                q.pop();

                for(int j=0;j<adj[node].size();j++)
                {
                    // color not assigned
                    if(color[adj[node][j]]==-1)
                    {
                        color[adj[node][j]]=(color[node]+1)%2;
                        q.push(adj[node][j]);
                    }
                    // color is assigned
                    else{
                        if(color[node]==color[adj[node][j]])
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}
int main(){
int V = 4;

    vector<int> adj[V];

    // Graph:
    // 0 -- 1
    // |    |
    // 3 -- 2

    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[3].push_back(0);
    adj[0].push_back(3);

    if(isBipartite(V, adj))
        cout << "Graph is Bipartite";
    else
        cout << "Graph is Not Bipartite";
return 0;
}