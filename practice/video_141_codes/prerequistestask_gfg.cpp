#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isPossible(int N, int P, vector<pair<int, int>>& prerequisites)
{
    vector<int> adj[N];
    vector<int> indegree(N, 0);

    // Create adjacency list and indegree array
    for (int i = 0; i < P; i++)
    {
        int u = prerequisites[i].second;
        int v = prerequisites[i].first;

        adj[u].push_back(v);
        indegree[v]++;
    }

    // Kahn's Algorithm
    queue<int> q;

    for (int i = 0; i < N; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    int count = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        count++;

        for (int neigh : adj[node])
        {
            indegree[neigh]--;

            if (indegree[neigh] == 0)
                q.push(neigh);
        }
    }

    return count == N;
}

int main()
{
    int N, P;

    cout << "Enter number of tasks/courses: ";
    cin >> N;

    cout << "Enter number of prerequisites: ";
    cin >> P;

    vector<pair<int, int>> prerequisites;

    cout << "Enter prerequisite pairs (course prerequisite):\n";
    for (int i = 0; i < P; i++)
    {
        int course, prerequisite;
        cin >> course >> prerequisite;

        prerequisites.push_back({course, prerequisite});
    }

    if (isPossible(N, P, prerequisites))
        cout << "All tasks can be completed.\n";
    else
        cout << "All tasks cannot be completed (Cycle exists).\n";

    return 0;
}