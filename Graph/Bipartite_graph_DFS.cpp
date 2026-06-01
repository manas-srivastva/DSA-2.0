#include<iostream>
#include<vector>
using namespace std;

bool isBip(int node,vector<int>adj[],vector<int>&color)
{
    for(int j=0;j<adj[node].size();j++)
    {
        if(color[adj[node][j]]==-1)
        {
            color[adj[node][j]]==(color[node]+1)%2;

            if(!isBip(adj[node][j],adj,color))
            return 0;
        }

        else{
            if(color[node]==color[adj[node][j]])
            return 0;
        }
    }
    return 1;

}


bool isBipartite(int V,vector<int>adj[]){
    vector<int>colour(V,-1);
    for(int i=0;i<V;i++)
    {
        if(colour[i]==-1) // not assigned
        {
            if(colour[i]==-1)
            {
                colour[i]=0;
                if(!isBip(i,adj,colour))
                return 0;

            }
        }
    }
    return 1;
}
int main(){
int V = 4;
    vector<int> adj[V];

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
        cout << "Graph is Bipartite\n";
    else
        cout << "Graph is Not Bipartite\n";
return 0;
}