#include<iostream>
using namespace std;
int findpages(int A[],int N,int M){
    if(M>N)
    return -1;

    int start=0,end=0,mid,ans;
    for(int i=0;i<N;i++){
        start=max(start,A[i]);
        end+=A[i];
    }
    while(start<=end){
        mid=start+(end-start)/2;
        int pages=0;
        int count=1;
        for(int i=0;i<N;i++){
            pages+=A[i];
            if(pages>mid){
                count++;
                pages=A[i];
            }
        }
        if(count<=M){
            ans=mid;
            end=mid-1;
        }
        else
        start=mid+1;
    }
    return ans;
}
int main(){
int arr[]={12,34,67,90};
int n=4;
int m=2;
int pages=findpages(arr,n,m);
cout<<pages;
return 0;
}

// same concept fo painter partition and ship package