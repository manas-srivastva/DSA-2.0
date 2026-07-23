#include <iostream>
#include <vector>
using namespace std;

int uniqueXorTriplets(vector<int>& nums) {
    int n = nums.size();

    if (n == 1 || n == 2)
        return n;

    int ans = 1;
    while (ans <= n) {
        ans *= 2;
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << uniqueXorTriplets(nums) << endl;

    return 0;
}