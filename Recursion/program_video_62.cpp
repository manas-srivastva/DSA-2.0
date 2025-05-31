#include<iostream>
#include<vector>
using namespace std;
void print(int arr[],int index,int n,int sum){
    if(index==n){
        cout<<sum<<endl;
        return;
    }
    // No  
    print(arr,index+1,n,sum);
    // YES
    print(arr,index+1,n,sum+arr[index]);
}
int main(){
int arr[]={1,2,3};
int n=sizeof(arr)/sizeof(arr[0]);
print(arr,0,n,0);
// The output will be the sum of all subsequences
// For the array {1, 2, 3}, the output will be:
// 0
return 0;
}