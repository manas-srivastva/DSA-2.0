// #include<iostream>
// using namespace std;
// int searchInsertPosisition(int arr[],int n,int target){
//     int start=0,end=n-1,mid;
//     while(start<=end){
//         mid=start+(end-start)/2;
//         if(arr[mid]==target){
//             return mid;
//             break;
//         }
//         else if(arr[mid]<target){
//             start=mid+1;
//         }
//         else{
//             end=mid-1;
//         }
//     }
// }
// int main(){
// int arr[]={1,2,3,4,6};
// int n=5;
// int target=5;
// int ans=searchInsertPosisition(arr,n,target);
// cout<<ans;
// return 0;
// }



#include<iostream>
using namespace std;
int mySqrt(int x){
    if(x<2){
        return x;
    }
    int start=0,end=x,mid,ans;
    while(start<=end){
        mid=start+(end-start)/2;
        if(mid==x/mid){
            return mid;
        }
        else if(mid<x/mid){
            ans=mid;
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
}
int main(){
int arr[]={1,2,3,4,5,6,7,8,10,11,12,13,14,15,16,17,18,19,20};
int n=19;
int target=100;

int ans=mySqrt(target);
cout<<ans;
return 0;
}