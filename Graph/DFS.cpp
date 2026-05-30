#include<iostream>
#include<vector>
using namespace std;
void DFS(int node,vector<int> adj[],vector<int> &visited,vector<int>& ans){
    visited[node]=1;
    ans.push_back(node);
    for(int i=0;i<adj[node].size();i++)
    {
        int neighbour=adj[node][i];
        if(visited[neighbour]==0)
        {
            DFS(neighbour,adj,visited,ans);
        }
    }

}

vector<int> dfsTraversal(vector<int>adj[],int vertices)
{
    vector<int>visited(vertices,0);
    vector<int> ans;

    DFS(0,adj,visited,ans);

    return ans;
}

int main(){
int vertices,edges;
cin>>vertices>>edges;

vector<int>adj[vertices];
int u,v;
for(int i=0;i<edges;i++){
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}

vector<int> result=dfsTraversal(adj,vertices);
cout<<"DFS TRAVERSAL: ";
for(int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
return 0;
}
