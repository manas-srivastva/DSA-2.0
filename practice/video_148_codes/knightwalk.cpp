#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int minStepToReachTarget(vector<int>& KnightPos, vector<int>& TargetPos, int N)
{
    int sx = KnightPos[0] - 1;
    int sy = KnightPos[1] - 1;

    int dx = TargetPos[0] - 1;
    int dy = TargetPos[1] - 1;

    if(sx == dx && sy == dy)
        return 0;

    vector<vector<int>> vis(N, vector<int>(N, 0));

    queue<pair<pair<int,int>, int>> q;
    q.push({{sx, sy}, 0});
    vis[sx][sy] = 1;

    int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};

    while(!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        q.pop();

        for(int i = 0; i < 8; i++)
        {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if(nr >= 0 && nr < N &&
               nc >= 0 && nc < N &&
               !vis[nr][nc])
            {
                if(nr == dx && nc == dy)
                    return steps + 1;

                vis[nr][nc] = 1;
                q.push({{nr, nc}, steps + 1});
            }
        }
    }

    return -1;
}




int main()
{
    int N = 6;

    vector<int> KnightPos = {4, 5};
    vector<int> TargetPos = {1, 1};

    cout << minStepToReachTarget(KnightPos, TargetPos, N);

    return 0;
}