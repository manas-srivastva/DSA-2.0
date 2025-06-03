#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 bool hasTripletSum(vector<int> &arr, int target) {
        // Your Code Here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int start,end,ans;
        for(int i=0;i<n-2;i++){
            ans=target-arr[i];
            start=i+1,end=n-1;
            while(start<end){
                if(arr[start]+arr[end]==ans)
                return 1;
                
                else if(arr[start]+arr[end]>ans)
                end--;
                else
                start++;
                }
        }
        return 0;
    }
int main(){
// 1, 4, 45, 6, 10, 8
vector<int>arr;
arr.push_back(1);
arr.push_back(4);
arr.push_back(45);
arr.push_back(6);
arr.push_back(10);
arr.push_back(8);
int X=13;
cout<<hasTripletSum(arr,X);
return 0;
}



// approach 2
// binary search

// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// vector<int> Possibility(vector<int>& arr, int target) {
//     int n = arr.size();
//     sort(arr.begin(), arr.end());
//     for (int i = 0; i < n - 2; i++) {
//         for (int j = i + 1; j < n - 1; j++) {
//             int start = j + 1, end = n - 1, mid;  // Corrected the 'end' value
//             while (start <= end) {
//                 mid = start + (end - start) / 2;
//                 if (arr[mid] == target - arr[i] - arr[j]) {
//                     int answer[3] = {arr[i], arr[j], arr[mid]};
//                     vector<int> t(answer, answer + 3);
//                     return t;
//                 } else if (arr[mid] < target - arr[i] - arr[j]) {
//                     start=mid+1;
//                 } else {
//                     end=mid-1;;
//                 }
//             }
//         }
//     }
//     return {};  // Return an empty vector if no valid combination is found
// }

// int main() {
//     int arr[1000] = {1, 4, 45, 6, 10, 8};
//     vector<int> v(arr, arr + 6);
//     int target;
//     cout << "Enter target value: ";
//     cin >> target;
//     vector<int> result = Possibility(v, target);

//     if (result.empty()) {
//         cout << "No combination found." << endl;
//     } else {
//         cout << "Indices: ";
//         for (int i : result) {
//             cout << i << ", ";
//         }
//         cout << endl;
//     }
// return 0;
// }