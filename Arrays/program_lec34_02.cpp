
// search in sorted row and col wise matrix
#include<iostream>
using namespace std;
int Binarysearhin2dArray(int arr[][3],int row,int col,int x){
    int i=0;
    int j=col-1;
    while(i<=row&&j>=0){
        if(arr[i][j]==x)
        return 1;
        else if(arr[i][j]<x)
        i++;
        else
        j--;
    }
    return 0;
}
int main(){
int arr[][3]={1,2,3,4,5,6,7,8,9};
int X=2;
int value=Binarysearhin2dArray(arr,3,3,X);
if(value==1)
cout<<"ELEMENT IS PRESENT";
else
cout<<"ELEMENT IS NOT FOUND";

return 0;
}