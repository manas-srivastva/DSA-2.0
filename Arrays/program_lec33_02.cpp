// brute force is that execute 90 degree code twice

// #include<iostream>
// using namespace std;
//  void rotate(int arr[][4],int row,int col){
//     // transpose
//     for(int i=0;i<row-1;i++)
//     {
//         for(int j=i+1;j<col;j++){
//             swap(arr[i][j],arr[j][i]);
//         }
//     }
//     // reverse each row
//     for(int i=0;i<row;i++){
//         int start=0;
//         int end=col-1;
//         while(start<end){
//             swap(arr[i][start],arr[i][end]);
//             start++,end--;
//         }
//     }
  
//         // transpose
//     for(int i=0;i<row-1;i++)
//     {
//         for(int j=i+1;j<col;j++){
//             swap(arr[i][j],arr[j][i]);
//         }
//     }
//     // reverse each row
//     for(int i=0;i<row;i++){
//         int start=0;
//         int end=col-1;
//         while(start<end){
//             swap(arr[i][start],arr[i][end]);
//             start++,end--;
//         }
//     }
//     for(int i=0;i<row;i++){
//         cout<<endl;
//         for(int j=0;j<col;j++){
//             cout<<arr[i][j]<<" ";
//         }
//     }
//  }
// int main(){
// int arr[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
// rotate(arr,4,4);
// return 0;
// }






#include<iostream>
using namespace std;
void rotate180(int arr[][4],int row,int col){
    // row wise reverse
    for(int i=0;i<row;i++){
        int start=0;
        int end=col-1;
        while(start<end){
            swap(arr[i][start],arr[i][end]);
            start++,end--;
        }
    }
    // column wise reverse
    for(int j=0;j<col;j++){
        int start=0,end=row-1;
        while(start<end){
            swap(arr[start][j],arr[end][j]);
            start++,end--;
        }
    }
    for(int i=0;i<row;i++){
        cout<<endl;
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
    }
}
int main(){
int arr[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
rotate180(arr,4,4);
return 0;
}