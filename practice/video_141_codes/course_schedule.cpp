#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> findOrder(int n, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);

    // Build graph
    for (int i = 0; i < prerequisites.size(); i++)
    {
        int u = prerequisites[i][1];
        int v = prerequisites[i][0];

        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;

    // Push all nodes with indegree 0
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> ans;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        ans.push_back(node);

        for (int neigh : adj[node])
        {
            indegree[neigh]--;

            if (indegree[neigh] == 0)
                q.push(neigh);
        }
    }

    if (ans.size() == n)
        return ans;

    return {};
}

int main()
{
    int n, p;

    cout << "Enter number of courses (vertices): ";
    cin >> n;

    cout << "Enter number of prerequisites (edges): ";
    cin >> p;

    vector<vector<int>> prerequisites(p, vector<int>(2));

    cout << "Enter prerequisite pairs (course prerequisite):\n";
    for (int i = 0; i < p; i++)
    {
        cin >> prerequisites[i][0] >> prerequisites[i][1];
    }

    vector<int> order = findOrder(n, prerequisites);

    if (order.empty())
    {
        cout << "Cycle detected. No valid ordering exists.\n";
    }
    else
    {
        cout << "Topological Order: ";
        for (int x : order)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}