#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int spanningTree(int V,vector<vector<int>>adj[]){
    // priority queue
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    vector<bool>IsMst(V,0);
    vector<int>parent(V);

    int cost=0;
    pq.push({0,{0,-1}});
    while(!pq.empty())
    {
        int wt=pq.top().first;
        int node=pq.top().second.first;
        int par=pq.top().second.second;
        pq.pop();

        if(!IsMst[node])
        {
            IsMst[node]=1;
            cost+=wt;
                parent[node]=par;


        // neighbours(pushing)
        for(int j=0;j<adj[node].size();j++){
            if(!IsMst[adj[node][j][0]])
            {
                pq.push({adj[node][j][1],{adj[node][j][0],node}});
            }
        }
        }
    }
           
    return cost;
}
int main(){
     int V = 5;

    vector<vector<int>> adj[V];

    // Edge 0-1 weight 2
    adj[0].push_back({1,2});
    adj[1].push_back({0,2});

    // Edge 0-3 weight 6
    adj[0].push_back({3,6});
    adj[3].push_back({0,6});

    // Edge 1-2 weight 3
    adj[1].push_back({2,3});
    adj[2].push_back({1,3});

    // Edge 1-3 weight 8
    adj[1].push_back({3,8});
    adj[3].push_back({1,8});

    // Edge 1-4 weight 5
    adj[1].push_back({4,5});
    adj[4].push_back({1,5});

    // Edge 2-4 weight 7
    adj[2].push_back({4,7});
    adj[4].push_back({2,7});

    cout << "Cost of MST = " << spanningTree(V, adj);
    return 0;
}