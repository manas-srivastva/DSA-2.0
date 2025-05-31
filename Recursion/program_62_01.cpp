#include<iostream>
#include<vector>
using namespace std;
bool find(int arr[], int index, int n, int sum) {
    if (index == n) {
        return sum == 0; // Check if the sum is zero
    }
    // Exclude the current element
    if (find(arr, index + 1, n, sum)) {
        return true;
    }
    // Include the current element
    if (find(arr, index + 1, n, sum - arr[index])) {
        return true;
    }
    return false; // If neither case returns true
}
int main(){
int arr[] = {1, 2, 3};
int n = sizeof(arr) / sizeof(arr[0]);
int sum = 5; // Change this to the desired sum you want to check
if (find(arr, 0, n, sum)) {
    cout << "Subset with sum " << sum << " exists." << endl;
} else {
    cout << "No subset with sum " << sum << " exists." << endl;
}
return 0;
}