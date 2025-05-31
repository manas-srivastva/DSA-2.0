#include<iostream>
using namespace std;
int targetsumrepeat(int arr[],int index,int sum,int n){
    if(sum==0){
        return 1; // Found a subset with the target sum
    }
    if(index==n || sum<0){
        return 0; // No valid subset found or sum is negative
    }
    return targetsumrepeat(arr, index, sum - arr[index], n) + targetsumrepeat(arr, index + 1, sum, n);
}
int main(){
int arr[] = {1, 2, 3,3,3};
int n = sizeof(arr) / sizeof(arr[0]);
int sum = 9; // Change this to the desired target sum
int result = targetsumrepeat(arr, 0, sum, n);
if (result > 0) {
    cout << "Subset with sum " << sum << " exists." << endl;
} else {
    cout << "No subset with sum " << sum << " exists." << endl;
}
return 0;
}