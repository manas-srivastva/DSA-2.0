#include <iostream>
#include <vector>
using namespace std;

vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
    vector<int> comp(n);
    comp[0] = 0;

    for (int i = 1; i < n; i++) {
        if (nums[i] - nums[i - 1] <= maxDiff)
            comp[i] = comp[i - 1];
        else
            comp[i] = comp[i - 1] + 1;
    }

    vector<bool> ans;

    for (int i = 0; i < queries.size(); i++) {
        int u = queries[i][0];
        int v = queries[i][1];

        ans.push_back(comp[u] == comp[v]);
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int maxDiff;
    cin >> maxDiff;

    int q;
    cin >> q;

    vector<vector<int>> queries(q, vector<int>(2));

    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1];
    }

    vector<bool> ans = pathExistenceQueries(n, nums, maxDiff, queries);

    for (int i = 0; i < ans.size(); i++) {
        cout << (ans[i] ? "true" : "false") << " ";
    }

    cout << endl;

    return 0;
}