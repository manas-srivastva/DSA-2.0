#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> topoSort(int V,vector<int>adj[])
{
    vector<int>ans;
    vector<int>InDeg(V,0); // store the indegree of every node

    for(int i=0;i<V;i++)
    for(int j=0;j<adj[i].size();j++)
    InDeg[adj[i][j]]++;

    // push all the node of zero indegree into queue
    queue<int>q;
    for(int i=0;i<V;i++)
    if(!InDeg[i])
    q.push(i);

    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        ans.push_back(node);

        // neighbour ,unki indegree ko decrease karna hai
        for(int j=0;j<adj[node].size();j++)
        {
            InDeg[adj[node][j]]--;
            if(InDeg[adj[node][j]]==0)
            q.push(adj[node][j]);
        }
    }
    return ans;
}
int main(){
 int V,E;

    cout<<"Enter number of vertices and edges: ";
    cin>>V>>E;

    vector<int> adj[V];

    cout<<"Enter directed edges (u v):\n";

    for(int i=0;i<E;i++)
    {
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
    }

    vector<int> result=topoSort(V,adj);

    cout<<"Topological Sort: ";

    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }

    cout<<endl;
return 0;
}