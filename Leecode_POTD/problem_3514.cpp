
//                                              METHOD-1(WITHOUT USING SETS)

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int uniqueXorTriplets(vector<int>& nums) {
//     int n = nums.size();
//     int maxEl = *max_element(nums.begin(), nums.end());

//     int T = 1;
//     while (T <= maxEl) {
//         T <<= 1;  // T = T * 2
//     }

//     vector<bool> s1(T, false); // XOR pair values
//     vector<bool> s2(T, false); // XOR triplet values

//     for (int i = 0; i < n; i++) {
//         for (int j = i; j < n; j++) {
//             s1[nums[i] ^ nums[j]] = true;
//         }
//     }

//     for (int i = 0; i < T; i++) {
//         if (s1[i]) {
//             for (int num : nums) {
//                 s2[i ^ num] = true;
//             }
//         }
//     }

//     int count = 0;
//     for (int i = 0; i < T; i++) {
//         if (s2[i])
//             count++;
//     }

//     return count;
// }

// int main() {
//     int n;
//     cin >> n;

//     vector<int> nums(n);
//     for (int i = 0; i < n; i++) {
//         cin >> nums[i];
//     }

//     cout << uniqueXorTriplets(nums) << endl;

//     return 0;
// }


//                                                 METHOD-2(WITH SETS)
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int uniqueXorTriplets(vector<int>& nums) {
    int n = nums.size();

    // Store all pair XORs
    unordered_set<int> s1;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            s1.insert(nums[i] ^ nums[j]);
        }
    }

    // Find all triplet XORs
    unordered_set<int> s2;
    for (int pairXor : s1) {
        for (int num : nums) {
            s2.insert(pairXor ^ num);
        }
    }

    return s2.size();
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