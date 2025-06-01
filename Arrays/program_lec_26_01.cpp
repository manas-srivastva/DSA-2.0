
     //   Approach 1 TIME COMPLEXITY O(N*N)

// #include<iostream>
// #include<vector>
// using namespace std;
// bool dividearrayin2subarray(int arr[],int n){
//     for(int i=0;i<n-1;i++){
//         int sum1=0;
//         int sum2=0;
//         for(int j=0;j<=i;j++){
//             sum1+=arr[j];
//         }
//         for(int j=i+1;j<n;j++){
//             sum2+=arr[j];
//         }
//         if(sum1==sum2){
//             return 1;
//         }
//     }
//     return 0;
// }
// int main(){
// int arr[]={3,4,-2,5,8,20,-10,8};
// int n=8;
// cout<<dividearrayin2subarray(arr,8);
// return 0;
// }




//               Approach 2  O(N)

#include<iostream>
using namespace std;
bool dividearrayin2subarray(int arr[],int n){
    int totalsum=0;
    int ans;
    for(int i=0;i<n;i++){
        totalsum+=arr[i];
    }
 int prefix=0;
 for(int i=0;i<n;i++){
    prefix+=arr[i];
    ans=totalsum-prefix;
     if(ans==prefix){
    return 1;
 }
 }

 return 0;
}
int main(){
 int arr[]={3,4,-2,5,8,20,-10,8};
 int n=8;
 cout<<dividearrayin2subarray(arr,8);
return 0;
}