// #include<iostream>
// using namespace std;
// int BinarySeach(int arr[],int n,int key){
//     int start=0;
//     int end=n-1;
//     int mid;

//     while(start<=end){
//         mid=start+(end-start)/2;
//         if(arr[mid]==key){
//             return mid;
//         }
//         else if(arr[mid]<key){
//             start=mid+1;
//         }
//         else{
//             end=mid-1;
//         }   
//     }
//     return -1;
// }
// int main(){
// int arr[]={1,2,3,4,5};
// int n=5;
// int key=8;
// int ans=BinarySeach(arr,n,key);
// if(ans==-1){
//     cout<<"Element not found";
// }
// else{
//     cout<<ans;
// }
// return 0;
//}







// for array in descending order



#include<iostream>
using namespace std;
int BinarySeach(int arr[],int n,int key){
    int start=0;
    int end=n-1;
    int mid;

    while(start<=end){
        mid=start+(end-start)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            end=mid-1;
        }
        else{
            start=mid+1;
        }   
    }
    return -1;
}
int main(){
int arr[]={5,4,3,2,1};
int n=5;
int key=4;
int ans=BinarySeach(arr,n,key);
if(ans==-1){
    cout<<"Element not found";
}
else{
    cout<<ans;
}
return 0;
}