               // print array elements using recursion
// #include<iostream>
// using namespace std;
// void print(int arr[],int index,int n){
//     if(index==n){
//         return;
//     }
//     cout<<arr[index]<<" ";
//     print(arr,index+1,n);
// }
// int main(){
// int arr[5]={1,2,3,4,5};
// int n=5;
// print(arr,0,n);
// return 0;
// }


// to print it in reverse order
// #include<iostream>
// using namespace std;
// void print(int arr[],int index,int n){
//     if(index==n){
//         return;
//     }
    
//     print(arr,index+1,n);
//     cout<<arr[index]<<" ";
// }
// int main(){
// int arr[5]={1,2,3,4,5};
// int n=5;
// print(arr,0,n);
// return 0;
// }


//            sum of array elements using recursion
// #include<iostream>
// using namespace std;
// int sum(int arr[],int index,int n){
//     if(index==n){
//         return 0;
//     }
//     return arr[index]+sum(arr,index+1,n);
// }
// int main(){
// int arr[5]={1,2,3,4,5};
// int n=5;
// int result=sum(arr,0,n);
// cout<<result;
// return 0;
// }


//       MININUM ELEMENTS IN AN ARRAY
#include<iostream>
using namespace std;
int minelement(int arr[],int index, int n){
    if(index==n-1){
        return arr[index];
    }
    return min(arr[index],minelement(arr,index+1,n));
}
int main(){
int arr[]={1,2,3,4,5};
int n=5;
int result=minelement(arr,0,n);
cout<<result;
return 0;
}