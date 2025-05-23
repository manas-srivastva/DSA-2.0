// #include<iostream>
// using namespace std;
// bool linearsearch(int arr[],int n,int index,int x){
//     if(index==n){
//         return 0;
//     }
//     if(arr[index]==x){
//         return 1;
//     }
//     return linearsearch(arr,n,index+1,x);
// }
// int main(){
// int arr[]={1,2,3,4,5};
// int n=5;
// int X=9;
// cout<<linearsearch(arr,n,0,X);
// return 0;
// } 


//                 Binary Search using recursion
#include<iostream>
using namespace std;
bool binarysearch(int arr[],int start,int end,int x)
{
    if(start>end){
        return 0;
    }
    int mid=start+(end-start)/2;
    if(arr[mid]==x){
        return 1;
    }
    else if(arr[mid]<x)
    return binarysearch(arr,mid+1,end,x);
    else
    return binarysearch(arr,start,mid-1,x);
    }

int main(){
int arr[]={1,2,3,4,5};
int n=5;
int x=8;
bool ans=binarysearch(arr,0,n-1,x);
if(ans){
    cout<<"Element found";
}
else{
    cout<<"Element not found";
}
return 0;
}