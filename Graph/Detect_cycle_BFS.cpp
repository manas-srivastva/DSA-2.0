#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool detectCycle(int V,vector<int>adj[])
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
    int count=ans.size();
    return count!=V;
}
int main(){
{
    int V = 4;

    vector<int> adj[V];

    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1);   // creates cycle

    if(detectCycle(V, adj))
        cout << "Cycle Found";
    else
        cout << "No Cycle";
return 0;
}