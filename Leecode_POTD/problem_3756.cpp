#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
typedef long long ll;

vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
    int n = s.length();

    vector<int> nonZeroCount(n, 0);
    vector<ll> numberUpTo(n, 0);
    vector<ll> digitSumTo(n, 0);
    vector<ll> pow10(n + 1, 0);

    pow10[0] = 1;
    for (int i = 1; i <= n; i++) {
        pow10[i] = (pow10[i - 1] * 10) % MOD;
    }

    nonZeroCount[0] = (s[0] != '0') ? 1 : 0;
    for (int i = 1; i < n; i++) {
        int digit = s[i] - '0';
        nonZeroCount[i] = nonZeroCount[i - 1] + (digit != 0);
    }

    numberUpTo[0] = s[0] - '0';
    for (int i = 1; i < n; i++) {
        int digit = s[i] - '0';
        if (digit != 0)
            numberUpTo[i] = (numberUpTo[i - 1] * 10 + digit) % MOD;
        else
            numberUpTo[i] = numberUpTo[i - 1];
    }

    digitSumTo[0] = s[0] - '0';
    for (int i = 1; i < n; i++) {
        digitSumTo[i] = digitSumTo[i - 1] + (s[i] - '0');
    }

    int q = queries.size();
    vector<int> result(q);

    for (int i = 0; i < q; i++) {
        int l = queries[i][0];
        int r = queries[i][1];

        ll sum = digitSumTo[r] - (l == 0 ? 0 : digitSumTo[l - 1]);

        ll numBefore = (l == 0) ? 0 : numberUpTo[l - 1];

        int k = nonZeroCount[r] - (l == 0 ? 0 : nonZeroCount[l - 1]);

        ll x = (numberUpTo[r] - (numBefore * pow10[k]) % MOD + MOD) % MOD;

        result[i] = (x * sum) % MOD;
    }

    return result;
}

int main() {
    string s;
    cin >> s;

    int q;
    cin >> q;

    vector<vector<int>> queries(q, vector<int>(2));

    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1];
    }

    vector<int> ans = sumAndMultiply(s, queries);

    for (int x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}