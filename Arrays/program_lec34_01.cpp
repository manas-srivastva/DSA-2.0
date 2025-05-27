#include<iostream>
using namespace std;
int Binarysearchin2DArray(int arr[][3],int row,int col,int X){
    for(int i=0;i<row;i++){
        if(arr[i][0]<=X && X<=arr[i][col-1]){
            int start=0,end=col-1;
            while(start<=end){
                int mid=(start+end)/2;
                if(arr[i][mid]==X){
                    return 1;
                }
                else if(arr[i][mid]<X){
                    start=mid+1;
                }
                else
                end=mid-1;
            }
        }
        return 0;
    }
   
}
int main(){
int arr[][3]={1,2,3,4,5,6,7,8,9};
int X=2;
int value=Binarysearchin2DArray(arr,3,3,X);
if(value==1)
cout<<"ELEMENT IS PRESENT";
else
cout<<"ELEMENT IS NOT FOUND";
return 0;
}