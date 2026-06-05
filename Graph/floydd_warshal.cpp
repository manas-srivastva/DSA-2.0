#include <iostream>
#include <vector>
using namespace std;

void floydWarshall(vector<vector<int>>& dist, int V)
{
    // Try every vertex as an intermediate vertex
    for(int via = 0; via < V; via++)
    {
        for(int i = 0; i < V; i++)
        {
            for(int j = 0; j < V; j++)
            {
                if(dist[i][via] == 1e8 || dist[via][j] == 1e8)
                    continue;

                dist[i][j] = min(dist[i][j],
                                 dist[i][via] + dist[via][j]);
            }
        }
    }
}

int main()
{
    int V = 4;
    int INF = 1e8;

    vector<vector<int>> dist = {
        {0,   3,   INF, 5},
        {2,   0,   INF, 4},
        {INF, 1,   0,   INF},
        {INF, INF, 2,   0}
    };

    floydWarshall(dist, V);

    cout << "Shortest Distance Matrix:\n";

    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            if(dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}