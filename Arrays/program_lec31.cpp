// #include<iostream>
// using namespace std;
// void printrowmax(int arr[][4],int row,int col){
//     int index=-1;
//     int sum=0;
//      for(int i=0;i<row;i++){
//         int total=0;
//         for(int j=0;j<col;j++){
//             total+=arr[i][j];
//         }
//         if(total>sum){
//             sum=total;
//             index=i;
//         }
//      }
//      cout<<index<<" ";
// }
// int main(){
// int arr[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
// int row=3;
// int col=4;
// printrowmax(arr,row,col); 
// return 0;
// }


//          print the sum of earch diagonal
// #include<iostream>
// using namespace std;
// void printsumofdiag(int arr[][3],int row,int col){
//     int sum1=0,sum2=0;
//     for(int i=0;i<row;i++){
//         for(int j=0;j<col;j++)
//         {
//             if(i==j)
//             sum1+=arr[i][i];
//         }
        
//     }

//     for(int i=0;i<row;i++){
//         for(int j=0;j<col;j++){
//             if((i+j)==2){
//                 sum2+=arr[i][j];
//             }
//         }
//     }
//     cout<<"The sum of first Diagonal is "<<" "<<sum1<<endl;
//     cout<<"The sum of second Diagonal is "<<" "<<sum2<<endl;

// }
// int main(){
// int arr[3][3]={1,2,3,4,5,6,7,8,9};
// int row=3;
// int col=3;
// printsumofdiag(arr,row,col);
// return 0;
// }


//                  Reverse Each row of the matrix
#include<iostream>
using namespace std;
void reverseofeachrow(int arr[][3],int row,int col){
    for(int i=0;i<row;i++){
        int start=0;
        int end=col-1;
        while(start<end){
            swap(arr[i][start],arr[i][end]);
            start++;end--;
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
int row=3;
int col=3;
reverseofeachrow(arr,row,col);
return 0;
}