#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arrayRankTransform(vector<int>& arr) {
    vector<int> temp = arr;
    sort(temp.begin(), temp.end());

    // Remove duplicate elements to establish unique ranks
    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    vector<int> ans;

    for (int x : arr) {
        // Binary search to find the 1-based index rank
        int rank = lower_bound(temp.begin(), temp.end(), x) - temp.begin() + 1;
        ans.push_back(rank);
    }
    
    return ans;
}

int main() {
    // Example test case
    vector<int> arr = {40, 10, 20, 30, 10};
    
    vector<int> rankedArr = arrayRankTransform(arr);
    
    // Print the results
    cout << "Original: ";
    for (int x : arr) cout << x << " ";
    cout << "\nRanked:   ";
    for (int x : rankedArr) cout << x << " ";
    cout << endl;

    return 0;
}