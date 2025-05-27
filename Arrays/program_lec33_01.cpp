//       rotate 2d array by 90degree clockwise without extra space


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
    for(int i=0;i<row;i++){
        cout<<endl;
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
    }
 }
int main(){
int arr[3][3]={1,2,3,4,5,6,7,8,9};
rotate(arr,3,3);
return 0;
}
//      with extra array space
// #include<iostream>
// using namespace std;

// int main(){
//     int ans[3][3];
//  int arr[3][3]={1,2,3,4,5,6,7,8,9};
//  for(int i=0;i<3;i++){
//     for(int j=0;j<3;j++){
//      ans[j][2-i]=arr[i][j];
//     }
//  }

//  for(int i=0;i<3;i++){
//     cout<<endl;
//     for(int j=0;j<3;j++){
//         cout<<ans[i][j]<<" ";
//     }
//  }
// return 0;
// }