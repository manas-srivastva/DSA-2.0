#include <bits/stdc++.h>
using namespace std;

int removeCoveredIntervals(vector<vector<int>>& intervals) {
    int n = intervals.size();

    auto cmp = [](vector<int>& a, vector<int>& b) {
        if (a[0] == b[0])
            return a[1] > b[1];

        return a[0] < b[0];
    };

    sort(intervals.begin(), intervals.end(), cmp);

    vector<vector<int>> result;
    result.push_back(intervals[0]);

    for (int i = 1; i < n; i++) {
        if (result.back()[0] <= intervals[i][0] &&
            result.back()[1] >= intervals[i][1]) {
            continue;
        }

        result.push_back(intervals[i]);
    }

    return result.size();
}

int main() {
    vector<vector<int>> intervals = {{1,4}, {3,6}, {2,8}};

    cout << removeCoveredIntervals(intervals) << endl;

    return 0;
}