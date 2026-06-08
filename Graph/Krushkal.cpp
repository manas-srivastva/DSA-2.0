#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int FindParent(int u,vector<int>&parent)
{
    if(u==parent[u])
    return u;

    return parent[u]=FindParent(parent[u],parent);
}

void UnionByRank(int u,int v,vector<int>&parent,vector<int>&rank){
    int pu=FindParent(u,parent);
    int pv=FindParent(v,parent);


    // rank,merge kar paauon
    if(rank[pu]>rank[pv])
    {
        parent[pv]=pu;
    }
    else if(rank[pu]<rank[pv])
    {
        parent[pu]=pv;
    }
    else{
        parent[pv]=pu;
        rank[pu]++;
    }
}

int spanningTree(int V,vector<vector<int>>adj[])
{
  vector<int>parent(V);  // ultimate parent will help us to determine set
  vector<int>rank(V,0);  // it will help us to merge the set
  for(int i=0;i<V;i++)
  parent[i]=i;

  // priority queue
  // wt,u,v
   priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
   for(int i=0;i<V;i++)
   {
    for(int j=0;j<adj[i].size();j++)
    {
        pq.push({adj[i][j][1],{i,adj[i][j][0]}});

    }
   }

   int cost=0;
   int edges=0;
   while(!pq.empty())
   {
    int wt=pq.top().first;
    int u=pq.top().second.first;
    int v=pq.top().second.second;
    pq.pop();

    // check if they are in different set

    if(FindParent(u,parent)!=FindParent(v,parent))
    {
        cost+=wt;
        UnionByRank(u,v,parent,rank);
    }
   }

   return cost;
}

int main(){
 int V = 4;

    vector<vector<int>> adj[V];

    // Edge 0 - 1 (weight 10)
    adj[0].push_back({1,10});
    adj[1].push_back({0,10});

    // Edge 0 - 2 (weight 6)
    adj[0].push_back({2,6});
    adj[2].push_back({0,6});

    // Edge 0 - 3 (weight 5)
    adj[0].push_back({3,5});
    adj[3].push_back({0,5});

    // Edge 1 - 3 (weight 15)
    adj[1].push_back({3,15});
    adj[3].push_back({1,15});

    // Edge 2 - 3 (weight 4)
    adj[2].push_back({3,4});
    adj[3].push_back({2,4});

    cout << "Cost of MST = "
         << spanningTree(V, adj);
return 0;
}