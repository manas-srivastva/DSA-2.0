#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    bool can(long long lim,
             vector<vector<pair<int, long long> > >& adj,
             vector<int>& topo,
             vector<bool>& online,
             long long k,
             int n) {

        long long INF = LLONG_MAX;
        vector<long long> dist(n, INF);
        dist[0] = 0;

        for (int i = 0; i < (int)topo.size(); i++) {
            int u = topo[i];

            if (dist[u] == INF)
                continue;

            if (u != 0 && u != n - 1 && !online[u])
                continue;

            for (int j = 0; j < (int)adj[u].size(); j++) {

                int v = adj[u][j].first;
                long long w = adj[u][j].second;

                if (w < lim)
                    continue;

                if (v != 0 && v != n - 1 && !online[v])
                    continue;

                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        return dist[n - 1] <= k;
    }

    int findMaxPathScore(vector<vector<int> >& edges,
                         vector<bool>& online,
                         long long k) {

        int n = online.size();

        vector<vector<pair<int, long long> > > adj(n);
        vector<int> indeg(n, 0);
        vector<long long> vals;

        for (int i = 0; i < (int)edges.size(); i++) {

            int u = edges[i][0];
            int v = edges[i][1];
            long long w = edges[i][2];

            adj[u].push_back(make_pair(v, w));
            indeg[v]++;

            vals.push_back(w);
        }

        if (vals.empty())
            return -1;

        queue<int> q;
        vector<int> topo;

        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {

            int u = q.front();
            q.pop();

            topo.push_back(u);

            for (int i = 0; i < (int)adj[u].size(); i++) {

                int v = adj[u][i].first;

                indeg[v]--;

                if (indeg[v] == 0)
                    q.push(v);
            }
        }

        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        if (!can(vals[0], adj, topo, online, k, n))
            return -1;

        int l = 0;
        int r = vals.size() - 1;
        long long ans = vals[0];

        while (l <= r) {

            int mid = l + (r - l) / 2;

            if (can(vals[mid], adj, topo, online, k, n)) {
                ans = vals[mid];
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        return (int)ans;
    }
};

int main() {

    Solution obj;

    vector<vector<int> > edges = {
        {0,1,5},
        {1,3,10},
        {0,2,3},
        {2,3,4}
    };

    vector<bool> online = {true, true, true, true};

    long long k = 10;

    cout << obj.findMaxPathScore(edges, online, k);

    return 0;
}


/*
// djkstra

class Solution {
public:

    bool can(long long lim,
             vector<vector<pair<int, long long> > >& adj,
             vector<bool>& online,
             long long k,
             int n) {

        long long INF = (long long)4e18;

        vector<long long> dist(n, INF);
        dist[0] = 0;

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int> >,
            greater<pair<long long, int> >
        > pq;

        pq.push({0, 0});

        while (!pq.empty()) {

            long long d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[u])
                continue;

            if (u != 0 && u != n - 1 && !online[u])
                continue;

            for (int i = 0; i < (int)adj[u].size(); i++) {

                int v = adj[u][i].first;
                long long w = adj[u][i].second;

                if (w < lim)
                    continue;

                if (v != 0 && v != n - 1 && !online[v])
                    continue;

                if (dist[u] + w < dist[v]) {

                    dist[v] = dist[u] + w;

                    pq.push({dist[v], v});
                }
            }
        }

        return dist[n - 1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges,
                         vector<bool>& online,
                         long long k) {

        int n = online.size();

        vector<vector<pair<int, long long> > > adj(n);
        vector<long long> vals;

        for (int i = 0; i < (int)edges.size(); i++) {

            int u = edges[i][0];
            int v = edges[i][1];
            long long w = edges[i][2];

            adj[u].push_back({v, w});

            vals.push_back(w);
        }

        if (vals.empty())
            return -1;

        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        if (!can(vals[0], adj, online, k, n))
            return -1;

        int l = 0;
        int r = (int)vals.size() - 1;

        long long ans = vals[0];

        while (l <= r) {

            int mid = l + (r - l) / 2;

            if (can(vals[mid], adj, online, k, n)) {

                ans = vals[mid];
                l = mid + 1;

            } else {

                r = mid - 1;
            }
        }

        return (int)ans;
    }
};

*/