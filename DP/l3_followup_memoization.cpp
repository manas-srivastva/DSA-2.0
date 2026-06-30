#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int f(int ind, vector<int>& h, vector<int>& dp, int k)
{
    if(ind == 0) return 0;

    if(dp[ind] != -1) return dp[ind];

    int ans = INT_MAX;

    for(int j = 1; j <= k; j++)
    {
        if(ind - j >= 0)
        {
            int jump = f(ind - j, h, dp, k)
                     + abs(h[ind] - h[ind - j]);

            ans = min(ans, jump);
        }
    }

    return dp[ind] = ans;
}

int frogJump(int n, int k, vector<int>& heights)
{
    vector<int> dp(n, -1);

    return f(n - 1, heights, dp, k);
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> heights(n);

    for(int i = 0; i < n; i++)
        cin >> heights[i];

    cout << frogJump(n, k, heights);
}