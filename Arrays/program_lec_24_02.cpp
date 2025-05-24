#include<iostream>
using namespace std;
int findmininRotatedArray(int arr[],int n){
    int start=0;
    int end=n-1;
    int ans=arr[0];
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]>arr[0]){
            start=mid+1; // move to the right side (left side sorted array)
        }
        else
        {
            ans=arr[mid];
            end=mid-1; // move to the left side (right side sorted array)
        }
    }
    return ans;
}
int main(){
int arr[]={4,5,6,7,0,1,2};
int n=7;
int ans=findmininRotatedArray(arr,n);
cout<<ans;  // output the minimum element in the rotated sorted array
return 0;
}