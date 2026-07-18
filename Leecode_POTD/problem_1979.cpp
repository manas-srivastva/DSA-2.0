#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>

using namespace std;

int findGCD(vector<int>& nums) {
    int mn = INT_MAX;
    int mx = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > mx)
            mx = nums[i];
    }

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] < mn)
            mn = nums[i];
    }

    int GCD = gcd(mn, mx);

    return GCD;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << findGCD(nums) << endl;

    return 0;
}