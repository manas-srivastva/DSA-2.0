#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> BFS(vector<int>adj[],int vertices){
    vector<int>visited(vertices,0);
    vector<int>ans;
    queue<int>q;
    

    visited[0]=1;
    q.push(0);

    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        ans.push_back(node);

        for(int i=0;i<adj[node].size();i++){
            int neighbour=adj[node][i];

            if(visited[neighbour]==0)
            {
                visited[neighbour]=1;
                q.push(neighbour);
                
            }
        }
    }
    return ans;
}
int main(){
int vertices,edges;
cin>>vertices>>edges;
vector<int> adj[vertices];
int u,v;

for(int i=0;i<edges;i++){
    cin>>u>>v;

    adj[u].push_back(v);
    adj[v].push_back(u);
}

vector<int> result=BFS(adj,vertices);

for(int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

return 0;
}