#include<iostream>
using namespace std;
int searchfirstandlastoccurence(int arr[],int n,int target){
    int start=0;
    int end=n-1;
    int first=-1;
    int last=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==target){
            first=mid;
            end=mid-1;
        }
        else if(arr[mid]<target){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    start=0;
    end=n-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==target){
            last=mid;
            start=mid+1;
        }
        else if(arr[mid]<target){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    int arr1[2];
    arr1[0]=first;
    arr1[1]=last;
}
int main(){
    int arr[]= {1,2,3,4,5,5,5,5};
    int n=8;
    int target=5;
    int arr1[2];
   arr1[2] =searchfirstandlastoccurence(arr,n,target);
    cout<<arr1[0]<<" "<<arr1[1];
return 0;
}