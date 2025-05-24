
                 // BRUTE FORCE APPROACH

// #include<iostream>
// using namespace std;
// int peakindex(int arr[],int n){
//     int index=0;
//     for(int i=0;i<n;i++){
//         if(arr[i]<arr[i+1]){
//             index++;
//         }
//         else{
//             return index;
//         }
//     }
   
// }
// int main(){
// int arr[]={1,3,4,6,7,3,1};
// int n=7;
// int index=peakindex(arr,n);
// cout<<index;
// return 0;
// }


               // BINARY SEARCH APPROAch
#include<iostream>
using namespace std;
int peakIndex(int arr[],int n){
    int start=0;
    int end=n-1;
    while(start<=end){
    int mid=end+(start-end)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
            return mid;  // founded the peak index
        }
        else if(arr[mid]<arr[mid+1]){
            start=mid+1;  // move to the right side
        }
        else{
            end=mid-1;  // move to the left side
        }
    }
}
int main(){
int arr[]={1,3,4,6,7,3,1};
int n=7;
int index=peakIndex(arr,n);
cout<<index;  // output the peak index
return 0;
}