#include<iostream>
using namespace std;
int kadanealgorithm(int arr[],int n){
    int maxi=-200;
    int prefix=0;
    for(int i=0;i<n;i++){
        prefix+=arr[i];
        maxi=max(maxi,prefix);
        if(prefix<0)
        prefix =0;
    }
    return maxi;
}
int main(){
int arr[]={2,4,-8,2,3,4};
int n=6;
cout<<kadanealgorithm(arr,n);
return 0;
}