// #include<iostream>
// using namespace std;
// void columnmajor(int arr[][3],int row,int col){
//     for(int j=0;j<col;j++){
//         for(int i=0;i<row;i++){
//             cout<<arr[i][j]<<" ";
//         }
//     }
// }
// int main(){
// int arr[4][3]={1,2,3,4,5,6,7,8,9,10,11,12};
// int row=4;
// int col=3;
// columnmajor(arr,row,col);
// return 0;
// }



// Wave form in a 2D matrix

// #include<iostream>
// using namespace std;
// void WaveformMatrix(int arr[][4],int row,int col){
//     for(int j=0;j<col;j++){
//         if(j%2==0){
//             for(int i=0;i<row;i++){
//                 cout<<arr[i][j]<<" ";
//             }
//         }
//         else
//         for(int i=row-1;i>=0;i--){
//             cout<<arr[i][j]<<" ";
//         }
//     }
// }
// int main(){
// int arr[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
// int row=3;
// int col=4;
// WaveformMatrix(arr,row,col);
// return 0;
// }


//          TRANSPOSE OF A MATRIX WITH USING EXTRA SPACE
// #include<iostream>
// using namespace std;
// int main(){
// int arr[3][3]={1,2,3,4,5,6,7,8,9};
// int transpose[3][3];
// for(int i=0;i<3;i++)
// {
//     for(int j=0;j<3;j++){
//         transpose[i][j]=arr[j][i];
//     }
// }

// for(int i=0;i<3;i++){
//     cout<<endl;
//     for(int j=0;j<3;j++){
//       cout<<transpose[i][j]<<" ";
//     }
// }
// return 0;
// }




//    Transpose without using extra space
#include<iostream>
using namespace std;
int main(){
int arr[3][3]={1,2,3,4,5,6,7,8,9};

for(int i=0;i<2;i++)
{
    for(int j=i+1;j<3;j++){
        swap(arr[i][j],arr[j][i]);
    }
}

for(int i=0;i<3;i++){
    cout<<endl;
    for(int j=0;j<3;j++){
      cout<<arr[i][j]<<" ";
    }
}
return 0;
}