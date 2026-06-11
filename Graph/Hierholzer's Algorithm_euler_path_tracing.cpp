#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
vector<int> findEulerPath(int V,vector<int>adj[])
{
    vector<vector<int>> graph(V);

    // copy adjacency list
    for(int i=0;i<V;i++)
    graph[i]=vector<int>(adj[i].begin(),adj[i].end());

    int start=0,odd=0;

    // Find odd degree vertices
    for(int i=0;i<V;i++){
        if(graph[i].size()%2)
        {
            odd++;
            start=i;
        }
    }

    // If no odd degree vertex, start anywhere with degree>0
    if(odd==0)
    {
        for(int i=0;i<V;i++){
            if(!graph[i].empty())
            {
                start=i;
                break;

            }
        }
    }

    stack<int>st;
    vector<int>path;
    st.push(start);

    while(!st.empty())
    {
        int u=st.top();
        if(!graph[u].empty())
        {
            int v=graph[u].back();
            graph[u].pop_back();

            // remove u from v's list
            for(auto it=graph[v].begin();it!=graph[v].end();it++)
            {
                if(*it==u)
                {
                    graph[v].erase(it);
                    break;
                }
            }
            st.push(v);
        }
        else{
            path.push_back(u);
            st.pop();
        }
    }
    reverse(path.begin(),path.end());
    return path;
}

int main(){
int V = 5;
    vector<int> adj[V];

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

    vector<int> eulerPath = findEulerPath(V, adj);

    cout << "Euler Path/Circuit: ";
    for(int x : eulerPath)
        cout << x << " ";
return 0;
}