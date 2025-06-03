#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool find4Numbers(int A[], int n, int X) {
    sort(A,A+n);
    int ans;
    for(int j=0;j<n-3;j++){
     
        for(int i=j+1;i<n-2;i++){
            ans=X-A[j]-A[i];
          int start=i+1,end=n-1;
            while(start<end){
                if(A[start]+A[end]==ans)
                return 1;
                
                else if(A[start]+A[end]>ans)
                end--;
                else
                start++;
                }
        }
    }
        return 0;
}
int main(){
int arr[]={1,5,1,0,6,0};
int n=6;
int X=7;
cout<<find4Numbers(arr,n,X);
return 0;
}