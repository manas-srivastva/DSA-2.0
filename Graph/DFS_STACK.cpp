#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> DFS(vector<int> adj[], int vertices)
{
    vector<int> visited(vertices, 0);
    vector<int> ans;
    stack<int> st;

    st.push(0);

    while(!st.empty())
    {
        int node = st.top();
        st.pop();

        if(visited[node] == 0)
        {
            visited[node] = 1;
            ans.push_back(node);

            for(int i = adj[node].size()-1; i >= 0; i--)
            {
                int neighbour = adj[node][i];

                if(visited[neighbour] == 0)
                {
                    st.push(neighbour);
                }
            }
        }
    }

    return ans;
}