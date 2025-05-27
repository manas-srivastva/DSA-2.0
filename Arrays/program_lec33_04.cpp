// rotated the array k times

#include<iostream>
using namespace std;
void rotate(int arr[][3],int row,int col){
    // transpose
    for(int i=0;i<row-1;i++)
    {
        for(int j=i+1;j<col;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
    // reverse each row
    for(int i=0;i<row;i++){
        int start=0;
        int end=col-1;
        while(start<end){
            swap(arr[i][start],arr[i][end]);
            start++,end--;
        }
    }
    
 }
int main(){
int k;
cin>>k;
k=k%4;
int arr[3][3]={1,2,3,4,5,6,7,8,9};
while(k!=0){


rotate(arr,3,3);
k--;
}
for(int i=0;i<3;i++){
        cout<<endl;
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<" ";
        }
    }
return 0;
}