#include<iostream>
#include<vector>
using namespace std;
int perfecrsumsubset(int arr[],int index,int sum,int n){
   if(index==n){
    if(sum==0)
    return 1;
    else
    return 0;
   }
    return perfecrsumsubset(arr,index+1,sum,n) + perfecrsumsubset(arr,index+1,sum-arr[index],n);
}
int main(){
int arr[]={1,2,3};
int n=sizeof(arr)/sizeof(arr[0]);   
int sum=3; // Change this to the desired sum you want to check
int result = perfecrsumsubset(arr, 0, sum, n);
if (result > 0) {
    cout << "Subset with sum " << sum << " exists." << endl;
} else {
    cout << "No subset with sum " << sum << " exists." << endl;
}
return 0;
}