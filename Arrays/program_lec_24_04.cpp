#include<iostream>
#include<vector>
using namespace std;
int Kthpositiveinteger(vector<int>&arr,int k){
int left=0;
int right=arr.size()-1;
while(left<=right){
    int mid=left+(right-left)/2;
    int missingCount=arr[mid]-(mid+1); // count of missing positive integers up to arr[mid]
    
    if(missingCount>=k){
        right=mid-1; // move to the left side
        
    }
    else{
        left=mid+1; // move to the right side
    }
     
}
return left+k; // return the k-th positive integer
}
int main(){
vector<int>arr={1,2,3,4};
int k=2;
int ans=Kthpositiveinteger(arr,k);
cout<<ans; // output the k-th positive integer
return 0;
}




//                    BRUTE FORCE APPROACH
// #include<iostream>
// using namespace std;
// int KthmissingInteger(int arr[],int n,int k){
//     for(int i=0;i<n-1;i++){
//         if(arr[i]<=k){
//             k++; // increment k if the current element is greater than k
//         }
//         else
//         break;
//     }
//     return k; // return the k-th missing positive integer
// }
// int main(){
// int arr[]={2,3,4,7,11};
// int n=5;
// int k=5;
// int ans=KthmissingInteger(arr,n,k);
// cout<<ans; // output the k-th missing positive integer
// return 0;
// }