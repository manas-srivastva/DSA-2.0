#include<iostream>
using namespace std;
int searchinRotatedSortedArrayy(int arr[],int n,int target){
    int start=0;
    int end=n-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==target){
            return mid;  // found the target
        }
        else if(arr[start]<=arr[mid]){
            if(target>=arr[start] && target<=arr[mid]){
                end=mid-1;  // move to the left side
            }
            else{
                start=mid+1;  // move to the right side
            }
        }
        else{
            if(target>=arr[mid] && target<=arr[end]){
                start=mid+1;  // move to the right side
            }
            else{
                end=mid-1;  // move to the left side
            }
        }
    }
    return -1;  // target not found
}
int main(){
int arr[]={4,5,6,7,0,1,2};
int n=7;
int target=0;
int ans=searchinRotatedSortedArrayy(arr,n,target);
if(ans==-1){
    cout<<"Target not found in the array";
}
else{
    cout<<"Target found at index: "<<ans;
}
return 0;
}