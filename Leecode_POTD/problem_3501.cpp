#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    struct Segment {
        int type; // 0 or 1
        int start;
        int end;
        int len;
    };

    vector<int> tree;

    void buildTree(const vector<int>& vals, int node, int start, int end) {
        if (start == end) {
            tree[node] = vals[start];
            return;
        }
        int mid = start + (end - start) / 2;
        buildTree(vals, 2 * node, start, mid);
        buildTree(vals, 2 * node + 1, mid + 1, end);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    int queryTree(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = start + (end - start) / 2;
        int p1 = queryTree(2 * node, start, mid, l, r);
        int p2 = queryTree(2 * node + 1, mid + 1, end, l, r);
        return max(p1, p2);
    }

public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int totalOnes = 0;
        for (char c : s) {
            if (c == '1') totalOnes++;
        }

        // Group contiguous characters into segments
        vector<Segment> segs;
        vector<int> charToSegIdx(n);

        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            int segIdx = segs.size();
            segs.push_back({s[i] - '0', i, j - 1, j - i});
            for (int k = i; k < j; k++) {
                charToSegIdx[k] = segIdx;
            }
            i = j;
        }

        int m = segs.size();
        vector<int> val(m, 0);

        // Precompute gain for fully internal 1-segments
        for (int i = 0; i < m; i++) {
            if (segs[i].type == 1) {
                if (i > 0 && i + 1 < m) {
                    val[i] = segs[i - 1].len + segs[i + 1].len;
                }
            }
        }

        // Build Segment Tree over gains
        if (m > 0) {
            tree.resize(4 * m, 0);
            buildTree(val, 1, 0, m - 1);
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int L = q[0], R = q[1];

            int segL = charToSegIdx[L];
            int segR = charToSegIdx[R];

            int firstOneSeg = segL + 1;
            int lastOneSeg = segR - 1;

            if (firstOneSeg < m && segs[firstOneSeg].type != 1) firstOneSeg++;
            if (lastOneSeg >= 0 && segs[lastOneSeg].type != 1) lastOneSeg--;

            while (firstOneSeg < m && (segs[firstOneSeg].type != 1 || segs[firstOneSeg].start <= L || segs[firstOneSeg].end >= R)) {
                firstOneSeg += 2;
            }
            while (lastOneSeg >= 0 && (segs[lastOneSeg].type != 1 || segs[lastOneSeg].start <= L || segs[lastOneSeg].end >= R)) {
                lastOneSeg -= 2;
            }

            int maxGain = 0;

            if (firstOneSeg <= lastOneSeg && firstOneSeg >= 0) {
                auto getGain = [&](int idx) {
                    int left0Len = segs[idx - 1].end - max(segs[idx - 1].start, L) + 1;
                    int right0Len = min(segs[idx + 1].end, R) - segs[idx + 1].start + 1;
                    return left0Len + right0Len;
                };

                maxGain = max(maxGain, getGain(firstOneSeg));
                maxGain = max(maxGain, getGain(lastOneSeg));

                int innerFirst = firstOneSeg;
                if (segs[innerFirst - 1].start < L) innerFirst += 2;

                int innerLast = lastOneSeg;
                if (segs[innerLast + 1].end > R) innerLast -= 2;

                if (innerFirst <= innerLast) {
                    maxGain = max(maxGain, queryTree(1, 0, m - 1, innerFirst, innerLast));
                }
            }

            ans.push_back(totalOnes + maxGain);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Testcase 1
    string s1 = "0100";
    vector<vector<int>> queries1 = {{0, 3}, {0, 2}, {1, 3}, {2, 3}};
    vector<int> res1 = sol.maxActiveSectionsAfterTrade(s1, queries1);

    cout << "Testcase 1 Output: ";
    for (int x : res1) cout << x << " ";
    cout << "\n"; // Expected: 4 3 1 1

    return 0;
}